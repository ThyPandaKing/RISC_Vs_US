.global main
addi x2, x8, -1284
main:

addi x5, x0, 1
sb x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lb x5, 0(x2)
sb x5, -4(x8)
lb x5, -4(x8)
sb x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
addi x5, x0, 0
lb x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
addi a7, x0, 4
ecall
