from enums import *
from preprocess import *
from postprocess import *
import shlex


class VM:
    def __init__(self):
        self.sp = 8192
        self.lcl = 8196
        self.arg = 8200
        self.tmp = 8204
        self.this = 8208
        self.that = 8212
        # 8216 and 8220 for later use
        # start from 8224
        self.text_segment = ".section\n.text\n.global main\njal x30, main\n"
        self.prev_operator = None
        self.prev_datatype = None
        self.prev_push_segment = None
        self.label_index = 0
        self.return_type = 'INT'
        self.num_local = 0
        self.num_temp = 0
        self.cur_function = "global"
        self.prev_push_datatype = None
        self.data_segment_start = 0x10010000
        self.data_segment_dict = {}
        self.data_segment = ".section\n.data\n"

    def init_mem(self):
        # 8224 to 8735 (512, local)
        self.text_segment += f"li x5, -8224\n"
        self.text_segment += f"li x6, -{self.lcl}\n"
        self.text_segment += f"add x6, x8, x6\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        # 8736 to 8767 (32, argument)
        self.text_segment += f"li x5, -8736\n"
        self.text_segment += f"li x6, -{self.arg}\n"
        self.text_segment += f"add x6, x8, x6\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        # 8768 to 9279 (512, temp)
        self.text_segment += f"li x5, -8768\n"
        self.text_segment += f"li x6, -{self.tmp}\n"
        self.text_segment += f"add x6, x8, x6\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        # 9280 to 10303 (1024, stack)
        self.text_segment += f"li x5, -9280\n"
        self.text_segment += f"li x6, -{self.sp}\n"
        self.text_segment += f"add x6, x8, x6\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        self.text_segment += f"li x2, -9280\n"
        self.text_segment += f"add x2, x2, x8\n\n"

    def label(self, line):
        """
        label L1
        """
        self.text_segment += f"{line[-1]}:\n"

    def get_new_label(self):
        label = '___CL'+str(self.label_index)
        self.label_index += 1
        return label

    def goto(self, line):
        """
        goto L0
        """
        self.text_segment += f"jal x30, {line[-1]}\n"

    def push(self, line):
        """
        push local 4 INT
        push constant -5.6 FLOAT
        push constant 'c' CHAR
        push constant true BOOL
        """
        segment = line[1]
        self.prev_push_segment = segment
        datatype = line[-1]
        index = 0
        self.prev_push_datatype = datatype

        if (segment != Segment.constant.value):
            index = int(line[2])
        else:
            if (datatype == Datatypes.INT.value or datatype == Datatypes.BOOL.value):
                index = int(line[2])
            elif (datatype == Datatypes.CHAR.value):
                if (segment == Segment.constant.value):
                    index = ord(line[2])
                else:
                    index = int(line[2])
            elif (datatype == Datatypes.FLOAT.value):
                index = float(line[2])
            elif (datatype == Datatypes.STR.value):
                index = int(line[2])

        if (segment == Segment.data.value):
            if (len(line) == 5):
                string_val = '"'+line[-2]+'"'
                var = f"__{self.cur_function}__data{index}"
                string_val = string_val[1:-1].replace(
                    "\\/", "/").encode().decode('unicode_escape')
                length = len(string_val)
                self.data_segment_dict[var] = [
                    ".asciz", line[-2], self.data_segment_start, length]
                self.data_segment_start += length+1
            else:
                # perform printing here itself
                var_name = f"__{self.cur_function}__data{index}"
                total = hex(self.data_segment_dict[var_name][2])[2:]
                upper, mid, lower = get_ieee_rep(None, total)

                self.text_segment += f"lui a0, {upper}\n"
                self.text_segment += f"addi a0, a0, {mid}\n"
                self.text_segment += f"addi a0, a0, {lower}\n"
                self.text_segment += "addi a7, x0, 4\necall\n"

        elif (segment != Segment.constant.value and segment != Segment.that.value):
            pointer = None
            if (segment == Segment.local.value):
                pointer = self.lcl
            elif (segment == Segment.temp.value):
                pointer = self.tmp
            elif (segment == Segment.argument.value):
                pointer = self.arg

            if (datatype == Datatypes.INT.value):
                # self.text_segment += f"lw x5, {-(pointer)}(x8)\n"

                self.text_segment += f"li x5, {-(pointer)}\n"
                self.text_segment += f"add x5, x5, x8\n"
                self.text_segment += f"lw x5, 0(x5)\n"

                self.text_segment += f"addi x5, x5, {-(index*4+4)}\n"
                self.text_segment += f"lw x5, 0(x5)\n"
                self.text_segment += f"sw x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif (datatype == Datatypes.CHAR.value or datatype == Datatypes.BOOL.value):
                # self.text_segment += f"lw x5, {-(pointer)}(x8)\n"
                self.text_segment += f"li x5, {-(pointer)}\n"
                self.text_segment += f"add x5, x5, x8\n"
                self.text_segment += f"lw x5, 0(x5)\n"

                self.text_segment += f"addi x5, x5, {-(index*4+4)}\n"
                self.text_segment += f"lb x5, 0(x5)\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif (datatype == Datatypes.FLOAT.value):
                # self.text_segment += f"lw x5, {-(pointer)}(x8)\n"
                self.text_segment += f"li x5, {-(pointer)}\n"
                self.text_segment += f"add x5, x5, x8\n"
                self.text_segment += f"lw x5, 0(x5)\n"

                self.text_segment += f"addi x5, x5, {-(int(index)*4+4)}\n"
                self.text_segment += f"flw f3, 0(x5)\n"
                self.text_segment += f"fsw f3, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"

            # self.text_segment += "\n"

        elif (segment == Segment.constant.value):
            constant = index
            if (datatype == Datatypes.INT.value):
                self.text_segment += f"li x5, {constant}\n"
                self.text_segment += f"sw x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif (datatype == Datatypes.CHAR.value):
                self.text_segment += f"li x5, {constant}\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif (datatype == Datatypes.BOOL.value):
                self.text_segment += f"li x5, {1 if line[2]=='true' else 0}\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif (datatype == Datatypes.FLOAT.value):
                self.text_segment += f"fli f3, {constant}\n"
                self.text_segment += f"fsw f3, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"

            # self.text_segment += "\n"
        else:
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"
            self.text_segment += f"li x6, -{self.lcl}\n"
            self.text_segment += f"lw x6, 0(x6)\n"
            self.text_segment += f"sub x6, x6, x5\n"
            self.text_segment += f"lw x7, 0(x6)\n"
            self.text_segment += f"sw x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"

        # self.text_segment += "\n"

    def pop(self, line):
        """
        pop local 4 INT
        pop temp 0 CHAR
        """
        segment = line[1]
        datatype = line[-1]
        index = int(line[2])

        pointer = None
        if (segment == Segment.local.value):
            pointer = self.lcl
        elif (segment == Segment.temp.value):
            pointer = self.tmp
        elif (segment == Segment.argument.value):
            pointer = self.arg

        if (segment == Segment.that.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"
            self.text_segment += f"li x7, -{self.lcl}\n"
            self.text_segment += f"lw x7, 0(x7)\n"
            self.text_segment += f"sub x7, x7, x5\n"
            self.text_segment += f"sw x6, 0(x7)\n"

            self.text_segment += '\n'
            return

        if (datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"

            if (self.prev_push_datatype == Datatypes.FLOAT.value):
                self.text_segment += f"flw f3, 0(x2)\n"
                self.text_segment += f"fcvt.w.s x5, f3\n"
            else:
                self.text_segment += f"lw x5, 0(x2)\n"

            # self.text_segment += f"lw x6, {-(pointer)}(x8)\n"

            self.text_segment += f"li x6, {-pointer}\n"
            self.text_segment += f"add x6, x6, x8\n"
            self.text_segment += f"lw x6, 0(x6)\n"

            self.text_segment += f"addi x6, x6, {-(index*4+4)}\n"
            self.text_segment += f"sw x5, 0(x6)\n"
        elif (datatype == Datatypes.CHAR.value or datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            if (self.prev_push_datatype == Datatypes.FLOAT.value):
                self.text_segment += f"flw f3, 0(x2)\n"
                self.text_segment += f"fcvt.w.s x5, f3\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"lb x5, 0(x2)\n"
            else:
                self.text_segment += f"lb x5, 0(x2)\n"

            # self.text_segment += f"lw x6, {-(pointer)}(x8)\n"
            self.text_segment += f"li x6, {-pointer}\n"
            self.text_segment += f"add x6, x6, x8\n"
            self.text_segment += f"lw x6, 0(x6)\n"

            self.text_segment += f"addi x6, x6, {-(index*4+4)}\n"
            self.text_segment += f"sb x5, 0(x6)\n"
        elif (datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            if (self.prev_push_datatype == Datatypes.INT.value):
                self.text_segment += f"lw x5, 0(x2)\n"
                self.text_segment += f"fcvt.s.w f3, x5\n"
            elif (self.prev_push_datatype == Datatypes.CHAR.value or self.prev_push_datatype == Datatypes.BOOL.value):
                self.text_segment += f"lb x5, 0(x2)\n"
                self.text_segment += f"fcvt.s.w f3, x5\n"
            else:
                self.text_segment += f"flw f3, 0(x2)\n"
            # self.text_segment += f"lw x6, {-(pointer)}(x8)\n"
            self.text_segment += f"li x6, {-pointer}\n"
            self.text_segment += f"add x6, x6, x8\n"
            self.text_segment += f"lw x6, 0(x6)\n"

            self.text_segment += f"addi x6, x6, {-(index*4+4)}\n"
            self.text_segment += f"fsw f3, 0(x6)\n"

        self.prev_push_datatype = None
        self.text_segment += '\n'

    def Operator(self, line):
        """
        Add/Sub/LShift/RShift/BitAnd/BitOr/BitXor INT
        Add/Sub FLOAT
        """
        datatype = line[-1]
        operator = line[0]
        instruction = ''
        if (operator == Instructions.Add.value):
            instruction = Operators.Add.value
        elif (operator == Instructions.Sub.value):
            instruction = Operators.Sub.value
        elif (operator == Instructions.LShift.value):
            instruction = Operators.LShift.value
        elif (operator == Instructions.RShift.value):
            instruction = Operators.RShift.value
        elif (operator == Instructions.BitAnd.value):
            instruction = Operators.BitAnd.value
        elif (operator == Instructions.BitOr.value):
            instruction = Operators.BitOr.value
        elif (operator == Instructions.BitXor.value):
            instruction = Operators.BitXor.value

        if (datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"
            self.text_segment += f"{instruction[0]} x5, x6, x5\n"
            self.text_segment += f"sw x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
        elif (datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"
            self.text_segment += f"{instruction[0]} x5, x6, x5\n"
            self.text_segment += f"sb x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
        elif (datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"
            self.text_segment += f"{instruction[0]} x5, x6, x5\n"
            self.text_segment += f"sb x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
        elif (datatype == Datatypes.FLOAT.value):
            if (operator == Instructions.Add.value or operator == Instructions.Sub.value):
                self.text_segment += f"addi x2, x2, 4\n"
                self.text_segment += f"flw f3, 0(x2)\n"
                self.text_segment += f"addi x2, x2, 4\n"
                self.text_segment += f"flw f4, 0(x2)\n"
                self.text_segment += f"{instruction[1]} f3, f4, f3\n"
                self.text_segment += f"fsw f3, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            # float does not have any other operations

        self.text_segment += '\n'

    def Condtion_builtin(self, line):
        """
        Eq INT
        if (x5 == x6){
            push 1 on top of stack
        }
        else{
            push 0 on top of stack
        }
        Lt INT
        """
        datatype = line[-1]
        condition = line[0]
        branch = 'eq'

        if (condition == Instructions.Eq.value):
            condition = Operators.Eq
            branch = Operators.Eq.value
        elif (condition == Instructions.Lt.value):
            condition = Operators.Lt
            branch = Operators.Lt.value
        elif (condition == Instructions.Ge.value):
            condition = Operators.Ge
            branch = Operators.Ge.value

        self.prev_operator = condition

        label1 = self.get_new_label()
        label2 = self.get_new_label()

        if (datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"      # RHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"      # LHS

            self.text_segment += f"{branch[0]} x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sw x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.INT
        elif (datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"{branch[0]} x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.CHAR
        elif (datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"{branch[0]} x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"add x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.BOOL
        # (need to check this conversion properly)
        elif (datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f4, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f3, 0(x2)\n"      # RHS

            # self.text_segment += f"{branch[1]} f3, f4, {label1}\n"
            self.text_segment += f"{branch[1]} x28, f3, f4\n"
            self.text_segment += f"bne x28, x0, {label1}\n"

            self.text_segment += f"fadd.s f5, f0, f0\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            # self.text_segment += f"add.s f5, f0, 1\n"
            self.text_segment += f"fli f5, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"fsub.s x5, x5, x6\n"
            self.text_segment += f"fsw f5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.FLOAT

    def LessThanOrEquals(self, line):
        """
        Le INT
        """
        datatype = line[-1]
        self.prev_operator = Operators.Le

        label1 = self.get_new_label()
        label2 = self.get_new_label()

        if (datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sw x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.INT
        elif (datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.CHAR
        elif (datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.BOOL
        # (need to check this conversion properly)
        elif (datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f4, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f3, 0(x2)\n"      # RHS

            # self.text_segment += f"flt.s f3, f4, {label1}\n"
            self.text_segment += f"flt.s x28, f3, f4\n"
            self.text_segment += f"bne x28, x0, {label1}\n"

            # self.text_segment += f"fle.s f3, f4, {label1}\n"
            self.text_segment += f"fle.s x28, f3, f4\n"
            self.text_segment += f"bne x28, x0, {label1}\n"

            self.text_segment += f"fli f5, 0\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"fli f5, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"fsub.s x5, x5, x6\n"
            self.text_segment += f"fsw f5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.FLOAT

    def GreaterThan(self, line):
        """
        Gt INT
        """
        datatype = line[-1]
        self.prev_operator = Operators.Gt

        label1 = self.get_new_label()
        label2 = self.get_new_label()

        if (datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sw x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.INT
        elif (datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.CHAR
        elif (datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.BOOL
        # (need to check this conversion properly)
        elif (datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f4, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f3, 0(x2)\n"      # RHS

            # self.text_segment += f"flt.s f3, f4, {label1}\n"
            self.text_segment += f"flt.s x28, f3, f4\n"
            self.text_segment += f"bne x28, x0, {label1}\n"

            # self.text_segment += f"fle.s f3, f4, {label1}\n"
            self.text_segment += f"fle.s x28, f3, f4\n"
            self.text_segment += f"bne x28, x0, {label1}\n"

            self.text_segment += f"fli f5, 1\n"
            self.text_segment += f"jal x30, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"fli f5, 0\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"fsub.s x5, x5, x6\n"
            self.text_segment += f"fsw f5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.FLOAT

        self.text_segment += '\n'

    def if_goto(self, line):
        """
        if-goto L4
        """
        datatype = self.prev_datatype
        label = line[-1]
        if (datatype == Datatypes.INT or datatype == None):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"
            self.text_segment += f"li x6, 1\n"
            self.text_segment += f"beq x5, x6, {label}\n"
        elif (datatype == Datatypes.CHAR or datatype == Datatypes.BOOL):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"li x6, 1\n"
            self.text_segment += f"beq x5, x6, {label}\n"
        # Has to be re-done (the implementation has been changed for eq, lt, ... )
        elif (datatype == Datatypes.FLOAT):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f3, 0(x2)\n"
            # the top of the stack does not store the subtracted value
            # if (len(self.prev_operator.value) == 3):
            # self.text_segment += f"fsub.s f3, f0, f3\n"
            # self.text_segment += f"{self.prev_operator.value[1]} f3, f0, {label}\n"
            self.text_segment += f"fli f4, 1\n"
            # self.text_segment += f"fle.s f3, f4, {label}\n"
            self.text_segment += f"fle.s x28, f3, f4\n"
            self.text_segment += f"bne x28, x0, {label}\n"

        self.text_segment += '\n'

        # self.prev_datatype = None
        self.prev_operator = None

    def print_stmt(self, line):
        """
        push local 0 INT
        print INT
        """
        datatype = line[-1]
        if (datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"
            self.text_segment += f"add a0, x5, x0\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.text_segment += f"li a7, 1\n"
            self.text_segment += f"ecall\n"
        elif (datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"add a0, x5, x0\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.text_segment += f"li a7, 11\n"
            self.text_segment += f"ecall\n"
        elif (datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            # self.text_segment += f"li x5, 0\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"add a0, x5, x0\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.text_segment += f"li a7, 4\n"
            self.text_segment += f"ecall\n"
        elif (datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw fa0, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.text_segment += f"li a7, 2\n"
            self.text_segment += f"ecall\n"
        elif (datatype == Datatypes.STR.value):
            pass

        self.text_segment += '\n'

    def function_call(self, line):
        num_args = int(line[-1])

        if (num_args == 0):
            self.push('push constant 0 INT'.split(' '))

        # storing current arg pointer in x7 register
        self.text_segment += f"li x5, -{self.arg}\n"
        self.text_segment += f"lw x7, 0(x5)\n"

        # setting arg pointer
        self.text_segment += f"addi x5, x2, {(num_args+1)*4}\n"
        self.text_segment += f"li x6, -{self.arg}\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        # pushing context
        self.text_segment += f"li x5, -{self.lcl}\n"
        self.text_segment += f"lw x6, 0(x5)\n"
        self.text_segment += f"sw x6, 0(x2)\n"
        self.text_segment += f"addi x2, x2, -4\n"

        # self.text_segment += f"li x5, -{self.arg}\n"
        # self.text_segment += f"lw x6, 0(x5)\n"
        self.text_segment += f"sw x7, 0(x2)\n"
        self.text_segment += f"addi x2, x2, -4\n"

        self.text_segment += f"li x5, -{self.tmp}\n"
        self.text_segment += f"lw x6, 0(x5)\n"
        self.text_segment += f"sw x6, 0(x2)\n"
        self.text_segment += f"addi x2, x2, -4\n"

        self.text_segment += f"li x5, -{self.this}\n"
        self.text_segment += f"lw x6, 0(x5)\n"
        self.text_segment += f"sw x6, 0(x2)\n"
        self.text_segment += f"addi x2, x2, -4\n"

        self.text_segment += f"li x5, -{self.that}\n"
        self.text_segment += f"lw x6, 0(x5)\n"
        self.text_segment += f"sw x6, 0(x2)\n"
        self.text_segment += f"addi x2, x2, -4\n"

        self.text_segment += f"jal x1, {line[1]}\n"

        self.text_segment += '\n'

    def function_def(self, line):
        """
        function mult 2 3 FLOAT
        """

        self.num_local = int(line[-3])
        self.num_temp = int(line[-2])
        function = line[1]
        self.cur_function = function
        if (function == 'main'):
            self.text_segment += f"{function}:\n"
            self.init_mem()
            self.text_segment += '\n'
            return

        self.text_segment += f"{function}:\n"
        # storing return address
        self.text_segment += f"sw x1, 0(x2)\n"

        # setting new LCL
        self.text_segment += f"addi x2, x2, -4\n"
        self.text_segment += f"li x5, -{self.lcl}\n"
        self.text_segment += f"sw x2, 0(x5)\n"

        # setting new TMP
        self.text_segment += f"addi x6, x2, -{self.num_local*4}\n"
        self.text_segment += f"li x5, -{self.tmp}\n"
        self.text_segment += f"sw x2, 0(x5)\n"

        # setting new working stack
        self.text_segment += f"addi x2, x2, -{(self.num_temp+self.num_local)*4}\n"

        self.text_segment += '\n'

    def return_call(self, line):

        if (self.cur_function == 'main'):
            self.text_segment += f"jal x30, __END__\n"
            return

        self.text_segment += f"addi x2, x2, 4\n"
        self.text_segment += f"lw x5, 0(x2)\n"
        self.text_segment += f"li x6, -{self.arg}\n"
        self.text_segment += f"lw x6, 0(x6)\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        # self.text_segment += f"addi x2, x2, {(self.num_local+self.num_temp)*4}\n"
        self.text_segment += f"li x5, -{self.lcl}\n"
        self.text_segment += f"lw x2, 0(x5)\n"

        self.text_segment += f"lw x5, 8(x2)\n"
        self.text_segment += f"li x6, -{self.that}\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        self.text_segment += f"lw x5, 12(x2)\n"
        self.text_segment += f"li x6, -{self.this}\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        self.text_segment += f"lw x5, 16(x2)\n"
        self.text_segment += f"li x6, -{self.tmp}\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        self.text_segment += f"lw x7, 20(x2)\n"
        # self.text_segment += f"li x6, -{self.arg}\n"
        # self.text_segment += f"sw x5, 0(x6)\n"

        self.text_segment += f"lw x5, 24(x2)\n"
        self.text_segment += f"li x6, -{self.lcl}\n"
        self.text_segment += f"sw x5, 0(x6)\n"

        self.text_segment += f"lw x5, 4(x2)\n"

        self.text_segment += f"li x6, -{self.arg}\n"
        self.text_segment += f"lw x2, 0(x6)\n"

        self.text_segment += f"addi x2, x2, -4\n"

        # self.text_segment += f"lw x5, 20(x2)\n"
        self.text_segment += f"li x6, -{self.arg}\n"
        self.text_segment += f"sw x7, 0(x6)\n"

        self.text_segment += f"jalr x28, x5, 0\n"

        self.text_segment += '\n'

    def scan(self, line):
        datatype = line[-1]

        if (datatype == Datatypes.INT.value):
            self.text_segment += "addi a7, x0, 5\necall\n"
            self.text_segment += f"sw a0, 0(x2)\n"

        # taking char input
        elif (datatype == Datatypes.CHAR.value):
            self.text_segment += "addi a7, x0, 12\necall\n"
            self.text_segment += f"sw a0, 0(x2)\n"

        # taking float input
        elif (datatype == Datatypes.FLOAT.value):
            self.text_segment += "addi a7, x0, 6\necall\n"
            self.text_segment += f"fsw fa0, 0(x2)\n"

        self.text_segment += f"addi x2, x2, -4\n"
        self.pop(f"pop {line[1]} {line[2]} {line[3]}".split(' '))

    def generate_target_code(self, vm_code):

        preprocess = Preprocess()
        vm_code = preprocess.preprocess(vm_code)

        for line in vm_code.splitlines():
            # print(line)
            line = shlex.split(line)
            if (len(line) == 0):
                continue

            if (line[0] == Instructions.Add.value or line[0] == Instructions.Sub.value or line[0] == Instructions.BitAnd.value or
                    line[0] == Instructions.BitOr.value or line[0] == Instructions.BitXor.value or line[0] == Instructions.LShift.value or
                    line[0] == Instructions.RShift.value):
                self.Operator(line)
            elif (line[0] == Instructions.Eq.value or line[0] == Instructions.Lt.value or line[0] == Instructions.Ge.value):
                self.Condtion_builtin(line)
            elif (line[0] == Instructions.Le.value):
                self.LessThanOrEquals(line)
            elif (line[0] == Instructions.Gt.value):
                self.GreaterThan(line)
            elif (line[0] == Instructions.push.value):
                self.push(line)
            elif (line[0] == Instructions.pop.value):
                self.pop(line)
            elif (line[0] == Instructions.function.value):
                self.function_def(line)
            elif (line[0] == Instructions.ret.value):
                self.return_call(line)
            elif (line[0] == Instructions.if_goto.value):
                self.if_goto(line)
            elif (line[0] == Instructions.goto.value):
                self.goto(line)
            elif (line[0] == Instructions.label.value):
                self.label(line)
            elif (line[0] == Instructions.print_stmt.value):
                self.print_stmt(line)
            elif (line[0] == Instructions.call.value):
                self.function_call(line)
            elif (line[0] == Instructions.scan.value):
                self.scan(line)

        self.text_segment = postprocess(self.text_segment)

        sorted_list = sorted(
            self.data_segment_dict.items(), key=lambda x: x[1][2])

        for var, (type, value, _, __) in sorted_list:
            self.data_segment += f"{var}:\n\t{type} \"{value}\"\n"

        final_code = self.data_segment+'\n'+self.text_segment
        return final_code
