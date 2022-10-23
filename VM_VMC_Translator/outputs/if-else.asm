.global main
addi x2, x8, -1284
main:

li x5, 4
sw x5, 0(x2)
addi x2, x2, -4

li x5, 4
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -4(x8)
lw x5, -4(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
sub x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
beq x5, x0, L
li x5, 11
sw x5, 0(x2)
addi x2, x2, -4

beq x0, x0, L0
L:
li x5, 13
sw x5, 0(x2)
addi x2, x2, -4

L0:
