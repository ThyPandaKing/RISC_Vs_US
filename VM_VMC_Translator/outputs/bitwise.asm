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

li x5, 6
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

li x5, 5
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
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


li x5, -8196
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
and x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
sw x5, 0(x6)

li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
li a7, 1
ecall

li x5, 44
sb x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lb x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
li a7, 11
ecall

li x5, 1
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
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
li a7, 1
ecall

