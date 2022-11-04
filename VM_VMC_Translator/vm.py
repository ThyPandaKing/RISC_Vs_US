from enums import *
from preprocess import *
from postprocess import *


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
        self.text_segment = ".global main\nbeq x0, x0, main\n"
        self.prev_operator = None
        self.prev_datatype = None
        self.prev_push_segment = None
        self.label_index = 0
        self.return_type = 'INT'
        self.num_local = 0
        self.num_temp = 0
        self.function_stack = []

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

    def function(self, line):
        """
        """
        func = line[1].split('.')[0]
        self.text_segment += f"{func}:\n"

        self.text_segment += "\n"

        self.init_mem()

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
        self.text_segment += f"beq x0, x0, {line[-1]}\n"

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
        if(datatype == Datatypes.INT.value or datatype == Datatypes.BOOL.value):
            index = int(line[2])
        elif(datatype == Datatypes.CHAR.value):
            if(segment == Segment.constant.value):
                index = ord(line[2][1])
            else:
                index = int(line[2])
        elif(datatype == Datatypes.FLOAT.value):
            index = float(line[2])

        if(segment != Segment.constant.value):
            pointer = None
            if(segment == Segment.local.value):
                pointer = self.lcl
            elif(segment == Segment.temp.value):
                pointer = self.tmp
            elif(segment == Segment.argument.value):
                pointer = self.arg

            if(datatype == Datatypes.INT.value):
                # self.text_segment += f"lw x5, {-(pointer)}(x8)\n"

                self.text_segment += f"li x5, {-(pointer)}\n"
                self.text_segment += f"add x5, x5, x8\n"
                self.text_segment += f"lw x5, 0(x5)\n"

                self.text_segment += f"addi x5, x5, {-(index*4+4)}\n"
                self.text_segment += f"lw x5, 0(x5)\n"
                self.text_segment += f"sw x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.CHAR.value or datatype == Datatypes.BOOL.value):
                # self.text_segment += f"lw x5, {-(pointer)}(x8)\n"
                self.text_segment += f"li x5, {-(pointer)}\n"
                self.text_segment += f"add x5, x5, x8\n"
                self.text_segment += f"lw x5, 0(x5)\n"

                self.text_segment += f"addi x5, x5, {-(index*4+4)}\n"
                self.text_segment += f"lb x5, 0(x5)\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.FLOAT.value):
                # self.text_segment += f"lw x5, {-(pointer)}(x8)\n"
                self.text_segment += f"li x5, {-(pointer)}\n"
                self.text_segment += f"add x5, x5, x8\n"
                self.text_segment += f"lw x5, 0(x5)\n"

                self.text_segment += f"addi x5, x5, {-(int(index)*4+4)}\n"
                self.text_segment += f"flw f3, 0(x5)\n"
                self.text_segment += f"fsw f3, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"

            self.text_segment += "\n"

        elif(segment == Segment.constant.value):
            constant = index
            if(datatype == Datatypes.INT.value):
                self.text_segment += f"li x5, {constant}\n"
                self.text_segment += f"sw x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.CHAR.value):
                self.text_segment += f"li x5, {constant}\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.BOOL.value):
                self.text_segment += f"li x5, {1 if line[2]=='true' else 0}\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.FLOAT.value):
                self.text_segment += f"fli f3, {constant}\n"
                self.text_segment += f"fsw f3, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"

            self.text_segment += "\n"
        self.text_segment += "\n"

    def pop(self, line):
        """
        pop local 4 INT
        pop temp 0 CHAR
        """
        segment = line[1]
        datatype = line[-1]
        index = int(line[2])

        pointer = None
        if(segment == Segment.local.value):
            pointer = self.lcl
        elif(segment == Segment.temp.value):
            pointer = self.tmp
        elif(segment == Segment.argument.value):
            pointer = self.arg

        if(datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"

            # self.text_segment += f"lw x6, {-(pointer)}(x8)\n"

            self.text_segment += f"li x6, {-pointer}\n"
            self.text_segment += f"add x6, x6, x8\n"
            self.text_segment += f"lw x6, 0(x6)\n"

            self.text_segment += f"addi x6, x6, {-(index*4+4)}\n"
            self.text_segment += f"sw x5, 0(x6)\n"
        elif(datatype == Datatypes.CHAR.value or datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            # self.text_segment += f"lw x6, {-(pointer)}(x8)\n"
            self.text_segment += f"li x6, {-pointer}\n"
            self.text_segment += f"add x6, x6, x8\n"
            self.text_segment += f"lw x6, 0(x6)\n"

            self.text_segment += f"addi x6, x6, {-(index*4+4)}\n"
            self.text_segment += f"sb x5, 0(x6)\n"
        elif(datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f3, 0(x2)\n"
            # self.text_segment += f"lw x6, {-(pointer)}(x8)\n"
            self.text_segment += f"li x6, {-pointer}\n"
            self.text_segment += f"add x6, x6, x8\n"
            self.text_segment += f"lw x6, 0(x6)\n"

            self.text_segment += f"addi x6, x6, {-(index*4+4)}\n"
            self.text_segment += f"fsw f3, 0(x6)\n"

        self.text_segment += '\n'

    def Operator(self, line):
        """
        Add/Sub/LShift/RShift/BitAnd/BitOr/BitXor INT
        Add/Sub FLOAT
        """
        datatype = line[-1]
        operator = line[0]
        instruction = ''
        if(operator == Instructions.Add.value):
            instruction = Operators.Add.value
        elif(operator == Instructions.Sub.value):
            instruction = Operators.Sub.value
        elif(operator == Instructions.LShift.value):
            instruction = Operators.LShift.value
        elif(operator == Instructions.RShift.value):
            instruction = Operators.RShift.value
        elif(operator == Instructions.BitAnd.value):
            instruction = Operators.BitAnd.value
        elif(operator == Instructions.BitOr.value):
            instruction = Operators.BitOr.value
        elif(operator == Instructions.BitXor.value):
            instruction = Operators.BitXor.value

        if(datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"
            self.text_segment += f"{instruction[0]} x5, x5, x6\n"
            self.text_segment += f"sw x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
        elif(datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"
            self.text_segment += f"{instruction[0]} x5, x5, x6\n"
            self.text_segment += f"sb x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
        elif(datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"
            self.text_segment += f"{instruction[0]} x5, x5, x6\n"
            self.text_segment += f"sb x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
        elif(datatype == Datatypes.FLOAT.value):
            if(operator == Instructions.Add.value or operator == Instructions.Sub.value):
                self.text_segment += f"addi x2, x2, 4\n"
                self.text_segment += f"flw f3, 0(x2)\n"
                self.text_segment += f"addi x2, x2, 4\n"
                self.text_segment += f"flw f4, 0(x2)\n"
                self.text_segment += f"{instruction[1]} f3, f3, f4\n"
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

        if(condition == Instructions.Eq.value):
            condition = Operators.Eq
            branch = Operators.Eq.value[0]
        elif(condition == Instructions.Lt.value):
            condition = Operators.Lt
            branch = Operators.Lt.value[0]
        elif(condition == Instructions.Ge.value):
            condition = Operators.Ge
            branch = Operators.Ge.value[0]

        self.prev_operator = condition

        label1 = self.get_new_label()
        label2 = self.get_new_label()

        if(datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"      # RHS

            self.text_segment += f"{branch} x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sw x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.INT
        elif(datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"{branch} x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.CHAR
        elif(datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"{branch} x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"add x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.BOOL
        # (need to check this conversion properly)
        elif(datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f4, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f3, 0(x2)\n"      # RHS

            self.text_segment += f"{branch} f3, f4, {label1}\n"
            self.text_segment += f"addi f5, f0, 0\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi f5, f0, 1\n"
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

        if(datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sw x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.INT
        elif(datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.CHAR
        elif(datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.BOOL
        # (need to check this conversion properly)
        elif(datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f4, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f3, 0(x2)\n"      # RHS

            self.text_segment += f"blt f3, f4, {label1}\n"
            self.text_segment += f"beq f3, f4, {label1}\n"
            self.text_segment += f"addi f5, f0, 0\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi f5, f0, 1\n"
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

        if(datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sw x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.INT
        elif(datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.CHAR
        elif(datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x6, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"      # RHS

            self.text_segment += f"blt x5, x6, {label1}\n"
            self.text_segment += f"beq x5, x6, {label1}\n"
            self.text_segment += f"addi x7, x0, 1\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi x7, x0, 0\n"
            self.text_segment += f"{label2}:\n"

            # self.text_segment += f"sub x5, x5, x6\n"
            self.text_segment += f"sb x7, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.prev_datatype = Datatypes.BOOL
        # (need to check this conversion properly)
        elif(datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f4, 0(x2)\n"      # LHS
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f3, 0(x2)\n"      # RHS

            self.text_segment += f"blt f3, f4, {label1}\n"
            self.text_segment += f"beq f3, f4, {label1}\n"
            self.text_segment += f"addi f5, f0, 1\n"
            self.text_segment += f"beq x0, x0, {label2}\n"
            self.text_segment += f"{label1}:\n"
            self.text_segment += f"addi f5, f0, 0\n"
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

        if(datatype == Datatypes.INT):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"
            self.text_segment += f"li x6, 1\n"
            self.text_segment += f"beq x5, x6, {label}\n"
        elif(datatype == Datatypes.CHAR or datatype == Datatypes.BOOL):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"li x6, 1\n"
            self.text_segment += f"beq x5, x6, {label}\n"
        # Has to be re-done (the implementation has been changed for eq, lt, ... )
        elif(datatype == Datatypes.FLOAT):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw f3, 0(x2)\n"
            # the top of the stack does not store the subtracted value
            if(len(self.prev_operator.value) == 3):
                self.text_segment += f"fsub.s f3, f0, f3\n"
            self.text_segment += f"{self.prev_operator.value[1]} f3, f0, {label}\n"

        self.text_segment += '\n'

        self.prev_datatype = None
        self.prev_operator = None

    def print_stmt(self, line):
        """
        push local 0 INT
        print INT
        """
        datatype = line[-1]
        if(datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"
            self.text_segment += f"add a0, x5, x0\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.text_segment += f"li a7, 1\n"
            self.text_segment += f"ecall\n"
        elif(datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"add a0, x5, x0\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.text_segment += f"li a7, 11\n"
            self.text_segment += f"ecall\n"
        elif(datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            # self.text_segment += f"li x5, 0\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"add a0, x5, x0\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.text_segment += f"li a7, 4\n"
            self.text_segment += f"ecall\n"
        elif(datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw fa0, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"
            self.text_segment += f"li a7, 2\n"
            self.text_segment += f"ecall\n"

        self.text_segment += '\n'

    def function_call(self, line):
        num_args = int(line[-1])

        if(num_args == 0):
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

        self.function_stack.append(function)

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
        # self.pop((f"pop argument 0 {self.return_type}").split(' '))

        if(self.function_stack[-1] == 'main'):
            self.text_segment += f"beq x0, x0, __END__\n"
            return

        self.function_stack.pop()

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

    def generate_target_code(self, vm_code):

        preprocess = Preprocess()
        vm_code = preprocess.preprocess(vm_code)

        for line in vm_code.splitlines():
            line = line.split(' ')

            if(line[0] == Instructions.Add.value or line[0] == Instructions.Sub.value or line[0] == Instructions.BitAnd.value or
                    line[0] == Instructions.BitOr.value or line[0] == Instructions.BitXor.value or line[0] == Instructions.LShift.value or
                    line[0] == Instructions.RShift.value):
                self.Operator(line)
            elif(line[0] == Instructions.Eq.value or line[0] == Instructions.Lt.value or line[0] == Instructions.Ge.value):
                self.Condtion_builtin(line)
            elif(line[0] == Instructions.Le.value):
                self.LessThanOrEquals(line)
            elif(line[0] == Instructions.Gt.value):
                self.GreaterThan(line)
            elif(line[0] == Instructions.push.value):
                self.push(line)
            elif(line[0] == Instructions.pop.value):
                self.pop(line)
            elif(line[0] == Instructions.function.value):
                self.function_def(line)
            elif(line[0] == Instructions.ret.value):
                self.return_call(line)
            elif(line[0] == Instructions.if_goto.value):
                self.if_goto(line)
            elif(line[0] == Instructions.goto.value):
                self.goto(line)
            elif(line[0] == Instructions.label.value):
                self.label(line)
            elif(line[0] == Instructions.print_stmt.value):
                self.print_stmt(line)
            elif(line[0] == Instructions.call.value):
                self.function_call(line)

        self.text_segment = postprocess(self.text_segment)

        return self.text_segment
