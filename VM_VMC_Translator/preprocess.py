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

        # Neq
        mod_vm_code = ''
        for line in generator:
            if(line.split(' ')[0] == 'function'):
                if(line.split(' ')[2] == '0' and line.split(' ')[3] == '0'):
                    line = line.split(' ')
                    mod_vm_code += f'function {line[1]} 10 10 {line[4]}\n'
                elif(line.split(' ')[2] == '0'):
                    line = line.split(' ')
                    mod_vm_code += f'function {line[1]} 10 {line[3]} {line[4]}\n'
                elif(line.split(' ')[3] == '0'):
                    line = line.split(' ')
                    mod_vm_code += f'function {line[1]} {line[2]} 10 {line[4]}\n'
                else:
                    mod_vm_code += line + '\n'

            elif (line.split(' ')[0] == Instructions.Neq.value):
                mod_vm_code += f"eq {line.split(' ')[-1]}\n"
                # print(line)
                line = next(generator)
                label = self.get_new_label()
                mod_vm_code += f"if-goto {label}\n"
                line = re.sub(r'#', '__', line)
                prev_label = line.split(' ')[-1]
                mod_vm_code += f"goto {prev_label}\n"
                mod_vm_code += f"label {label}\n"
                # print(label, prev_label)
            elif (line.split(' ')[0] == Instructions.Not.value):
                line = line.split(' ')
                label0 = self.get_new_label()
                label1 = self.get_new_label()
                mod_vm_code += f"push constant 0 {line[-1]}\n"
                mod_vm_code += f"eq {line[-1]}\n"
                mod_vm_code += f"if-goto {label0}\n"
                mod_vm_code += f"push constant 0 {line[-1]}\n"
                mod_vm_code += f"goto {label1}\n"
                mod_vm_code += f"label {label0}\n"
                mod_vm_code += f"push constant 1 {line[-1]}\n"
                mod_vm_code += f"label {label1}\n"
            elif (';' in line):
                mod_vm_code += re.sub(r';.*', '\n', line).strip()
                mod_vm_code += '\n'
            elif ('#' in line):
                mod_vm_code += re.sub(r'#', '__', line)
                mod_vm_code += '\n'
            else:
                mod_vm_code += line + '\n'

        # print(mod_vm_code)
        return mod_vm_code
