import os
import re
from CodeOptimizer import CodeOptimizer

if __name__ == '__main__':

    # read files from ./test_cases
    script_dir = os.path.dirname(__file__)
    rel_path = "test_cases/add_sub_tac.tac"
    abs_file_path = os.path.join(script_dir, rel_path)

    with open(abs_file_path) as file:
        original_tac_code = file.read()
        tac_code = re.split(r'(\-\-)+(\-)*', original_tac_code)[-1]
        print(tac_code)
        code_generator = CodeOptimizer()
        # starting point of the virtual machine
        code_generator.generate_target_code(tac_code)
