import re
from CodeGenerator import CodeGenerator


class CodeOptimizer:

    operators = set("+ - * / % && || > < >= <= ! != = ==".split())
    relational_operators = set("> < >= <= != ==".split())

    def __init__(self):
        self.blocks = []
        self.label_index = 100
        self.temp_index = 0
        self.register_allocation = CodeGenerator()

    def is_condition_statement(self, instruction):
        """
        returns true if the given instruction
        is a condition statement
        """
        split = instruction.split(' ')
        if(len(split) != 6):
            return False
        if(len(set(split).intersection(self.relational_operators)) == 1 and
                split[1] == '='):
            return True
        return False

    def get_new_temp(self) -> str:
        temp = '@_t'+str(self.temp_index)
        self.temp_index += 1
        return temp

    def get_new_label(self) -> str:
        label = '___L'+str(self.label_index)
        self.label_index += 1
        return label

    def generate_target_code(self, tac_code) -> None:
        """
        basic blocks will be built here
        by reading the tac code
        """

        modified_tac = ''
        for line in tac_code.splitlines():
            if(self.is_condition_statement(line)):
                relop = line.split()[3]
                temp = line.split()[0]
                t0 = self.get_new_temp()
                left_operand = line.split()[2]
                right_operand = line.split()[4]
                # if(self.register_allocation.is_constant(left_operand)):
                #     t1 = self.get_new_temp()
                #     replacement_str += f"{t1} = {left_operand}\n"
                replacement_str = f"{t0} = {left_operand} - {right_operand} INT\n"
                l0 = self.get_new_label()
                l1 = self.get_new_label()
                l2 = self.get_new_label()
                replacement_str += f"if {t0} {relop} 0 GOTO {l0} else GOTO {l1}\n"
                replacement_str += f"{l0}:\n"
                replacement_str += f"{temp} = 1 INT\n"
                replacement_str += f"GOTO {l2}\n"
                replacement_str += f"{l1}:\n"
                replacement_str += f"{temp} = 0 INT\n"
                replacement_str += f"{l2}:\n"
                modified_tac += replacement_str
            else:
                modified_tac += line+'\n'

        declared_temps=[]
        final_tac = ''
        for line in modified_tac.splitlines():
            if(re.search(r'^@.+', line) is not None and line.split(' ')[0] not in declared_temps):
                final_tac += f"- {line.split(' ')[-1]} {line.split(' ')[0]}\n"
                declared_temps.append(line.split(' ')[0])
            final_tac += line+'\n'

        print(final_tac)

        block_lines = ''
        for line in final_tac.splitlines():
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
        # print(*self.blocks, sep='\n----------------\n')

        self.optimize()

    def optimize(self) -> None:
        """
        all optimizations will occur here
        for now, just pass the blocks as it is
        """

        self.register_allocation.main(self.blocks)
