.global main
main:

addi x2, x8, -1284
addi x5, x0, 48
sb x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lb x5, 0(x2)
sb x5, -648(x8)
addi x5, x0, 49
sb x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lb x5, 0(x2)
sb x5, -4(x8)
lb x5, -648(x8)
sb x5, 0(x2)
addi x2, x2, -4

lb x5, -4(x8)
sb x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lb x5, 0(x2)
addi x2, x2, 4
lb x6, 0(x2)
add x5, x5, x6
sb x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lb x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
addi a7, x0, 11
ecall
