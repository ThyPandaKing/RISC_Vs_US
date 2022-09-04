from CodeGenerator import CodeGenerator


class CodeOptimizer:

    arithmetic_operators = set("+ - * / % && || > < >= <= ! != = ==".split())

    datatype_sizes = {
        'int': 4,
        'float': 4,
        'char': 1,
        'bool': 4,
    }

    def __init__(self):
        pass

    def generate_target_code(self, tac_code) -> None:
        """
        basic blocks will be built here
        by reading the tac code
        """

        self.optimize([])

    def optimize(self, blocks) -> None:
        """
        all optimizations will occur here
        for now, just pass the blocks as it is
        """

        register_allocation = CodeGenerator()
        register_allocation.main(blocks)
