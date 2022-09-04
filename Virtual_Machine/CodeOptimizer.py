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
        self.blocks = []

    def generate_target_code(self, tac_code) -> None:
        """
        basic blocks will be built here
        by reading the tac code
        """

        block_lines = ''
        for line in tac_code.splitlines():
            if(line.startswith('.global')):
                block_lines += line
            elif line.strip() == '' or line.strip() == 'end:':
                pass
            elif line.startswith('if') or line.startswith('goto') \
                    or line.startswith('return'):
                block_lines += line
                self.blocks.append(block_lines)
                block_lines = ''
            elif line.endswith(':'):
                if(block_lines.strip() != ''):
                    self.blocks.append(block_lines)
                block_lines = line
            else:
                block_lines += line
            block_lines += '\n'

        if(block_lines.strip() != ''):
            self.blocks.append(block_lines)

        # printing the generated blocks
        print(*self.blocks, sep='\n----------------\n')

        self.optimize()

    def optimize(self) -> None:
        """
        all optimizations will occur here
        for now, just pass the blocks as it is
        """

        register_allocation = CodeGenerator()
        register_allocation.main(self.blocks)
