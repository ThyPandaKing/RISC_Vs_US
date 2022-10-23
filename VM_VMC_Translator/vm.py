from enums import *


class VM:
    def __init__(self):
        self.RAM = [0 for _ in range(2048)]

        self.RAM[0] = 1280          # stack segment is from -1280 to -2047
        self.sp = self.RAM[0]

        self.RAM[1] = 0
        self.lcl = self.RAM[1]      # local segment is from 0 to -635

        self.RAM[2] = 636
        self.arg = self.RAM[2]      # argument segment is from -636 to -643

        self.RAM[3] = 644
        self.tmp = self.RAM[3]      # temp segment is from -644 to -1279

        self.text_segment = ".global Main\n"
        self.text_segment += f"addi x2, x8, -1284\n"

    def function(self, line):
        """
        """
        func = line[1].split('.')[0]
        self.text_segment += f"{func}:\n"

        self.text_segment += "\n"

    def push(self, line):
        """
        push local 4 INT
        push constant -5.6 FLOAT
        push constant 'c' CHAR
        push constant true BOOL
        """
        segment = line[1]
        datatype = line[-1]
        index = int(line[2])

        if(segment != Segment.constant.value):
            pointer = None
            if(segment == Segment.local.value):
                pointer = self.lcl
            elif(segment == Segment.temp.value):
                pointer = self.tmp
            elif(segment == Segment.argument.value):
                pointer = self.arg

            if(datatype == Datatypes.INT.value):
                self.text_segment += f"lw x5, {-(pointer+index+4)}(x8)\n"
                self.text_segment += f"sw x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.CHAR.value):
                self.text_segment += f"lb x5, {-(pointer+index+4)}(x8)\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.BOOL.value):
                self.text_segment += f"lb x5, {-(pointer+index+4)}(x8)\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.FLOAT.value):
                self.text_segment += f"flw f3, {-(pointer+index+4)}(x8)\n"
                self.text_segment += f"fsw f3, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"

            self.text_segment += "\n"

        elif(segment == Segment.constant.value):
            constant = int(line[2])
            if(datatype == Datatypes.INT.value):
                self.text_segment += f"li x5, {constant}\n"
                self.text_segment += f"sw x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.CHAR.value):
                self.text_segment += f"li x5, {ord(constant)}\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.BOOL.value):
                self.text_segment += f"lb x5, {1 if constant=='true' else 0}\n"
                self.text_segment += f"sb x5, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"
            elif(datatype == Datatypes.FLOAT.value):
                self.text_segment += f"fli f3, {constant}\n"
                self.text_segment += f"fsw f3, 0(x2)\n"
                self.text_segment += f"addi x2, x2, -4\n"

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
            self.text_segment += f"sw x5, {-(pointer+index+4)}(x8)\n"
        elif(datatype == Datatypes.CHAR.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"sb x5, {-(pointer+index+4)}(x8)\n"
        elif(datatype == Datatypes.BOOL.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lb x5, 0(x2)\n"
            self.text_segment += f"sb x5, {-(pointer+index+4)}(x8)\n"
        elif(datatype == Datatypes.FLOAT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"flw x5, 0(x2)\n"
            self.text_segment += f"fsw x5, {-(pointer+index+4)}(x8)\n"

    def Add(self, line):
        """
        Add FLOAT
        """
        datatype = line[-1]

        if(datatype == Datatypes.INT.value):
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, 4\n"
            self.text_segment += f"lw x6, 0(x2)\n"
            self.text_segment += f"add x5, x5, x6\n"
            self.text_segment += f"sw x5, 0(x2)\n"
            self.text_segment += f"addi x2, x2, -4\n"

    def generate_target_code(self, vm_code):

        for line in vm_code.splitlines():
            line = line.split(' ')

            if(line[0] == Instructions.Add.value):
                self.Add(line)
            elif(line[0] == Instructions.Sub.value):
                return Instructions.Sub
            elif(line[0] == Instructions.Eq.value):
                return Instructions.Eq
            elif(line[0] == Instructions.Lt.value):
                return Instructions.Lt
            elif(line[0] == Instructions.Gt.value):
                return Instructions.Gt
            elif(line[0] == Instructions.Ge.value):
                return Instructions.Ge
            elif(line[0] == Instructions.Le.value):
                return Instructions.Le
            elif(line[0] == Instructions.Neq.value):
                return Instructions.Neq
            elif(line[0] == Instructions.push.value):
                self.push(line)
            elif(line[0] == Instructions.pop.value):
                self.pop(line)
            elif(line[0] == Instructions.function.value):
                self.function(line)
            elif(line[0] == Instructions.ret.value):
                return Instructions.ret
            elif(line[0] == Instructions.if_goto.value):
                return Instructions.if_goto
            elif(line[0] == Instructions.goto.value):
                return Instructions.goto
            elif(line[0] == Instructions.label.value):
                return Instructions.label
            elif(line[0] == Instructions.print_stmt.value):
                return Instructions.print

        return self.text_segment
