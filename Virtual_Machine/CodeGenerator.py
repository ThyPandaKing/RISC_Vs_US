"""
- Structure of address descriptor:

    self.address_descriptor = {
        "var_name": {
            "offset": None,
            "registers": None
        }
    }

- main() is the starting point of code generation
- stack pointer is x2 register
- frame pointer is x8 register
"""


import enum
from typing import final

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

    datatype_sizes = {
        'int': 4,
        'float': 4,
        'char': 1,
        'bool': 1,
    }

    operators = set("+ - * / % & | ^ << >> && || > < >= <= ! != = ==".split())
    relational_operators = set("> < >= <= != ==".split())

    def __init__(self) -> None:
        self.rr_registers_index = 0    # pointer for round robin register fetch
        self.register_descriptor = self.default_reg_des.copy()  # register descriptor
        self.address_descriptor = {}    # address descriptor
        self.text_segment = '.section\n.text\n'
        self.data_segment = '.section\n.data\n'
        self.data_segment_dict = {}
        self.ds_variables = {}
        self.offset = 4     # for stack pointer (spill)
        self.symbol_table = {}      # a custom symbol table

    def get_data_type(self, instruction) -> str:
        """
        function to get the data type
        of an instruction
        """
        return instruction.split(' ')[-1].lower()

    def is_binary_arithmetic(self, instruction) -> bool:
        """
        function that returns true if instruction
        is a binary arithmetic instruction
        """
        if(len(instruction.split(' ')) != 6):
            return False
        if(len(set(instruction.split(' ')).intersection(self.operators)) != 2):
            return False
        return True

    def update_descriptors(self, register, variable) -> None:
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

    def is_declaration(self, instruction) -> bool:
        """
        returns true if the instruction is a
        variable declaration instruction
        """
        split = instruction.split(' ')
        if(len(split) != 3 or split[0] != '-'):
            return False
        return True

    def is_assignment(self, instruction) -> bool:
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

    def is_unary_assignment(self, instruction) -> bool:
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

    def is_if_statement_with_relop(self, instruction) -> bool:
        """
        function that returns true if instruction
        is an if statement
        """
        if(instruction.startswith('if') and len(set(instruction.split(' ')).intersection(self.relational_operators)) != 0):
            return True
        return False

    def is_if_statement_without_relop(self, instruction) -> bool:
        """
        function that returns true if instruction
        is an if statement
        """
        if(instruction.startswith('if') and not self.is_if_statement_with_relop(instruction)):
            return True
        return False

    def is_goto_statement(self, instruction):
        """
        function that returns true if instruction
        is a goto statement
        """
        if(instruction.startswith('GOTO')):
            return True
        return False

    def is_return_statement(self, instruction) -> bool:
        """
        function that returns true if instruction
        is a return statement
        """
        if(instruction.startswith('return')):
            return True
        return False

    def is_input_statement(self, instruction) -> bool:
        """
        function that returns true if instruction
        is a user input statement
        """
        if(instruction.startswith('input')):
            return True
        return False

    def is_output_statement(self, instruction) -> bool:
        """
        function that returns true if instruction
        is an output statement
        """
        if(instruction.startswith('print')):
            return True
        return False

    def isfloat(self, num) -> bool:
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

    def is_constant(self, value) -> "tuple[bool, str]":
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

    def get_register(self, variable) -> "tuple[str, int]":
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

    def spill_register(self, register) -> None:
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

    def update_symbol_table(self, subject, datatype) -> None:
        """
        updates the symbol table
        """
        if(self.symbol_table[subject] is not None):
            self.symbol_table[subject]['datatype'] = datatype
        else:
            self.symbol_table[subject] = {
                'datatype': datatype
            }

    def spill_all_registers(self) -> None:
        """
        function that spills all registers
        at the end of each block
        """

        self.text_segment += '# ---- end of block ----\n'
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

        self.text_segment += '# ---- end of spill ----\n'

        self.register_descriptor = self.default_reg_des.copy()

    def main(self, blocks) -> None:
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

                    ld_command = 'lw' if exp_datatype == Datatypes.INT else 'lb'

                    if(line[3] == Operators.Plus.value or line[3] == Operators.Minus.value
                            or line[3] == Operators.Mul.value or Operators.Div.value):
                        lhs = self.get_register(line[0])
                        if(lhs[1] == 1):
                            offset = self.address_descriptor[line[0]]['offset']
                            # self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                            self.update_descriptors(lhs[0], line[0])

                        op1 = self.get_register(line[2])
                        if(op1[1] == 1):
                            offset = self.address_descriptor[line[2]]['offset']
                            self.text_segment += f"{ld_command} {op1[0]}, {-offset}(x8)\n"
                            self.update_descriptors(op1[0], line[2])

                        op2 = self.get_register(line[4])
                        if(op2[1] == 1):
                            offset = self.address_descriptor[line[4]]['offset']
                            self.text_segment += f"{ld_command} {op2[0]}, {-offset}(x8)\n"
                            self.update_descriptors(op2[0], line[4])

                    if(line[3] == Operators.Plus.value):
                        self.text_segment += f"add {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.Minus.value):
                        self.text_segment += f"sub {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.Mul.value):
                        self.text_segment += f"mul {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.Div.value):
                        self.text_segment += f"div {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.BitAnd.value):
                        self.text_segment += f"and {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.BitOr.value):
                        self.text_segment += f"or {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.BitXor.value):
                        self.text_segment += f"xor {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.LeftShift.value):
                        self.text_segment += f"sll {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.RightShift.value):
                        self.text_segment += f"srl {lhs[0]}, {op1[0]}, {op2[0]}\n"
                        
                    # adding/updating lhs in symbol table
                    if(self.symbol_table[line[2]]['datatype'] == Datatypes.CHAR.value or
                            self.symbol_table[line[4]]['datatype'] == Datatypes.CHAR.value):
                        # implicit typecast of char to int
                        self.update_symbol_table(
                            subject=line[0], datatype=Datatypes.CHAR)
                    elif(line[5] == Datatypes.INT.value):
                        self.update_symbol_table(
                            subject=line[0], datatype=Datatypes.INT)
                    elif(line[5] == Datatypes.BOOL.value):
                        self.update_symbol_table(
                            subject=line[0], datatype=Datatypes.BOOL)

                elif(self.is_declaration(line)):
                    line = line.split(' ')
                    # CHAR and BOOL
                    if(line[1].lower() == Datatypes.BOOL.value or line[1].lower() == Datatypes.CHAR.value):
                        # self.text_segment += f"sw x0, {-self.offset}(x8)\n"
                        self.address_descriptor[line[2]] = {
                            'offset': self.offset,
                            'registers': None
                        }
                        self.offset += 4
                    elif(line[1].lower() == Datatypes.INT.value or line[1].lower() == Datatypes.FLOAT.value):
                        self.address_descriptor[line[2]] = {
                            'offset': self.offset,
                            'registers': None
                        }
                        self.offset += 4

                    if(line[1].lower() == Datatypes.INT.value):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.INT}
                    elif(line[1].lower() == Datatypes.BOOL.value):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.BOOL}
                    elif(line[1].lower() == Datatypes.CHAR.value):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.CHAR}
                    elif(line[1].lower() == Datatypes.FLOAT.value):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.FLOAT}
                    elif(line[1].lower() == Datatypes.STR.value):
                        self.symbol_table[line[2]] = {
                            'datatype': Datatypes.STR}

                elif(self.is_assignment(line)):
                    line = line.split(' ')
                    constant, datatype = self.is_constant(line[2])
                    lhs = self.get_register(line[0])
                    if(lhs[1] == 1 and line[-1].lower() != Datatypes.STR.value):
                        # offset = self.address_descriptor[line[0]]['offset']
                        # self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                        self.update_descriptors(lhs[0], line[0])

                    if(constant):
                        # INT
                        if(datatype == Datatypes.INT.value):
                            self.text_segment += f"addi {lhs[0]}, x0, {line[2]}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"sw {lhs[0]}, {-offset}(x8)\n"
                            self.update_symbol_table(line[0], Datatypes.INT)
                        elif(datatype == Datatypes.BOOL.value):
                            self.text_segment += f"addi {lhs[0]}, x0, {line[2]}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"sb {lhs[0]}, {-offset}(x8)\n"
                            self.update_symbol_table(line[0], Datatypes.INT)
                        # CHAR
                        elif(datatype == Datatypes.CHAR.value):
                            self.text_segment += f"addi {lhs[0]}, x0, {ord(line[2][1])}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"sb {lhs[0]}, {-offset}(x8)\n"
                            self.update_symbol_table(line[0], Datatypes.CHAR)
                        # STRING
                        elif(datatype == Datatypes.STR.value):
                            const = line[2]
                            var = line[0]
                            self.data_segment_dict[var] = (".asciz", const)
                            self.update_symbol_table(var, Datatypes.STR)
                    else:
                        rhs_datatype = line[-1].lower()
                        # INT
                        if(rhs_datatype == Datatypes.INT.value):
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
                        elif(rhs_datatype == Datatypes.BOOL.value or rhs_datatype == Datatypes.CHAR.value):
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
                        elif(rhs_datatype == Datatypes.STR.value):
                            self.data_segment_dict[line[0]
                                                   ] = self.data_segment_dict[line[2]]

                        if(rhs_datatype == Datatypes.INT.value):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.INT)
                        elif(rhs_datatype == Datatypes.CHAR.value):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.CHAR)
                        elif(rhs_datatype == Datatypes.BOOL.value):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.BOOL)
                        elif(rhs_datatype == Datatypes.STR.value):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.STR)

                elif(self.is_unary_assignment(line)):
                    line = line.split(' ')
                    constant, datatype = self.is_constant(line[3])
                    lhs = self.get_register(line[0])
                    if(lhs[1] == 1 and line[-1].lower() != Datatypes.STR.value):
                        # offset = self.address_descriptor[line[0]]['offset']
                        # self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                        self.update_descriptors(lhs[0], line[0])

                    if(constant):
                        # INT
                        if(datatype == Datatypes.INT.value or datatype == Datatypes.BOOL.value):
                            self.text_segment += f"addi {lhs[0]}, x0, {-int(line[3])}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"sw {lhs[0]}, {-offset}(x8)\n"
                            self.update_symbol_table(line[0], Datatypes.INT)
                        # CHAR
                        elif(datatype == Datatypes.CHAR.value):
                            self.text_segment += f"addi {lhs[0]}, x0, {-ord(line[3])}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"sw {lhs[0]}, {-offset}(x8)\n"
                            self.update_symbol_table(line[0], Datatypes.CHAR)
                        # BOOL
                        elif(datatype == Datatypes.BOOL.value):
                            self.text_segment += f"addi {lhs[0]}, x0, {-ord(line[3])}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"sb {lhs[0]}, {-offset}(x8)\n"
                            self.update_symbol_table(line[0], Datatypes.BOOL)
                        # should be syntax error for strings
                    else:
                        rhs_datatype = line[-1].lower()
                        # INT
                        if(rhs_datatype == Datatypes.INT.value):
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
                        elif(rhs_datatype == Datatypes.BOOL.value
                                or rhs_datatype == Datatypes.CHAR.value):
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

                        if(rhs_datatype == Datatypes.INT.value):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.INT)
                        elif(rhs_datatype == Datatypes.CHAR.value):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.CHAR)
                        elif(rhs_datatype == Datatypes.BOOL.value):
                            self.update_symbol_table(
                                subject=line[0], datatype=Datatypes.BOOL)

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

                elif(self.is_input_statement(line)):
                    line = line.split(' ')
                    datatype = self.symbol_table[line[1]]
                    # taking integer input
                    if(datatype == Datatypes.INT.value):
                        self.text_segment += "li a7, 5\necall\n"
                        offset = self.address_descriptor[line[1]]['offset']
                        self.text_segment += f"sw a0, {-offset}(x8)\n"

                    # taking char input
                    elif(datatype == Datatypes.CHAR.value):
                        self.text_segment += "li a7, 12\necall\n"
                        offset = self.address_descriptor[line[1]]['offset']
                        self.text_segment += f"sw a0, {-offset}(x8)\n"

                    # taking float input
                    elif(datatype == Datatypes.FLOAT.value):
                        self.text_segment += "li a7, 6\necall\n"
                        offset = self.address_descriptor[line[1]]['offset']
                        self.text_segment += f"sw fa0, {-offset}(x8)\n"

                    # taking string input (INCOMPLETE)
                    # elif(datatype == Datatypes.STRING.value):
                    #     self.text_segment += f"la a0, {line[1]}\n"
                    #     self.text_segment += "li a7, 8\necall\n"

                elif(self.is_output_statement(line)):
                    line = line.split(' ')

                    self.spill_all_registers()

                    # printing string
                    if(line[2].lower() == Datatypes.STR.value):
                        if(self.is_constant(line[1])[0]):
                            if(self.ds_variables.get(line[1]) == None):
                                var = f"ds{len(self.ds_variables)}"
                                self.ds_variables[line[1]] = var
                                # self.data_segment += f"{var}:\t.ascii {line[1]}\n"
                                self.data_segment_dict[var] = (
                                    ".asciz", line[1])
                            var_name = self.ds_variables[line[1]]
                            self.text_segment += f"la a0, {var_name}\n"
                        else:
                            self.text_segment += f"la a0, {line[1]}\n"

                        self.text_segment += "li a7, 4\necall\n"

                    # printing integers
                    if(line[2].lower() == Datatypes.INT.value):
                        constant, datatype = self.is_constant(line[1])
                        if(constant):
                            self.text_segment += f"li a0, {line[1]}\n"
                        else:
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"lw a0, {-offset}(x8)\n"
                        self.text_segment += "li a7, 1\necall\n"

                    # printing char
                    elif(line[2].lower() == Datatypes.CHAR.value):
                        constant, datatype = self.is_constant(line[1])
                        if(constant):
                            self.text_segment += f"li a0, {line[1]}\n"
                        else:
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"lw a0, {-offset}(x8)\n"
                        self.text_segment += "li a7, 11\necall\n"

                    # printing floats
                    elif(line[2].lower() == Datatypes.FLOAT.value):
                        constant, datatype = self.is_constant(line[1])
                        if(constant):
                            self.text_segment += f"li fa0, {line[1]}\n"
                        else:
                            offset = self.address_descriptor[line[1]]['offset']
                            self.text_segment += f"lw fa0, {-offset}(x8)\n"
                        self.text_segment += "li a7, 2\necall\n"

            # spill all here
            # if(block != blocks[-1]):
                # self.spill_all_registers()

        # print(self.register_descriptor)
        print(self.address_descriptor)
        # print(self.symbol_table)

        for var, (type, value) in self.data_segment_dict.items():
            self.data_segment += f"{var}:\n\t{type} {value}\n"

        final_asm = self.data_segment+'\n'+self.text_segment

        return final_asm
