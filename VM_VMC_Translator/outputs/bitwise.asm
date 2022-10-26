.global main
main:

addi x2, x8, -1284
addi x5, x0, 6
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -4(x8)
addi x5, x0, 5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -8(x8)
lw x5, -4(x8)
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -8(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
and x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
sw x5, -12(x8)
lw x5, -12(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
addi a7, x0, 1
ecall
addi x5, x0, 45
sb x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lb x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
addi a7, x0, 11
ecall
addi x5, x0, 1
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -4(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
sll x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
addi a7, x0, 1
ecall
