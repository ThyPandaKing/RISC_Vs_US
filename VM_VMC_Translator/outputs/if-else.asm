.global main
main:

li x5, -8224
li x6, -8196
add x6, x8, x6
sw x5, 0(x6)
li x5, -8736
li x6, -8200
add x6, x8, x6
sw x5, 0(x6)
li x5, -8768
li x6, -8204
add x6, x8, x6
sw x5, 0(x6)
li x5, -9280
li x6, -8192
add x6, x8, x6
sw x5, 0(x6)
li x2, -9280
add x2, x2, x8

li x5, 2
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

li x5, 1
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -8
sw x5, 0(x6)

li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -8
lw x5, 0(x5)
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
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
sw x5, 0(x6)

li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
lw x5, 0(x5)
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
beq x5, x0, __L1

beq x0, x0, __L2
__L1:
li x5, 11
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -16
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -16
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
li a7, 1
ecall

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -8
sw x5, 0(x6)

beq x0, x0, __L0
__L2:
li x5, 2
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -20
lw x5, 0(x5)
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
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -20
sw x5, 0(x6)

li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -20
lw x5, 0(x5)
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
beq x5, x0, __L3

beq x0, x0, __L4
__L3:
li x5, 22
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -24
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -24
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
li a7, 1
ecall

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -8
sw x5, 0(x6)

beq x0, x0, __L0
__L4:
li x5, 33
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -28
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -28
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
li a7, 1
ecall

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -8
sw x5, 0(x6)

__L0:
li x5, 38
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -32
sw x5, 0(x6)

li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -8
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -32
lw x5, 0(x5)
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
add a0, x5, x0
addi x2, x2, -4
li a7, 1
ecall

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -36
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -36
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -8
sw x5, 0(x6)

li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -40
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -40
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


