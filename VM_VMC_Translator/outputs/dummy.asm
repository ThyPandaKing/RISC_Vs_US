.global main
main:

addi x2, x8, -1284
addi x5, x0, -1
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -648(x8)
lw x5, -648(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -4(x8)
addi x5, x0, 1
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -652(x8)
lw x5, -652(x8)
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -4(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
blt x5, x6, ___CL0
addi x7, x0, 0
beq x0, x0, ___CL1
___CL0:
addi x7, x0, 1
___CL1:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
sw x5, -656(x8)
addi x5, x0, 1
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -656(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
beq x5, x6, ___CL2
addi x7, x0, 0
beq x0, x0, ___CL3
___CL2:
addi x7, x0, 1
___CL3:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
beq x5, x0, __L2
beq x0, x0, __L1
__L1:
addi x5, x0, 11
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -660(x8)
lw x5, -660(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -8(x8)
beq x0, x0, __L0
__L2:
addi x5, x0, 2
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -648(x8)
lw x5, -648(x8)
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -4(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
beq x5, x6, ___CL4
addi x7, x0, 0
beq x0, x0, ___CL5
___CL4:
addi x7, x0, 1
___CL5:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
sw x5, -664(x8)
addi x5, x0, 1
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -664(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
beq x5, x6, ___CL6
addi x7, x0, 0
beq x0, x0, ___CL7
___CL6:
addi x7, x0, 1
___CL7:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
addi a7, x0, 1
ecall
addi x2, x2, 4
lw x5, 0(x2)
beq x5, x0, __L4
beq x0, x0, __L3
__L3:
addi x5, x0, 22
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -668(x8)
lw x5, -668(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -8(x8)
beq x0, x0, __L0
__L4:
addi x5, x0, 33
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -672(x8)
lw x5, -672(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -8(x8)
__L0:
addi x5, x0, 38
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -676(x8)
lw x5, -8(x8)
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -676(x8)
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
sw x5, -680(x8)
lw x5, -680(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -8(x8)
lw x5, -8(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
addi a7, x0, 1
ecall
addi x5, x0, 0
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -684(x8)
lw x5, -684(x8)
sw x5, 0(x2)
addi x2, x2, -4

