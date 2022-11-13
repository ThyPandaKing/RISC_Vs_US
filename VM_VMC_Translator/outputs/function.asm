.section
.data

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


lui x5, 0x00000
addi x5, x5, 1
addi x5, x5, 1
addi x5, x5, 1
addi x5, x5, 2
sw x5, 0(x2)
addi x2, x2, -4


lui x5, 0xffffd
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 2
lw x7, 0(x5)
addi x5, x2, 8
lui x6, 0xffffd
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
sw x5, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
sw x7, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1360
addi x5, x5, 1360
addi x5, x5, 1360
addi x5, x5, 0
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1358
addi x5, x5, 1358
addi x5, x5, 1358
addi x5, x5, 2
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
jal x1, fact

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

beq x0, x0, __END__
fact:
sw x1, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
sw x2, 0(x5)
addi x6, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
sw x2, 0(x5)
addi x2, x2, -8

lui x5, 0xffffd
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 2
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lw x5, 0(x5)
sw x5, 0(x2)
addi x2, x2, -4


lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4


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
lui x6, 0x00000
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 0
addi x6, x6, 1
beq x5, x6, REC

beq x0, x0, ONE
REC:
lui x5, 0x00000
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 0
addi x5, x5, 1
sw x5, 0(x2)
addi x2, x2, -4


lui x5, 0xffffd
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 2
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
sub x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4

lui x5, 0xffffd
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 2
lw x7, 0(x5)
addi x5, x2, 8
lui x6, 0xffffd
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
sw x5, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
sw x7, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1360
addi x5, x5, 1360
addi x5, x5, 1360
addi x5, x5, 0
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
lui x5, 0xffffd
addi x5, x5, 1358
addi x5, x5, 1358
addi x5, x5, 1358
addi x5, x5, 2
lw x6, 0(x5)
sw x6, 0(x2)
addi x2, x2, -4
jal x1, fact

lui x5, 0xffffd
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 1362
addi x5, x5, 2
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
add x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
lw x6, 0(x6)
sw x5, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
lw x2, 0(x5)
lw x5, 8(x2)
lui x6, 0xffffd
addi x6, x6, 1358
addi x6, x6, 1358
addi x6, x6, 1358
addi x6, x6, 2
sw x5, 0(x6)
lw x5, 12(x2)
lui x6, 0xffffd
addi x6, x6, 1360
addi x6, x6, 1360
addi x6, x6, 1360
addi x6, x6, 0
sw x5, 0(x6)
lw x5, 16(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
sw x5, 0(x6)
lw x7, 20(x2)
lw x5, 24(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
sw x5, 0(x6)
lw x5, 4(x2)
lui x6, 0xffffd
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
lw x2, 0(x6)
addi x2, x2, -4
lui x6, 0xffffd
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
sw x7, 0(x6)
jalr x28, x5, 0

ONE:
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
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
lw x6, 0(x6)
sw x5, 0(x6)
lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
lw x2, 0(x5)
lw x5, 8(x2)
lui x6, 0xffffd
addi x6, x6, 1358
addi x6, x6, 1358
addi x6, x6, 1358
addi x6, x6, 2
sw x5, 0(x6)
lw x5, 12(x2)
lui x6, 0xffffd
addi x6, x6, 1360
addi x6, x6, 1360
addi x6, x6, 1360
addi x6, x6, 0
sw x5, 0(x6)
lw x5, 16(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
sw x5, 0(x6)
lw x7, 20(x2)
lw x5, 24(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
sw x5, 0(x6)
lw x5, 4(x2)
lui x6, 0xffffd
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
lw x2, 0(x6)
addi x2, x2, -4
lui x6, 0xffffd
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 1362
addi x6, x6, 2
sw x7, 0(x6)
jalr x28, x5, 0

__END__:
