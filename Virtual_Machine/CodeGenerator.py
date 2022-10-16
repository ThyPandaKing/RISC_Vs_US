# -*- coding: future_fstrings -*-
import enum
import struct
import operator

class Operators(enum.Enum):
    Plus = '+'
    Minus = '-'
    Mul = '*'
    Div = '/'
    Mod = '%'
    BitAnd = '&'
    BitOr = '|'
    BitXor = '^'
    LeftShift = '<<'
    RightShift = '>>'
    LogicalAnd = '&&'
    LogicalOr = '||'
    Gre = '>'
    Less = '<'
    GreEq = '>='
    LessEq = '<='
    Not = '!'
    NotEq = '!='
    Eq = '=='
    Assign = '='


class Datatypes(enum.Enum):
    INT = 'int'
    FLOAT = 'float'
    BOOL = 'bool'
    CHAR = 'char'
    STR = 'str'


class CodeGenerator:

    available_registers = [
        'x5',
        'x6',
        'x7',
        'x28',
        'x29',
        'x30',
        'x31',
    ]

    default_reg_des = {
        'x5': None,
        'x6': None,
        'x7': None,
        'x28': None,
        'x29': None,
        'x30': None,
        'x31': None
    }

    available_float_registers = [
        'f3',
        'f4',
        'f5',
        'f6',
        'f7',
        'f28',
        'f29',
        'f30',
        'f31',
    ]

    default_float_reg_des = {
        'f3':None,
        'f4':None,
        'f5':None,
        'f6':None,
        'f7':None,
        'f28':None,
        'f29':None,
        'f30':None,
        'f31':None
    }

    datatype_sizes = {
        'int': 4,
        'float': 4,
        'char': 1,
        'bool': 1,
    }

    operators = set("+ - * / % & | ^ << >> && || > < >= <= ! != = ==".split())
    relational_operators = set("> < >= <= != ==".split())

    def __init__(self) :
        self.rr_registers_index = 0    # pointer for round robin register fetch
        self.rr_registers_index_float = 0    # pointer for round robin float register fetch
        self.register_descriptor = self.default_reg_des.copy()  # register descriptor
        self.float_register_descriptor = self.default_float_reg_des.copy()  # float register descriptor
        self.address_descriptor = {}    # address descriptor
        self.text_segment = '.section\n.text\n'
        self.data_segment = '.section\n.data\n'
        self.data_segment_dict = {}
        self.ds_variables = {}
        self.offset = 4     # for stack pointer (spill)
        self.symbol_table = {}      # a custom symbol table
        self.data_segment_start = 0x10010000        # start address of datasegment

    def get_data_type(self, instruction) :
        """
        function to get the data type
        of an instruction
        """
        return instruction.split(' ')[-1].lower()

    def is_binary_arithmetic(self, instruction) :
        """
        function that returns true if instruction
        is a binary arithmetic instruction
        """
        if(len(instruction.split(' ')) != 6):
            return False
        if(len(set(instruction.split(' ')).intersection(self.operators)) != 2):
            return False
        return True

    def update_descriptors(self, register, variable, line=None) :
        """
        updates register descriptor and
        address descriptor
        """
        if(self.address_descriptor[variable] is not None):
            self.address_descriptor[variable]['registers'] = register
        else:
            self.address_descriptor[variable] = {
                'offset': self.offset,
                'registers': register
            }
            self.offset += 4

        self.register_descriptor[register] = variable
        print(self.register_descriptor)

    def update_float_descriptors(self, register, variable) :
        """
        updates register descriptor and
        address descriptor
        """
        if(self.address_descriptor[variable] is not None):
            self.address_descriptor[variable]['registers'] = register
        else:
            self.address_descriptor[variable] = {
                'offset': self.offset,
                'registers': register
            }
            self.offset += 4

        self.float_register_descriptor[register] = variable

    def is_declaration(self, instruction) :
        """
        returns true if the instruction is a
        variable declaration instruction
        """
        split = instruction.split(' ')
        if(len(split) != 3 or split[0] != '-'):
            return False
        return True

    def is_assignment(self, instruction) :
        """
        function that returns true if instruction
        is an assignment instruction
        """
        split = instruction.split(' ')
        if(len(split) != 4):
            return False
        if(split[1] != '='):
            return False
        return True

    def is_unary_assignment(self, instruction) :
        """
        function that returns true if instruction
        is an assignment instruction containing
        a unary minus in the operand
        """
        split = instruction.split(' ')
        if(len(split) != 5):
            return False
        if(split[1] != '='):
            return False
        if(split[2] != '-'):
            return False
        return True

    def is_if_statement_with_relop(self, instruction) :
        """
        function that returns true if instruction
        is an if statement
        """
        if(instruction.startswith('if ') and len(set(instruction.split(' ')).intersection(self.relational_operators)) != 0):
            return True
        return False

    def is_if_statement_without_relop(self, instruction) :
        """
        function that returns true if instruction
        is an if statement
        """
        if(instruction.startswith('if ') and not self.is_if_statement_with_relop(instruction)):
            return True
        return False

    def is_goto_statement(self, instruction):
        """
        function that returns true if instruction
        is a goto statement
        """
        if(instruction.startswith('GOTO ')):
            return True
        return False

    def is_return_statement(self, instruction) :
        """
        function that returns true if instruction
        is a return statement
        """
        if(instruction.startswith('return ')):
            return True
        return False

    def is_input_statement(self, instruction) :
        """
        function that returns true if instruction
        is a user input statement
        """
        if(instruction.startswith('input ')):
            return True
        return False

    def is_output_statement(self, instruction) :
        """
        function that returns true if instruction
        is an output statement
        """
        if(instruction.startswith('print ')):
            return True
        return False

    def isfloat(self, num) :
        """
        function that returns true if value
        is a float constant
        """
        if num.isdigit():
            return False
        try:
            float(num)
            return True
        except ValueError:
            return False

    def is_constant(self, value) :
        """
        function that returns true if value
        is a constant
        """
        if(value[0] == '-'):
            value = value[1:]
        if(len(value) == 0):
            return (False, '')

        # check character
        if value[0] == '\'':
            return (True, 'char')
        # check int
        if value.isdigit():
            return (True, 'int')
        # check float
        if self.isfloat(value):
            return (True, 'float')
        # check string
        if value[0] == '\"' and value[-1] == '\"':
            return (True, 'str')
        # not a constant
        return (False, '')

    def get_register(self, variable) :
        """
        returns a register based on
        the allocation algorithm
        takes care of spilling
        """
        # check if the variable is already in some register
        for reg in self.register_descriptor:
            if(self.register_descriptor[reg] == variable):
                return (reg, 0)
        # check for an empty register
        for reg in self.register_descriptor:
            if(self.register_descriptor[reg] is None):
                return (reg, 1)
        # spill a register according to rr_registers_index
        register = self.available_registers[self.rr_registers_index]
        self.spill_register(register)
        self.rr_registers_index = (
            self.rr_registers_index+1) % len(self.available_registers)

        return (register, 1)

    def get_float_register(self, variable) :
        """
        returns a float register based on
        the allocation algorithm and it
        takes care of spilling
        """
        # check if the variable is already in some register
        for reg in self.float_register_descriptor:
            if(self.float_register_descriptor[reg] == variable):
                return (reg, 0)
        # check for an empty register
        for reg in self.float_register_descriptor:
            if(self.float_register_descriptor[reg] is None):
                return (reg, 1)
        # spill a register according to rr_registers_index_float
        register = self.available_float_registers[self.rr_registers_index_float]
        self.spill_float_register(register)
        self.rr_registers_index_float = (
            self.rr_registers_index_float+1) % len(self.available_float_registers)

        return (register, 1)

    def spill_register(self, register) :
        """
        handles the logic of spilling
        a register
        """

        variable = self.register_descriptor[register]

        # update address descriptor
        if(self.address_descriptor[variable] is not None):
            try:
                self.address_descriptor[variable]["registers"] = None
                self.text_segment += f"sw {register}, {-self.address_descriptor[variable]['offset']}(x8)\n"
            except KeyError or ValueError:
                # should not reach here
                print("Error: register not present in address descriptor")
        else:
            self.address_descriptor[variable] = {
                'offset': self.offset,
                'registers': None
            }
            self.text_segment += f"sw {register}, {-self.offset}(x8)\n"
            self.offset += 4

        # update register descriptor
        self.register_descriptor[register] = None

    def spill_float_register(self, register) :
        """
        handles the logic of spilling
        a float register
        """

        variable = self.float_register_descriptor[register]

        # update address descriptor
        if(self.address_descriptor[variable] is not None):
            try:
                self.address_descriptor[variable]["registers"] = None
                self.text_segment += f"fsw {register}, {-self.address_descriptor[variable]['offset']}(x8)\n"
            except KeyError or ValueError:
                # should not reach here
                print("Error: register not present in address descriptor")
        else:
            self.address_descriptor[variable] = {
                'offset': self.offset,
                'registers': None
            }
            self.text_segment += f"fsw {register}, {-self.offset}(x8)\n"
            self.offset += 4

        # update register descriptor
        self.float_register_descriptor[register] = None

    def get_ieee_rep(self, value, hex=None):
        """
        function that converts a constant
        into IEEE 754 floating point representation
        """
        if hex is None:
            hex=''.join('{:02x}'.format(ord(x))[::-1] for x in struct.pack('f',float(value)))[::-1]
        upper = hex[:5]
        mid = hex[5]
        lower = hex[6:]
        return ('0x'+upper, '0x'+mid, '0x'+lower)

    def update_symbol_table(self, subject, datatype) :
        """
        updates the symbol table
        """
        if(self.symbol_table[subject] is not None):
            self.symbol_table[subject]['datatype'] = datatype
        else:
            self.symbol_table[subject] = {
                'datatype': datatype
            }

    def spill_all_registers(self) :
        """
        function that spills all registers
        at the end of each block
        """

        self.text_segment += '# ---- start of spill ----\n'
        for var, val in self.address_descriptor.items():
            reg = val['registers']
            if(reg is not None):
                offset = self.address_descriptor[var]['offset']
                self.address_descriptor[var]['registers'] = None
                if(self.symbol_table[var]['datatype'] == Datatypes.INT):
                    self.text_segment += f"sw {reg}, {-offset}(x8)\n"
                elif(self.symbol_table[var]['datatype'] == Datatypes.BOOL or
                     self.symbol_table[var]['datatype'] == Datatypes.CHAR):
                    self.text_segment += f"sb {reg}, {-offset}(x8)\n"
                elif(self.symbol_table[var]['datatype'] == Datatypes.FLOAT):
                    self.text_segment += f"fsw {reg}, {-offset}(x8)\n"

        self.text_segment += '# ---- end of spill ----\n'

        self.register_descriptor = self.default_reg_des.copy()
        self.float_register_descriptor = self.default_float_reg_des.copy()

    def main(self, blocks) :
        """
        the starting point of register allocation
        """

        # TODO: complete this
        for block in blocks:
            for line in block.splitlines():
                if(line.endswith(':')):
                    line = line.replace('#', '__')
                    self.text_segment += line+'\n'

                elif(line.startswith('.global')):
                    self.text_segment += line+'\n'

                elif(self.is_goto_statement(line)):
                    self.spill_all_registers()
                    self.text_segment += f"beq x0, x0, {line.split(' ')[1]}\n"

                elif(self.is_binary_arithmetic(line)):
                    line = line.split(' ')
                    exp_datatype = line[-1]

                    if(line[-1].lower()==Datatypes.INT or line[-1].lower()==Datatypes.BOOL \
                        or line[-1].lower()==Datatypes.CHAR):
                        ld_command = 'lw' if exp_datatype.lower() == Datatypes.INT else 'lb'

                        if(line[3] == Operators.Plus or line[3] == Operators.Minus
                                or line[3] == Operators.Mul or Operators.Div):
                            lhs = self.get_register(line[0])
                            if(lhs[1] == 1):
                                offset = self.address_descriptor[line[0]]['offset']
                                self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                                self.update_descriptors(lhs[0], line[0])
                            # x=' '.join(line)

                            # print(self.register)
                            op1 = self.get_register(line[2])
                            if(op1[1] == 1):
                                # print('abcd')
                                offset = self.address_descriptor[line[2]]['offset']
                                self.text_segment += f"{ld_command} {op1[0]}, {-offset}(x8)\n"
                                self.update_descriptors(op1[0], line[2])

                            op2 = self.get_register(line[4])
                            if(op2[1] == 1):
                                # print('efgh')
                                offset = self.address_descriptor[line[4]]['offset']
                                self.text_segment += f"{ld_command} {op2[0]}, {-offset}(x8)\n"
                                self.update_descriptors(op2[0], line[4])
                            

                        if(line[3] == Operators.Plus):
                            self.text_segment += f"add {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.Minus):
                            self.text_segment += f"sub {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.Mul):
                            self.text_segment += f"mul {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.Div):
                            self.text_segment += f"div {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.BitAnd):
                            self.text_segment += f"and {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.BitOr):
                            self.text_segment += f"or {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.BitXor):
                            self.text_segment += f"xor {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.LeftShift):
                            self.text_segment += f"sll {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.RightShift):
                            self.text_segment += f"srl {lhs[0]}, {op1[0]}, {op2[0]}\n"
                            
                        # adding/updating lhs in symbol table
                        if(self.symbol_table[line[2]]['datatype'] == Datatypes.CHAR or
                                self.symbol_table[line[4]]['datatype'] == Datatypes.CHAR):
                            # implicit typecast of char to int
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.CHAR)
                        elif(line[5] == Datatypes.INT):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.INT)
                        elif(line[5] == Datatypes.BOOL):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.BOOL)

                    elif(line[-1].lower()==Datatypes.FLOAT):

                        if(line[3] == Operators.Plus or line[3] == Operators.Minus
                                or line[3] == Operators.Mul or Operators.Div):
                            lhs = self.get_float_register(line[0])
                            if(lhs[1] == 1):
                                offset = self.address_descriptor[line[0]]['offset']
                                # self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                                self.update_float_descriptors(lhs[0], line[0])

                            op1 = self.get_float_register(line[2])
                            if(op1[1] == 1):
                                offset = self.address_descriptor[line[2]]['offset']
                                self.text_segment += f"flw {op1[0]}, {-offset}(x8)\n"
                                self.update_float_descriptors(op1[0], line[2])

                            op2 = self.get_float_register(line[4])
                            if(op2[1] == 1):
                                offset = self.address_descriptor[line[4]]['offset']
                                self.text_segment += f"flw {op2[0]}, {-offset}(x8)\n"
                                self.update_float_descriptors(op2[0], line[4])

                        if(line[3] == Operators.Plus):
                            self.text_segment += f"fadd.s {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.Minus):
                            self.text_segment += f"fsub.s {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.Mul):
                            self.text_segment += f"fmul.s {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        elif(line[3] == Operators.Div):
                            self.text_segment += f"fdiv.s {lhs[0]}, {op1[0]}, {op2[0]}\n"

                        # bitwise operations not supported for floats
                            
                        # adding/updating lhs in symbol table
                        if(line[5] == Datatypes.FLOAT):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.FLOAT)

                elif(self.is_declaration(line)):
                    line = line.split(' ')
                    # CHAR and BOOL
                    if(line[1].lower() == Datatypes.BOOL or line[1].lower() == Datatypes.CHAR):
                        # self.text_segment += f"sw x0, {-self.offset}(x8)\n"
                        self.address_descriptor[line[2]] = {
                            'offset': self.offset,
                            'registers': None
                        }
                        self.offset += 4
                    elif(line[1].lower() == Datatypes.INT or line[1].lower() == Datatypes.FLOAT):
                        self.address_descriptor[line[2]] = {
                            'offset': self.offset,
                            'registers': None
                        }
                        self.offset += 4

                    if(line[1].lower() == Datatypes.INT):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.INT}
                    elif(line[1].lower() == Datatypes.BOOL):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.BOOL}
                    elif(line[1].lower() == Datatypes.CHAR):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.CHAR}
                    elif(line[1].lower() == Datatypes.FLOAT):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.FLOAT}
                    elif(line[1].lower() == Datatypes.STR):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.STR}

                elif(self.is_assignment(line)):
                    line = line.split(' ')
                    constant, datatype = self.is_constant(line[2])

                    if(line[-1].lower()!=Datatypes.FLOAT):
                        lhs = self.get_register(line[0])
                        if(lhs[1] == 1 and line[-1].lower() != Datatypes.STR):
                            # offset = self.address_descriptor[line[0]]['offset']
                            # self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                            self.update_descriptors(lhs[0], line[0])

                        if(constant):
                            # INT
                            if(datatype == Datatypes.INT):
                                self.text_segment += f"addi {lhs[0]}, x0, {line[2]}\n"
                                offset = self.address_descriptor[line[0]]['offset']
                                self.text_segment += f"sw {lhs[0]}, {-offset}(x8)\n"
                                self.update_symbol_table(line[0], Datatypes.INT)
                            elif(datatype == Datatypes.BOOL):
                                self.text_segment += f"addi {lhs[0]}, x0, {line[2]}\n"
                                offset = self.address_descriptor[line[0]]['offset']
                                self.text_segment += f"sb {lhs[0]}, {-offset}(x8)\n"
                                self.update_symbol_table(line[0], Datatypes.INT)
                            # CHAR
                            elif(datatype == Datatypes.CHAR):
                                self.text_segment += f"addi {lhs[0]}, x0, {ord(line[2][1])}\n"
                                offset = self.address_descriptor[line[0]]['offset']
                                self.text_segment += f"sb {lhs[0]}, {-offset}(x8)\n"
                                self.update_symbol_table(line[0], Datatypes.CHAR)
                            # STRING
                            elif(datatype == Datatypes.STR):
                                const = line[2]
                                var = line[0]
                                const = const[1:-1].decode('string_escape')
                                length=len(const)
                                self.data_segment_dict[var] = [".asciz", line[2], self.data_segment_start, length]
                                self.data_segment_start += length+1
                                self.update_symbol_table(var, Datatypes.STR)
                        else:
                            rhs_datatype = line[-1].lower()
                            # INT
                            if(rhs_datatype == Datatypes.INT):
                                rhs_register = None
                                # check if the variable is already in some register
                                for reg in self.register_descriptor:
                                    if(self.register_descriptor[reg] == line[2]):
                                        rhs_register = reg
                                        break
                                if(rhs_register is not None):
                                    self.text_segment += f"add {lhs[0]}, x0, {rhs_register}\n"
                                else:
                                    offset = self.address_descriptor[line[2]]['offset']
                                    self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                            # BOOL and CHAR
                            elif(rhs_datatype == Datatypes.BOOL or rhs_datatype == Datatypes.CHAR):
                                rhs_register = None
                                # check if the variable is already in some register
                                for reg in self.register_descriptor:
                                    if(self.register_descriptor[reg] == line[2]):
                                        rhs_register = reg
                                        break
                                if(rhs_register is not None):
                                    self.text_segment += f"add {lhs[0]}, x0, {rhs_register}\n"
                                else:
                                    offset = self.address_descriptor[line[2]]['offset']
                                    self.text_segment += f"lb {lhs[0]}, {-offset}(x8)\n"
                            # STR
                            elif(rhs_datatype == Datatypes.STR):
                                self.data_segment_dict[line[0]] = [i for i in self.data_segment_dict[line[2]]]
                                self.data_segment_dict[line[0]][2] = self.data_segment_start
                                self.data_segment_start += self.data_segment_dict[line[0]][-1]+1

                            if(rhs_datatype == Datatypes.INT):
                                self.update_symbol_table(
                                    subject=line[0], datatype=Datatypes.INT)
                            elif(rhs_datatype == Datatypes.CHAR):
                                self.update_symbol_table(
                                    subject=line[0], datatype=Datatypes.CHAR)
                            elif(rhs_datatype == Datatypes.BOOL):
                                self.update_symbol_table(
                                    subject=line[0], datatype=Datatypes.BOOL)
                            elif(rhs_datatype == Datatypes.STR):
                                self.update_symbol_table(
                                    subject=line[0], datatype=Datatypes.STR)
                    # FLOAT
                    else:
                        lhs_float = self.get_float_register(line[0])
                        if(lhs_float[1] == 1):
                            self.update_float_descriptors(lhs_float[0], line[0])

                        if(constant):
                            # get an integer register to store the constant
                            lhs_sup = self.get_register(line[0])
                            # if(lhs_sup[1] == 1 and line[-1].lower() != Datatypes.STR):
                                # self.update_descriptors(lhs_sup[0], line[0])

                            upper,mid,lower=self.get_ieee_rep(line[2])
                                
                            self.text_segment += f"lui {lhs_sup[0]}, {upper}\n"
                            self.text_segment += f"addi {lhs_sup[0]}, {lhs_sup[0]}, {mid}\n"
                            self.text_segment += f"addi {lhs_sup[0]}, {lhs_sup[0]}, {lower}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"sw {lhs_sup[0]}, {-offset}(x8)\n"
                            self.text_segment += f"fmv.w.x {lhs_float[0]}, {lhs_sup[0]}\n"
                            self.update_symbol_table(line[0], Datatypes.FLOAT)
                            self.update_float_descriptors(lhs_float[0], line[0])
                        else:
                            rhs_datatype = line[-1].lower()
                            # let this condition be
                            if(rhs_datatype == Datatypes.FLOAT):
                                rhs_register = None
                                # check if the variable is already in some register
                                for reg in self.float_register_descriptor:
                                    if(self.float_register_descriptor[reg] == line[2]):
                                        rhs_register = reg
                                        break
                                if(rhs_register is not None):
                                    self.text_segment += f"fadd.s {lhs_float[0]}, f0, {rhs_register}\n"
                                else:
                                    offset = self.address_descriptor[line[2]]['offset']
                                    self.text_segment += f"flw {lhs_float[0]}, {-offset}(x8)\n"
                            
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.FLOAT)
                            self.update_float_descriptors(lhs_float[0], line[0])

                elif(self.is_unary_assignment(line)):
                    line = line.split(' ')
                    constant, datatype = self.is_constant(line[3])

                    if(line[-1].lower()!=Datatypes.FLOAT):
                        lhs = self.get_register(line[0])
                        if(lhs[1] == 1 and line[-1].lower() != Datatypes.STR):
                            # offset = self.address_descriptor[line[0]]['offset']
                            # self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                            self.update_descriptors(lhs[0], line[0])

                        if(constant):
                            # INT
                            if(datatype == Datatypes.INT or datatype == Datatypes.BOOL):
                                self.text_segment += f"addi {lhs[0]}, x0, {-int(line[3])}\n"
                                offset = self.address_descriptor[line[0]]['offset']
                                self.text_segment += f"sw {lhs[0]}, {-offset}(x8)\n"
                                self.update_symbol_table(line[0], Datatypes.INT)
                            # CHAR
                            elif(datatype == Datatypes.CHAR):
                                self.text_segment += f"addi {lhs[0]}, x0, {-ord(line[3])}\n"
                                offset = self.address_descriptor[line[0]]['offset']
                                self.text_segment += f"sw {lhs[0]}, {-offset}(x8)\n"
                                self.update_symbol_table(line[0], Datatypes.CHAR)
                            # BOOL
                            elif(datatype == Datatypes.BOOL):
                                self.text_segment += f"addi {lhs[0]}, x0, {-ord(line[3])}\n"
                                offset = self.address_descriptor[line[0]]['offset']
                                self.text_segment += f"sb {lhs[0]}, {-offset}(x8)\n"
                                self.update_symbol_table(line[0], Datatypes.BOOL)
                            # should be syntax error for strings
                        else:
                            rhs_datatype = line[-1].lower()
                            # INT
                            if(rhs_datatype == Datatypes.INT):
                                rhs_register = None
                                # check if the variable is already in some register
                                for reg in self.register_descriptor:
                                    if(self.register_descriptor[reg] == line[3]):
                                        rhs_register = reg
                                        break
                                # loading the variable as a negative value
                                if(rhs_register is not None):
                                    self.text_segment += f"sub {lhs[0]}, x0, {rhs_register}\n"
                                else:
                                    offset = self.address_descriptor[line[3]]['offset']
                                    self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                                    self.text_segment += f"sub {lhs[0]}, x0, {lhs[0]}\n"
                                # no need to update descriptor with rhs value
                            # BOOL and CHAR
                            elif(rhs_datatype == Datatypes.BOOL
                                    or rhs_datatype == Datatypes.CHAR):
                                rhs_register = None
                                # check if the variable is already in some register
                                for reg in self.register_descriptor:
                                    if(self.register_descriptor[reg] == line[3]):
                                        rhs_register = reg
                                        break
                                # loading the variable as a negative value
                                if(rhs_register is not None):
                                    self.text_segment += f"sub {lhs[0]}, x0, {rhs_register}\n"
                                else:
                                    offset = self.address_descriptor[line[3]]['offset']
                                    self.text_segment += f"lb {lhs[0]}, {-offset}(x8)\n"
                                    self.text_segment += f"sub {lhs[0]}, x0, {lhs[0]}\n"
                                # no need to update descriptor with rhs value

                            if(rhs_datatype == Datatypes.INT):
                                self.update_symbol_table(
                                    subject=line[0], datatype=Datatypes.INT)
                            elif(rhs_datatype == Datatypes.CHAR):
                                self.update_symbol_table(
                                    subject=line[0], datatype=Datatypes.CHAR)
                            elif(rhs_datatype == Datatypes.BOOL):
                                self.update_symbol_table(
                                    subject=line[0], datatype=Datatypes.BOOL)
                    # FLOAT
                    else:
                        lhs_float = self.get_float_register(line[0])
                        if(lhs_float[1] == 1):
                            self.update_float_descriptors(lhs_float[0], line[0])

                        if(constant):
                            # get an integer register to store the constant
                            lhs_sup = self.get_register(line[0])
                            if(lhs_sup[1] == 1 and line[-1].lower() != Datatypes.STR):
                                self.update_descriptors(lhs_sup[0], line[0])

                            upper,mid,lower=self.get_ieee_rep('-'+line[3])
                                
                            self.text_segment += f"lui {lhs_sup[0]}, {upper}\n"
                            self.text_segment += f"addi {lhs_sup[0]}, {lhs_sup[0]}, {mid}\n"
                            self.text_segment += f"addi {lhs_sup[0]}, {lhs_sup[0]}, {lower}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"sw {lhs_sup[0]}, {-offset}(x8)\n"
                            self.text_segment += f"fmv.w.x {lhs_float[0]}, {lhs_sup[0]}\n"
                            self.update_symbol_table(line[0], Datatypes.FLOAT)
                        else:
                            rhs_datatype = line[-1].lower()
                            # let this condition be
                            if(rhs_datatype == Datatypes.FLOAT):
                                rhs_register = None
                                # check if the variable is already in some register
                                for reg in self.float_register_descriptor:
                                    if(self.float_register_descriptor[reg] == line[3]):
                                        rhs_register = reg
                                        break
                                if(rhs_register is not None):
                                    self.text_segment += f"fsub.s {lhs_float[0]}, f0, {rhs_register}\n"
                                else:
                                    offset = self.address_descriptor[line[3]]['offset']
                                    self.text_segment += f"flw {lhs_float[0]}, {-offset}(x8)\n"
                                    self.text_segment += f"fsub.s {lhs_float[0]}, f0, {lhs_float[0]}\n"
                            
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.FLOAT)

                elif(self.is_if_statement_without_relop(line)):
                    line = line.split(' ')
                    datatype = self.symbol_table[line[1]]['datatype']

                    if(block != blocks[-1]):
                        self.spill_all_registers()

                    if(datatype == Datatypes.INT or datatype == Datatypes.BOOL
                            or datatype == Datatypes.CHAR):
                        lhs = self.get_register(line[1])
                        load_command = 'lw' if datatype == Datatypes.INT else 'lb'
                        if(lhs[1] == 1):
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"{load_command} {lhs[0]}, {-offset}(x8)\n"
                            self.update_descriptors(lhs[0], line[1])

                        self.text_segment += f"bne {lhs[0]}, x0, {line[3]}\n"
                        self.text_segment += f"beq x0, x0, {line[6]}\n"
                    elif(datatype == Datatypes.FLOAT):
                        lhs = self.get_float_register(line[1])
                        if(lhs[1] == 1):
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"flw {lhs[0]}, {-offset}(x8)\n"
                            self.update_float_descriptors(lhs[0], line[1])

                        self.text_segment += f"feq.s {lhs[0]}, f0, {line[6]}\n"
                        self.text_segment += f"beq x0, x0, {line[3]}\n"

                elif(self.is_if_statement_with_relop(line)):
                    line = line.split(' ')
                    datatype = self.symbol_table[line[1]]['datatype']
                    relop = line[2]
                    if(datatype == Datatypes.INT or datatype == Datatypes.BOOL
                            or datatype == Datatypes.CHAR):
                        lhs = self.get_register(line[1])
                        load_command = 'lw' if datatype == Datatypes.INT else 'lb'
                        if(lhs[1] == 1):
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"{load_command} {lhs[0]}, {-offset}(x8)\n"
                            self.update_descriptors(lhs[0], line[1])

                        if(block != blocks[-1]):
                            self.spill_all_registers()

                        if(relop == '=='):
                            self.text_segment += f"beq {lhs[0]}, x0, {line[5]}\n"
                            self.text_segment += f"beq x0, x0, {line[8]}\n"
                        elif(relop == '!='):
                            self.text_segment += f"bne {lhs[0]}, x0, {line[5]}\n"
                            self.text_segment += f"beq x0, x0, {line[8]}\n"
                        elif(relop == '<'):
                            self.text_segment += f"blt {lhs[0]}, x0, {line[5]}\n"
                            self.text_segment += f"beq x0, x0, {line[8]}\n"
                        elif(relop == '>='):
                            self.text_segment += f"bge {lhs[0]}, x0, {line[5]}\n"
                            self.text_segment += f"beq x0, x0, {line[8]}\n"
                        elif(relop == '<='):
                            self.text_segment += f"bge x0, {lhs[0]}, {line[5]}\n"
                            self.text_segment += f"beq x0, x0, {line[8]}\n"
                        elif(relop == '>'):
                            self.text_segment += f"blt x0, {lhs[0]}, {line[5]}\n"
                            self.text_segment += f"beq x0, x0, {line[8]}\n"
                    elif(datatype == Datatypes.FLOAT):
                        lhs = self.get_float_register(line[1])
                        if(lhs[1] == 1):
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"flw {lhs[0]}, {-offset}(x8)\n"
                            self.update_float_descriptors(lhs[0], line[1])

                        if(block != blocks[-1]):
                            self.spill_all_registers()

                        if(relop == '=='):
                            self.text_segment += f"feq.s {lhs[0]}, f0, {line[5]}\n"
                            self.text_segment += f"beq x0, x0, {line[8]}\n"
                        elif(relop == '!='):
                            self.text_segment += f"feq.s {lhs[0]}, f0, {line[8]}\n"
                            self.text_segment += f"beq x0, x0, {line[5]}\n"
                        elif(relop == '<'):
                            self.text_segment += f"flt.s {lhs[0]}, f0, {line[5]}\n"
                            self.text_segment += f"beq x0, x0, {line[8]}\n"
                        elif(relop == '>='):
                            self.text_segment += f"flt.s {lhs[0]}, f0, {line[8]}\n"
                            self.text_segment += f"beq x0, x0, {line[5]}\n"
                        elif(relop == '<='):
                            self.text_segment += f"fle.s {lhs[0]}, f0, {line[5]}\n"
                            self.text_segment += f"beq x0, x0, {line[8]}\n"
                        elif(relop == '>'):
                            self.text_segment += f"fle.s {lhs[0]}, f0 {line[8]}\n"
                            self.text_segment += f"beq x0, x0, {line[5]}\n"

                elif(self.is_input_statement(line)):
                    line = line.split(' ')
                    datatype = self.symbol_table[line[1]]['datatype']
                    # taking integer input
                    if(datatype == Datatypes.INT):
                        self.text_segment += "addi a7, x0, 5\necall\n"
                        offset = self.address_descriptor[line[1]]['offset']
                        self.text_segment += f"sw a0, {-offset}(x8)\n"

                    # taking char input
                    elif(datatype == Datatypes.CHAR):
                        self.text_segment += "addi a7, x0, 12\necall\n"
                        offset = self.address_descriptor[line[1]]['offset']
                        self.text_segment += f"sw a0, {-offset}(x8)\n"

                    # taking float input
                    elif(datatype == Datatypes.FLOAT):
                        self.text_segment += "addi a7, x0, 6\necall\n"
                        offset = self.address_descriptor[line[1]]['offset']
                        self.text_segment += f"sw fa0, {-offset}(x8)\n"

                    # taking string input (INCOMPLETE)
                    
                    elif(datatype == Datatypes.STR):
                        null_str ='"'+ '\\0'*30+'"'
                        self.data_segment_dict[line[1]] = [".asciz", null_str, self.data_segment_start, 31]
                        self.data_segment_start += 32
                        self.update_symbol_table(line[1], Datatypes.STR)

                        total = hex(self.data_segment_dict[line[1]][2])[2:]
                        upper,mid,lower = self.get_ieee_rep(None,total)

                        self.text_segment += f"lui a0, {upper}\n"
                        self.text_segment += f"addi a0, a0, {mid}\n"
                        self.text_segment += f"addi a0, a0, {lower}\n"

                        # self.text_segment += f"la a0, {line[1]}\n"
                        self.text_segment += "addi a1, x0, 30\n" 
                        self.text_segment += "addi a7, x0, 8\necall\n"

                elif(self.is_output_statement(line)):
                    line = line.split(' ')

                    self.spill_all_registers()

                    # printing string
                    if(line[2].lower() == Datatypes.STR):
                        if(self.is_constant(line[1])[0]):
                            if(self.ds_variables.get(line[1]) == None):
                                var = f"ds{len(self.ds_variables)}"
                                self.ds_variables[line[1]] = var
                                self.data_segment_dict[var] = (
                                    ".asciz", line[1])
                            var_name = self.ds_variables[line[1]]
                            total = hex(self.data_segment_dict[var_name][2])[2:]
                            upper,mid,lower = self.get_ieee_rep(None,total)

                            self.text_segment += f"lui a0, {upper}\n"
                            self.text_segment += f"addi a0, a0, {mid}\n"
                            self.text_segment += f"addi a0, a0, {lower}\n"
                        else:
                            total = hex(self.data_segment_dict[line[1]][2])[2:]
                            upper,mid,lower = self.get_ieee_rep(None,total)

                            self.text_segment += f"lui a0, {upper}\n"
                            self.text_segment += f"addi a0, a0, {mid}\n"
                            self.text_segment += f"addi a0, a0, {lower}\n"

                        self.text_segment += "addi a7, x0, 4\necall\n"

                    # printing integers
                    if(line[2].lower() == Datatypes.INT):
                        constant, datatype = self.is_constant(line[1])
                        if(constant):
                            self.text_segment += f"addi a0, x0, {line[1]}\n"
                        else:
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"lw a0, {-offset}(x8)\n"
                        self.text_segment += "addi a7, x0, 1\necall\n"

                    # printing char
                    elif(line[2].lower() == Datatypes.CHAR):
                        constant, datatype = self.is_constant(line[1])
                        if(constant):
                            self.text_segment += f"addi a0, x0, {line[1]}\n"
                        else:
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"lw a0, {-offset}(x8)\n"
                        self.text_segment += "addi a7, x0, 11\necall\n"

                    # printing floats
                    elif(line[2].lower() == Datatypes.FLOAT):
                        constant, datatype = self.is_constant(line[1])
                        if(constant):
                            upper,mid,lower=self.get_ieee_rep(line[1])
                            self.text_segment += f"lui a0, {upper}\n"
                            self.text_segment += f"addi a0, a0, {mid}\n"
                            self.text_segment += f"addi a0, a0, {lower}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"fmv.w.x fa0, a0\n"
                        else:
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"flw fa0, {-offset}(x8)\n"
                        self.text_segment += "addi a7, x0, 2\necall\n"

            # spill all here
            if(block != blocks[-1]):
                self.spill_all_registers()

        # print(self.register_descriptor)
        print(self.address_descriptor)
        # print(self.symbol_table)

        sorted_list = sorted(self.data_segment_dict.items(),key=lambda x: x[1][2])

        for var, (type, value, _, __) in sorted_list:
            self.data_segment += f"{var}:\n\t{type} {value}\n"

        final_asm = self.data_segment+'\n'+self.text_segment

        return final_asm
