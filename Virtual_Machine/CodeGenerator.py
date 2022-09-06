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


class Operators(enum.Enum):
    Plus = '+'
    Minus = '-'
    Mul = '*'
    Div = '/'
    Mod = '%'
    LAnd = '&&'
    LOr = '||'
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


class CodeGenerator:

    available_registers = [
        'x18',
        'x19',
        'x20',
        'x21',
        'x22',
        'x23',
        'x24',
        'x25',
        'x26',
        'x27',
    ]

    default_reg_des = {
        'x18': None,
        'x19': None,
        'x20': None,
        'x21': None,
        'x22': None,
        'x23': None,
        'x24': None,
        'x25': None,
        'x26': None,
        'x27': None
    }

    datatype_sizes = {
        'int': 4,
        'float': 4,
        'char': 1,
        'bool': 1,
    }

    operators = set("+ - * / % && || > < >= <= ! != = ==".split())

    def __init__(self) -> None:
        self.rr_registers_index = 0    # pointer for round robin register fetch
        self.register_descriptor = self.default_reg_des.copy()  # register descriptor
        self.address_descriptor = {}    # address descriptor
        self.text_segment = '.section\n.text\n'
        self.offset = 4     # for stack pointer (spill)

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

    def update_descriptors(self, register, variable):
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

    def is_if_statement(self, instruction) -> bool:
        """
        function that returns true if instruction
        is an if statement
        """
        if(instruction.startswith('if')):
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
        return False

    def is_output_statement(self, instruction) -> bool:
        """
        function that returns true if instruction
        is an output statement
        """
        return False

    def is_constant(self, value) -> tuple[bool, str]:
        """
        function that returns true if value
        is a constant
        """
        # check character
        if value[0] == '\'':
            return (True, 'string')
        # check int
        if value.isdigit():
            return (True, 'int')
        # check float
        if self.isfloat(value):
            return (True, 'float')
        # check string
        if value[0] == '\"' and value[-1] == '\"':
            return (True, 'char')
        # not a constant
        return (False, '')

    def get_register(self, variable) -> tuple[str, int]:
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

                elif(self.is_binary_arithmetic(line)):
                    line = line.split(' ')
                    if(line[3] == Operators.Plus.value):
                        lhs = self.get_register(line[0])
                        if(lhs[1] == 1):
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                        self.update_descriptors(lhs[0], line[0])

                        op1 = self.get_register(line[2])
                        if(op1[1] == 1):
                            offset = self.address_descriptor[line[2]]['offset']
                            self.text_segment += f"lw {op1[0]}, {-offset}(x8)\n"
                        self.update_descriptors(op1[0], line[2])

                        op2 = self.get_register(line[4])
                        if(op2[1] == 1):
                            offset = self.address_descriptor[line[4]]['offset']
                            self.text_segment += f"lw {op2[0]}, {-offset}(x8)\n"
                        self.update_descriptors(op2[0], line[4])

                        self.text_segment += f"add {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.Minus.value):
                        lhs = self.get_register(line[0])
                        if(lhs[1] == 1):
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                        self.update_descriptors(lhs[0], line[0])

                        op1 = self.get_register(line[2])
                        if(op1[1] == 1):
                            offset = self.address_descriptor[line[2]]['offset']
                            self.text_segment += f"lw {op1[0]}, {-offset}(x8)\n"
                        self.update_descriptors(op1[0], line[2])

                        op2 = self.get_register(line[4])
                        if(op2[1] == 1):
                            offset = self.address_descriptor[line[4]]['offset']
                            self.text_segment += f"lw {op2[0]}, {-offset}(x8)\n"
                        self.update_descriptors(op2[0], line[4])

                        self.text_segment += f"sub {lhs[0]}, {op1[0]}, {op2[0]}\n"

                    elif(line[3] == Operators.Mul.value):
                        lhs = self.get_register(line[0])
                        if(lhs[1] == 1):
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                        self.update_descriptors(lhs[0], line[0])

                        op1 = self.get_register(line[2])
                        if(op1[1] == 1):
                            offset = self.address_descriptor[line[2]]['offset']
                            self.text_segment += f"lw {op1[0]}, {-offset}(x8)\n"
                        self.update_descriptors(op1[0], line[2])

                        op2 = self.get_register(line[4])
                        if(op2[1] == 1):
                            offset = self.address_descriptor[line[4]]['offset']
                            self.text_segment += f"lw {op2[0]}, {-offset}(x8)\n"
                        self.update_descriptors(op2[0], line[4])

                        self.text_segment += f"mul {lhs[0]}, {op1[0]}, {op2[0]}\n"
                    
                    elif(line[3] == Operators.Div.value):
                        lhs = self.get_register(line[0])
                        if(lhs[1] == 1):
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                        self.update_descriptors(lhs[0], line[0])

                        op1 = self.get_register(line[2])
                        if(op1[1] == 1):
                            offset = self.address_descriptor[line[2]]['offset']
                            self.text_segment += f"lw {op1[0]}, {-offset}(x8)\n"
                        self.update_descriptors(op1[0], line[2])

                        op2 = self.get_register(line[4])
                        if(op2[1] == 1):
                            offset = self.address_descriptor[line[4]]['offset']
                            self.text_segment += f"lw {op2[0]}, {-offset}(x8)\n"
                        self.update_descriptors(op2[0], line[4])

                        self.text_segment += f"div {lhs[0]}, {op1[0]}, {op2[0]}\n"

                elif(self.is_declaration(line)):
                    line = line.split(' ')
                    if(line[1].lower() == Datatypes.INT.value or line[1].lower() == Datatypes.BOOL.value):
                        self.text_segment += f"sw x0, {-self.offset}(x8)\n"
                        self.address_descriptor[line[2]] = {
                            'offset': self.offset,
                            'registers': None
                        }
                        self.offset += 4

                elif(self.is_assignment(line)):
                    line = line.split(' ')
                    constant, datatype = self.is_constant(line[2])
                    lhs = self.get_register(line[0])
                    if(lhs[1] == 1):
                        offset = self.address_descriptor[line[0]]['offset']
                        self.text_segment += f"lw {lhs[0]}, {-offset}(x8)\n"
                    self.update_descriptors(lhs[0], line[0])

                    if(constant):
                        if(datatype == Datatypes.INT.value or datatype == Datatypes.BOOL.value):
                            self.text_segment += f"addi {lhs[0]}, x0, {line[2]}\n"
                            offset = self.address_descriptor[line[0]]['offset']
                            self.text_segment += f"sw {lhs[0]}, {-offset}(x8)\n"

        print(self.text_segment)
        print(self.register_descriptor)
