"""
- Structure of address descriptor:

    self.address_descriptor = {
        "var_name": {
            "offset": None,
            "registers": []
        }
    }

- main() is the starting point of code generation
"""


import re


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
        self.text_segment = '.section .text\n'

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

    def is_constant(self, value) -> bool:
        """
        function that returns true if value
        is a constant
        """
        # check character
        if value[0] == '\'':
            return True
        # check int
        if value.isdigit():
            return True
        # check float
        if self.isfloat(value):
            return True
        # check string
        if value[0] == '\"' and value[-1] == '\"':
            return True
        # not a constant
        return False

    def get_register(self, variable) -> str:
        """
        returns a register based on
        the allocation algorithm
        """

        for reg in self.register_descriptor:
            if(self.register_descriptor[reg] == variable):
                return reg

        for reg in self.register_descriptor:
            if(self.register_descriptor[reg] is None):
                return reg

        register = self.available_registers[self.rr_registers_index]
        self.spill_register(register)
        self.rr_registers_index = (
            self.rr_registers_index+1) % len(self.available_registers)

        return register

    def spill_register(self, register) -> None:
        """
        handles the logic of spilling
        a register
        """

        variable = self.register_descriptor[register]

        if(self.address_descriptor[variable] is not None):
            try:
                self.address_descriptor[variable]["registers"].remove(register)
                if(len(self.address_descriptor[variable]["registers"]) == 0):
                    self.text_segment += ''
            except KeyError or ValueError:
                print("Error: register not present in address descriptor")

    def main(self, blocks) -> None:
        """
        the starting point of register allocation
        """

        # TODO: complete this
        for block in blocks:
            for line in block:
                if(line.endswith(':')):
                    line = line.replace('#', '__')
                    self.text_segment += line+'\n'
                elif(line.startswith('.global')):
                    self.text_segment += line+'\n'
                # elif()
