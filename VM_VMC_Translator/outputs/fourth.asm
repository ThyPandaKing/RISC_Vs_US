.section
.data
__main__data0:
	.asciz "Enter a float value:"
__main__data1:
	.asciz "Floor: "
__main__data2:
	.asciz "Ceil:"

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
addi x6, x6, -8
sw x5, 0(x6)
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
lw x5, 0(x2)
fcvt.s.w f3, x5
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -12
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
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
flw f3, 0(x2)
addi x2, x2, 4
flw f4, 0(x2)
fsub.s f3, f4, f3
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
addi x6, x6, -16
fsw f3, 0(x6)
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x15
addi a7, x0, 4
ecall
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
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
addi x6, x6, -4
fsw f3, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
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
addi x5, x5, -4
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
flw f4, 0(x2)
addi x2, x2, 4
flw f3, 0(x2)
flt.s x28, f3, f4
bne x28, x0, ___CL0
fle.s x28, f3, f4
bne x28, x0, ___CL0
lui x7, 0x3f800
addi x7, x7, 0x0
addi x7, x7, 0x00
fmv.w.x f5, x7
beq x0, x0, ___CL1
___CL0:
lui x7, 0x00000
addi x7, x7, 0x0
addi x7, x7, 0x00
fmv.w.x f5, x7
___CL1:
fsw f5, 0(x2)
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
addi x6, x6, -8
fsw f3, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -8
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
flw f3, 0(x2)
lui x7, 0x3f800
addi x7, x7, 0x0
addi x7, x7, 0x00
fmv.w.x f4, x7
fle.s x28, f3, f4
bne x28, x0, __L1
beq x0, x0, __L2
__L1:
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
addi x6, x6, -8
fsw f3, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
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
addi x5, x5, -8
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
flw f3, 0(x2)
addi x2, x2, 4
flw f4, 0(x2)
fadd.s f3, f4, f3
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
addi x6, x6, -12
fsw f3, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
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
addi x6, x6, -12
fsw f3, 0(x6)
beq x0, x0, __L0
__L2:
__L0:
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x1d
addi a7, x0, 4
ecall
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -12
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
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
flw f3, 0(x5)
fsw f3, 0(x2)
addi x2, x2, -4
addi x2, x2, 4
flw f3, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
fsw f3, 0(x6)
beq x0, x0, __END__
__END__:
