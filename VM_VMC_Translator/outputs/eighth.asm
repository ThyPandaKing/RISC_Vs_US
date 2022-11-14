.section
.data
__main__data0:
	.asciz "Tree: \n\n"
__main__data1:
	.asciz " "
__main__data2:
	.asciz "\n"
__main__data3:
	.asciz "\n\n"
__main__data4:
	.asciz "Insert: "

.section
.text
.global main
jal x30, main
main:
lui x5, 0xffffd
addi x5, x5, 1354
addi x5, x5, 1354
addi x5, x5, 1354
addi x5, x5, 2
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x8, x6
sw x5, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1184
addi x5, x5, 1184
addi x5, x5, 1184
addi x5, x5, 0
lui x6, 0xffffd
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
add x6, x8, x6
sw x5, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1173
addi x5, x5, 1173
addi x5, x5, 1173
addi x5, x5, 1
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x8, x6
sw x5, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1002
addi x5, x5, 1002
addi x5, x5, 1002
addi x5, x5, 2
lui x6, 0xffffe
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
add x6, x8, x6
sw x5, 0(x6)
lui x2, 0xffffd
addi x2, x2, 1002
addi x2, x2, 1002
addi x2, x2, 1002
addi x2, x2, 2
add x2, x2, x8


lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -256
sw x5, 0(x6)

__L0:
lui x5, 0x00000
addi x5, x5, 21
addi x5, x5, 21
addi x5, x5, 21
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -8
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -256
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -8
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
blt x5, x6, ___CL0
addi x7, x0, 0
jal x30, ___CL1
___CL0:
addi x7, x0, 1
___CL1:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L1

jal x30, __L2
__L3:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -256
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
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
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -16
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -16
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -256
sw x5, 0(x6)

jal x30, __L0
__L1:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -16
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -16
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -256
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -256
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -256
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -256
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
lui x7, 0xffffd
addi x7, x7, 1364
addi x7, x7, 1364
addi x7, x7, 1364
addi x7, x7, 0
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)

jal x30, __L3
__L2:
__L4:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -20
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -20
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L5

jal x30, __L6
__L5:
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x00
addi a7, x0, 4
ecall

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -24
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -24
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -260
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -28
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -28
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -264
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -32
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -32
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -268
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -36
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -36
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -260
sw x5, 0(x6)

__L7:
lui x5, 0x00000
addi x5, x5, 2
addi x5, x5, 2
addi x5, x5, 2
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -40
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -260
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
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
blt x5, x6, ___CL2
addi x7, x0, 0
jal x30, ___CL3
___CL2:
addi x7, x0, 1
___CL3:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -44
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -44
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L8

jal x30, __L9
__L10:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -44
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -260
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -44
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -48
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -48
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -260
sw x5, 0(x6)

jal x30, __L7
__L8:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -48
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -48
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -272
sw x5, 0(x6)

__L11:
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -272
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -264
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
blt x5, x6, ___CL4
addi x7, x0, 0
jal x30, ___CL5
___CL4:
addi x7, x0, 1
___CL5:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -52
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -52
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L12

jal x30, __L13
__L14:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -52
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -272
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -52
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -56
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -56
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -272
sw x5, 0(x6)

jal x30, __L11
__L12:
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -268
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -272
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -56
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -56
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -56
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -56
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -56
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
lw x6, 0(x6)
sub x6, x6, x5
lw x7, 0(x6)
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -60
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -60
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
lui a7, 0x00000
addi a7, a7, 0
addi a7, a7, 0
addi a7, a7, 0
addi a7, a7, 1
ecall

lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x09
addi a7, x0, 4
ecall

jal x30, __L14
__L13:
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x0b
addi a7, x0, 4
ecall

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -268
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -264
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -56
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -56
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -268
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 2
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -56
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -64
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -68
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -72
sw x5, 0(x6)

__L16:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -68
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
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
blt x5, x6, ___CL6
addi x7, x0, 0
jal x30, ___CL7
___CL6:
addi x7, x0, 1
___CL7:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -76
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -76
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L17

jal x30, __L18
__L17:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -64
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -264
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -64
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -68
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -72
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -68
sw x5, 0(x6)

jal x30, __L16
__L18:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -64
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -264
sw x5, 0(x6)

jal x30, __L10
__L9:
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x0d
addi a7, x0, 4
ecall

lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x10
addi a7, x0, 4
ecall

addi a7, x0, 5
ecall
sw a0, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -276
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -68
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -68
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -280
sw x5, 0(x6)

__L19:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
lw x6, 0(x6)
sub x6, x6, x5
lw x7, 0(x6)
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -76
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -72
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -76
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -72
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
beq x5, x6, ___CL8
addi x7, x0, 0
jal x30, ___CL9
___CL8:
addi x7, x0, 1
___CL9:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -80
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -80
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
beq x5, x6, ___CL10
addi x7, x0, 0
jal x30, ___CL11
___CL10:
addi x7, x0, 1
___CL11:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, ___L0

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
jal x30, ___L1
___L0:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
___L1:
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -64
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -64
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L20

jal x30, __L21
__L20:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
lw x6, 0(x6)
sub x6, x6, x5
lw x7, 0(x6)
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -80
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -276
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -80
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
blt x5, x6, ___CL12
addi x7, x0, 0
jal x30, ___CL13
___CL12:
addi x7, x0, 1
___CL13:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -76
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -76
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L23

jal x30, __L24
__L23:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 2
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -64
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -80
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -76
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -84
sw x5, 0(x6)

__L26:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -76
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
blt x5, x6, ___CL14
addi x7, x0, 0
jal x30, ___CL15
___CL14:
addi x7, x0, 1
___CL15:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -88
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -88
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L27

jal x30, __L28
__L27:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -80
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -64
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -80
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -76
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -84
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -76
sw x5, 0(x6)

jal x30, __L26
__L28:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -76
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -80
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -76
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -88
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -88
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -280
sw x5, 0(x6)

jal x30, __L22
__L24:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 2
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -84
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -80
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -88
sw x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -92
sw x5, 0(x6)

__L30:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -88
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
blt x5, x6, ___CL16
addi x7, x0, 0
jal x30, ___CL17
___CL16:
addi x7, x0, 1
___CL17:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -96
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -96
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L31

jal x30, __L32
__L31:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -80
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -84
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -80
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -88
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -92
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -88
sw x5, 0(x6)

jal x30, __L30
__L32:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 2
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -88
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -80
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -88
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -96
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -96
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -280
sw x5, 0(x6)

__L22:
jal x30, __L19
__L21:
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -276
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -280
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x6, x5
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
lui x7, 0xffffd
addi x7, x7, 1364
addi x7, x7, 1364
addi x7, x7, 1364
addi x7, x7, 0
lw x7, 0(x7)
sub x7, x7, x5
sw x6, 0(x7)

jal x30, __L4
__L6:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -92
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -92
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4
jal x30, __END__
__END__:
