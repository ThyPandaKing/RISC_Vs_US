import struct
import re


def get_ieee_rep(value, hex=None):
    if hex is None:
        hex = ''.join('{:02x}'.format(x)[::-1]
                      for x in struct.pack('f', float(value)))[::-1]
    upper = hex[:5]
    mid = hex[5]
    lower = hex[6:]
    return ('0x'+upper, '0x'+mid, '0x'+lower)


def convert_rep(value):
    value = int(value)
    h = None

    if value < 0:
        h = hex((1 << 32) + value)
    else:
        h = hex(value)

    h = h.lstrip('0x')

    if (len(h) < 8):
        h = '0'*(8-len(h))+h

    upper = h[:5]
    lower_val = int(h[5:], 16)
    val = lower_val//3
    extra = lower_val-3*val
    return ('0x'+upper, val, extra)


def postprocess(asm_code):
    mod_asm_code = ''

    for line in asm_code.splitlines():
        if (line.split(' ')[0] == 'li'):
            # li x5, 4
            reg = line.split(' ')[1][:-1]
            upper, val, extra = convert_rep(line.split(' ')[-1])
            mod_asm_code += f"lui {reg}, {upper}\n"
            mod_asm_code += f"addi {reg}, {reg}, {val}\n"
            mod_asm_code += f"addi {reg}, {reg}, {val}\n"
            mod_asm_code += f"addi {reg}, {reg}, {val}\n"
            mod_asm_code += f"addi {reg}, {reg}, {extra}\n"
        elif (line.split(' ')[0] == 'fli'):
            # fli f3, -247.6
            reg = line.split(' ')[1][:-1]
            upper, mid, lower = get_ieee_rep(line.split(' ')[-1])
            mod_asm_code += f"lui x7, {upper}\n"
            mod_asm_code += f"addi x7, x7, {mid}\n"
            mod_asm_code += f"addi x7, x7, {lower}\n"
            mod_asm_code += f"fmv.w.x {reg}, x7\n"
        else:
            mod_asm_code += line + '\n'

    # mod_asm_code = asm_code + '\n'

    mod_asm_code += f"__END__:\n"
    mod_asm_code += f"nop\n"

    final_asm_code = ''
    enable = False
    for line in mod_asm_code.splitlines():
        if ('.text' in line):
            enable = True
        if (enable):
            final_asm_code += re.sub(r', ', ',', line)
        final_asm_code += '\n'

    final_asm_code = re.sub(r'\n\n', '\n', final_asm_code)

    return final_asm_code
