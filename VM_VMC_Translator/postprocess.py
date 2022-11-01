from ast import mod
from atexit import register
import struct


def convert_rep(value):
    value = int(value)
    h = None

    if value < 0:
        h = hex((1 << 32) + value)
    else:
        h = hex(value)

    h = h.lstrip('0x')

    if(len(h) < 8):
        h = '0'*(8-len(h))+h

    upper = h[:5]
    lower_val = int(h[5:], 16)
    val = lower_val//3
    extra = lower_val-3*val
    return ('0x'+upper, val, extra)


def postprocess(asm_code):
    mod_asm_code = ''

    for line in asm_code.splitlines():
        if(line.split(' ')[0] == 'li'):
            # li x5, 4
            reg = line.split(' ')[1][:-1]
            upper, val, extra = convert_rep(line.split(' ')[-1])
            mod_asm_code += f"lui {reg}, {upper}\n"
            mod_asm_code += f"addi {reg}, {reg}, {val}\n"
            mod_asm_code += f"addi {reg}, {reg}, {val}\n"
            mod_asm_code += f"addi {reg}, {reg}, {val}\n"
            mod_asm_code += f"addi {reg}, {reg}, {extra}\n"
            # elif(line.split(' ')[0] == 'fli'):
        else:
            mod_asm_code += line + '\n'

    return mod_asm_code
