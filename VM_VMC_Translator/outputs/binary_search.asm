.global main
beq x0, x0, main
binary_search:
sw x1, 0(x2)
addi x2, x2, -4
li x5, -8196
sw x2, 0(x5)
addi x6, x2, -80
li x5, -8204
sw x2, 0(x5)
addi x2, x2, -160

li x5, 4
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
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
addi x2, x2, 4
lw x6, 0(x2)
li x7, -8196
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)

li x5, 8
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, 4
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
addi x2, x2, 4
lw x6, 0(x2)
li x7, -8196
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)

li x5, 10
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, 8
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
addi x2, x2, 4
lw x6, 0(x2)
li x7, -8196
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)

li x5, 17
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, 12
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
addi x2, x2, 4
lw x6, 0(x2)
li x7, -8196
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)





addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
blt x5, x6, ___CL0
beq x5, x6, ___CL0
addi x7, x0, 1
beq x0, x0, ___CL1
___CL0:
addi x7, x0, 0
___CL1:
sw x7, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
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
li x6, 1
beq x5, x6, __L1

beq x0, x0, __L2
__L1:
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

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -8
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8200
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8200
lw x6, 0(x6)
sw x5, 0(x6)
li x5, -8196
lw x2, 0(x5)
lw x5, 8(x2)
li x6, -8212
sw x5, 0(x6)
lw x5, 12(x2)
li x6, -8208
sw x5, 0(x6)
lw x5, 16(x2)
li x6, -8204
sw x5, 0(x6)
lw x7, 20(x2)
lw x5, 24(x2)
li x6, -8196
sw x5, 0(x6)
lw x5, 4(x2)
li x6, -8200
lw x2, 0(x6)
addi x2, x2, -4
li x6, -8200
sw x7, 0(x6)
jalr x28, x5, 0

beq x0, x0, __L0
__L2:
__L0:




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
addi x6, x6, -16
sw x5, 0(x6)

li x5, 2
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
addi x5, x5, -16
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -28
sw x5, 0(x6)

li x5, 1
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -32
sw x5, 0(x6)

__L4:
li x5, 0
sw x5, 0(x2)
addi x2, x2, -4




addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
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
li x6, 1
beq x5, x6, __L5

beq x0, x0, __L100
__L5:
li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -24
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
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -24
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -28
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
addi x6, x6, -28
sw x5, 0(x6)

beq x0, x0, __L4
__L100:


li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -24
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
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -32
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -32
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
sw x5, 0(x6)

li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4



addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
lw x6, 0(x6)
sub x6, x6, x5
lw x7, 0(x6)
sw x7, 0(x2)
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




addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
blt x5, x6, ___CL6
addi x7, x0, 0
beq x0, x0, ___CL7
___CL6:
addi x7, x0, 1
___CL7:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -44
sw x5, 0(x6)

li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -44
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
beq x5, x6, ___CL8
addi x7, x0, 0
beq x0, x0, ___CL9
___CL8:
addi x7, x0, 1
___CL9:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
li x6, 1
beq x5, x6, __L7

beq x0, x0, __L8
__L7:
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
addi x5, x5, -12
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
add x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -48
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -48
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4






li x5, -8200
lw x7, 0(x5)
addi x5, x2, 16
li x6, -8200
sw x5, 0(x6)
li x5, -8196
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
sw x7, 0(x2)
addi x2, x2, -4
li x5, -8204
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
li x5, -8208
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
li x5, -8212
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
jal x1, binary_search

li x5, -8200
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -52
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -52
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -20
sw x5, 0(x6)

li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -20
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8200
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8200
lw x6, 0(x6)
sw x5, 0(x6)
li x5, -8196
lw x2, 0(x5)
lw x5, 8(x2)
li x6, -8212
sw x5, 0(x6)
lw x5, 12(x2)
li x6, -8208
sw x5, 0(x6)
lw x5, 16(x2)
li x6, -8204
sw x5, 0(x6)
lw x7, 20(x2)
lw x5, 24(x2)
li x6, -8196
sw x5, 0(x6)
lw x5, 4(x2)
li x6, -8200
lw x2, 0(x6)
addi x2, x2, -4
li x6, -8200
sw x7, 0(x6)
jalr x28, x5, 0

beq x0, x0, __L6
__L8:
li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8196
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
add x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
lw x6, 0(x6)
sub x6, x6, x5
lw x7, 0(x6)
sw x7, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -56
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -56
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4




addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
blt x5, x6, ___CL10
beq x5, x6, ___CL10
addi x7, x0, 1
beq x0, x0, ___CL11
___CL10:
addi x7, x0, 0
___CL11:
sw x7, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -60
sw x5, 0(x6)

li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -60
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
beq x5, x6, ___CL12
addi x7, x0, 0
beq x0, x0, ___CL13
___CL12:
addi x7, x0, 1
___CL13:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
li x6, 1
beq x5, x6, __L9

beq x0, x0, __L10
__L9:


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
addi x5, x5, -12
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
addi x6, x6, -64
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -64
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4




li x5, -8200
lw x7, 0(x5)
addi x5, x2, 16
li x6, -8200
sw x5, 0(x6)
li x5, -8196
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
sw x7, 0(x2)
addi x2, x2, -4
li x5, -8204
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
li x5, -8208
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
li x5, -8212
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
jal x1, binary_search

li x5, -8200
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -68
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -68
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -24
sw x5, 0(x6)

li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -24
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8200
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8200
lw x6, 0(x6)
sw x5, 0(x6)
li x5, -8196
lw x2, 0(x5)
lw x5, 8(x2)
li x6, -8212
sw x5, 0(x6)
lw x5, 12(x2)
li x6, -8208
sw x5, 0(x6)
lw x5, 16(x2)
li x6, -8204
sw x5, 0(x6)
lw x7, 20(x2)
lw x5, 24(x2)
li x6, -8196
sw x5, 0(x6)
lw x5, 4(x2)
li x6, -8200
lw x2, 0(x6)
addi x2, x2, -4
li x6, -8200
sw x7, 0(x6)
jalr x28, x5, 0

beq x0, x0, __L6
__L10:
li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8200
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

addi x2, x2, 4
lw x5, 0(x2)
li x6, -8200
lw x6, 0(x6)
sw x5, 0(x6)
li x5, -8196
lw x2, 0(x5)
lw x5, 8(x2)
li x6, -8212
sw x5, 0(x6)
lw x5, 12(x2)
li x6, -8208
sw x5, 0(x6)
lw x5, 16(x2)
li x6, -8204
sw x5, 0(x6)
lw x7, 20(x2)
lw x5, 24(x2)
li x6, -8196
sw x5, 0(x6)
lw x5, 4(x2)
li x6, -8200
lw x2, 0(x6)
addi x2, x2, -4
li x6, -8200
sw x7, 0(x6)
jalr x28, x5, 0

__L6:
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


li x5, 4
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
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
addi x2, x2, 4
lw x6, 0(x2)
li x7, -8196
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)

li x5, 8
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, 4
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
addi x2, x2, 4
lw x6, 0(x2)
li x7, -8196
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)

li x5, 10
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, 8
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
addi x2, x2, 4
lw x6, 0(x2)
li x7, -8196
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)

li x5, 17
sw x5, 0(x2)
addi x2, x2, -4


li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


li x5, 12
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
addi x2, x2, 4
lw x6, 0(x2)
li x7, -8196
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)

li x5, 8
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

li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -8
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -8
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


li x5, 3
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


li x5, -8200
lw x7, 0(x5)
addi x5, x2, 16
li x6, -8200
sw x5, 0(x6)
li x5, -8196
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
sw x7, 0(x2)
addi x2, x2, -4
li x5, -8204
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
li x5, -8208
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
li x5, -8212
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
jal x1, binary_search

li x5, -8200
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
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
li x6, -8196
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -8
sw x5, 0(x6)

li x5, -8196
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -8
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
li a7, 1
ecall

li x5, 0
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8204
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -8
sw x5, 0(x6)

li x5, -8204
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -8
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
li x6, -8200
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

beq x0, x0, __END__

__END__:
