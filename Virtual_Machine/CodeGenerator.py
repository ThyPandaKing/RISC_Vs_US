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

    arithmetic_operators = set("+ - * / % && || > < >= <= ! != = ==".split())

    def __init__(self) -> None:
        self.rr_registers_index = 0    # pointer for round robin register fetch
        self.register_descriptor = self.default_reg_des.copy()  # register descriptor
        self.address_descriptor = {}    # address descriptor

    def get_data_type(self, instruction) -> str:
        """
        function to get the data type
        of an instruction
        """
        return ''

    def is_binary_arithmetic(self, instruction) -> bool:
        """
        function that returns true if instruction
        is a binary arithmetic instruction
        """
        return False

    def is_assignment(self, instruction) -> bool:
        """
        function that returns true if instruction
        is an assignment instruction
        """
        return False

    def is_if_statement(self, instruction) -> bool:
        """
        function that returns true if instruction
        is an if statement
        """
        return False

    def is_return_statement(self, instruction) -> bool:
        """
        function that returns true if instruction
        is a return statement
        """
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
        return False

    def get_register(self, variable) -> str:
        """
        returns a register based on
        the allocation algorithm
        """
        return ''

    def spil_register(self, register) -> None:
        """
        handles the logic of spilling
        a register
        """
        pass

    def main(self, blocks) -> None:
        """
        the starting point of code generation
        """
        pass
