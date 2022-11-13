.section
.data
__main__data0:
	.asciz "Enter a decimal number: "
__main__data1:
	.asciz "Final decimal number precision: "
__main__data2:
	.asciz "Rounded number: "
__main__data3:
	.asciz "\n"

.section
.text
.global main
beq x0, x0, main
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



lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x00
addi a7, x0, 4
ecall


addi a7, x0, 6
ecall
fsw fa0, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
flw f3, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
fsw f3, 0(x6)


lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x19
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
addi x6, x6, -8
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
addi x6, x6, -12
sw x5, 0(x6)

__L0:
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
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
beq x0, x0, ___CL1
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
addi x6, x6, -8
sw x5, 0(x6)

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L1

beq x0, x0, __L2
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
addi x6, x6, -8
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
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
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x5, x6
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
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
sw x5, 0(x6)

beq x0, x0, __L0
__L1:
lui x5, 0x00000
addi x5, x5, 3
addi x5, x5, 3
addi x5, x5, 3
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

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -16
fsw f3, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -20
fsw f3, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -24
fsw f3, 0(x6)

__L5:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -20
flw f3, 0(x5)
fsw f3, 0(x2)
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
flw f4, 0(x2)
addi x2, x2, 4
flw f3, 0(x2)
flt.s f3, f4, ___CL2
add.s f5, f0, f0
beq x0, x0, ___CL3
___CL2:
lui x7, 0x3f800
addi x7, x7, 0x0
addi x7, x7, 0x00
fmv.w.x f5, x7
___CL3:
fsw f5, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -28
fsw f3, 0(x6)

addi x2, x2, 4
flw f3, 0(x2)
lui x7, 0x3f800
addi x7, x7, 0x0
addi x7, x7, 0x00
fmv.w.x f4, x7
fle.s f3, f4, __L6

beq x0, x0, __L7
__L6:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -16
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
flw f3, 0(x2)
addi x2, x2, 4
flw f4, 0(x2)
fadd.s f3, f3, f4
fsw f3, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
flw f3, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -16
fsw f3, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -20
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -24
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
flw f3, 0(x2)
addi x2, x2, 4
flw f4, 0(x2)
fadd.s f3, f3, f4
fsw f3, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
flw f3, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -20
fsw f3, 0(x6)

beq x0, x0, __L5
__L7:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -16
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
flw f3, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
fsw f3, 0(x6)

beq x0, x0, __L3
__L2:
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
flw f3, 0(x2)
fcvt.w.s x5, f3
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -16
sw x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -16
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
fsw f3, 0(x6)

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
addi x6, x6, -12
sw x5, 0(x6)

__L7:
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
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
addi x5, x5, -8
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x6, 0(x2)
addi x2, x2, 4
lw x5, 0(x2)
blt x5, x6, ___CL4
addi x7, x0, 0
beq x0, x0, ___CL5
___CL4:
addi x7, x0, 1
___CL5:
sw x7, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -20
fsw f3, 0(x6)

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, __L8

beq x0, x0, __L9
__L10:
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
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
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -28
fsw f3, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -28
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
flw f3, 0(x2)
fcvt.w.s x5, f3
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
sw x5, 0(x6)

beq x0, x0, __L7
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
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -24
fsw f3, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
flw f3, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -16
fsw f3, 0(x6)

lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -28
fsw f3, 0(x6)

__L12:

beq x0, x0, __L14
__L13:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -24
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -28
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
flw f3, 0(x2)
addi x2, x2, 4
flw f4, 0(x2)
fadd.s f3, f3, f4
fsw f3, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
flw f3, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -24
fsw f3, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -16
flw f3, 0(x5)
fsw f3, 0(x2)
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
flw f3, 0(x2)
addi x2, x2, 4
flw f4, 0(x2)
fsub.s f3, f3, f4
fsw f3, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -16
fsw f3, 0(x6)

beq x0, x0, __L12
__L14:
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -24
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
flw f3, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
fsw f3, 0(x6)

beq x0, x0, __L10
__L9:

lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x3a
addi a7, x0, 4
ecall


lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
flw fa0, 0(x2)
addi x2, x2, -4
lui a7, 0x00000
addi a7, a7, 0
addi a7, a7, 0
addi a7, a7, 0
addi a7, a7, 2
ecall


lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x4b
addi a7, x0, 4
ecall


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
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sw x5, 0(x6)

beq x0, x0, __END__
__END__:
