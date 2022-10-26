.global main
addi x2, x8, -1284
main:

fli f3, 4.8
fsw f3, 0(x2)
addi x2, x2, -4

fli f3, -5.5
fsw f3, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
flw x5, 0(x2)
fsw x5, -4(x8)
flw f3, -4.0(x8)
fsw f3, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
flw x5, 0(x2)
addi x2, x2, 4
flw x6, 0(x2)
fsub.s x5, x5, x6
fsw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
flw f3, 0(x2)
fsub.s f3, f0, f3
flt.s f3, f0, L
addi x5, x0, 11
sw x5, 0(x2)
addi x2, x2, -4

beq x0, x0, L0
L:
addi x5, x0, 13
sw x5, 0(x2)
addi x2, x2, -4

L0:
