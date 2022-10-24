
def postprocess(asm_code):
    mod_asm_code = ''

    for line in asm_code.splitlines():
        if(line.split(' ')[0] == 'li'):
            # li x5, 4
            mod_asm_code += f"addi {line.split(' ')[1]} x0, {line.split(' ')[-1]}\n"
        # elif(line.split(' ')[0] == 'fli'):
        else:
            mod_asm_code += line + '\n'

    return mod_asm_code
