from enums import *
import re


class Preprocess:
    def __init__(self):
        self.label_index = 0

    def get_new_label(self):
        label = '___L'+str(self.label_index)
        self.label_index += 1
        return label

    def preprocess(self, vm_code):

        generator = (i for i in vm_code.splitlines())

        mod_vm_code = ''
        for line in generator:
            if(line.split(' ')[0] == Instructions.Neq.value):
                mod_vm_code += f"eq {line.split(' ')[-1]}\n"
                line = next(generator)
                label = self.get_new_label()
                mod_vm_code += f"if-goto {label}\n"
                prev_label = line.split(' ')[-1]
                mod_vm_code += f"goto {prev_label}\n"
                mod_vm_code += f"label {label}\n"
            elif(';' in line):
                mod_vm_code += re.sub(r';.*', '\n', line).strip()
                mod_vm_code += '\n'
            elif('#' in line):
                mod_vm_code += re.sub(r'#', '__', line)
                mod_vm_code += '\n'
            else:
                mod_vm_code += line + '\n'

        print(mod_vm_code)
        return mod_vm_code
