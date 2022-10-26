.global main
main:

addi x2, x8, -1284
addi x5, x0, 0
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
LOOP:
addi x5, x0, 0
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -8(x8)
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
beq x5, x0, END
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
add x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
sw x5, -4(x8)
addi x5, x0, 1
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -8(x8)
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
sw x5, -8(x8)
beq x0, x0, LOOP
END:
lw x5, -4(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
addi a7, x0, 1
ecall
