with open("asmout.o", "r") as fp:
    asm_code = fp.readlines()

asm_code = [i.strip() for i in asm_code]

with open("program.o", "w") as fp:
    fp.write("program(")
    for i, line in enumerate(asm_code):
        val = hex(int(line, base=2))
        if i == len(asm_code) - 1:
            fp.write(f"{val}")
        else:
            fp.write(f"{val},")
    fp.write(")")