import os
from CodeOptimizer import CodeOptimizer

if __name__ == '__main__':

    # read files from ./test_cases
    script_dir = os.path.dirname(__file__)
    rel_path = "test_cases/if_else_tac.tac"
    abs_file_path = os.path.join(script_dir, rel_path)

    with open(abs_file_path) as file:
        tac_code = file.read()

        code_generator = CodeOptimizer()
        # starting point of the virtual machine
        code_generator.generate_target_code(tac_code)
