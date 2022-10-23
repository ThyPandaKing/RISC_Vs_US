import sys
import os
from vm import VM

if __name__ == '__main__':
    script_dir = os.path.dirname(__file__)
    rel_path = sys.argv[1]
    abs_file_path = os.path.join(script_dir, rel_path)

    with open(abs_file_path) as file:
        vm_code = file.read()

        asm_generator = VM()
        # starting point of the virtual machine
        asm_generator.generate_target_code(vm_code)
