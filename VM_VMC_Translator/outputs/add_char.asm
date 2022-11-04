.global main
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
addi x5, x5, 16
addi x5, x5, 16
addi x5, x5, 16
addi x5, x5, 0
sb x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lb x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1361
addi x6, x6, 1
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sb x5, 0(x6)

lui x5, 0x00000
addi x5, x5, 16
addi x5, x5, 16
addi x5, x5, 16
addi x5, x5, 1
sb x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lb x5, 0(x2)
lui x6, 0xffffd
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 1364
addi x6, x6, 0
add x6, x6, x8
lw x6, 0(x6)
addi x6, x6, -4
sb x5, 0(x6)

lui x5, 0xffffd
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1361
addi x5, x5, 1
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lb x5, 0(x5)
sb x5, 0(x2)
addi x2, x2, -4


lui x5, 0xffffd
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 1364
addi x5, x5, 0
add x5, x5, x8
lw x5, 0(x5)
addi x5, x5, -4
lb x5, 0(x5)
sb x5, 0(x2)
addi x2, x2, -4


addi x2, x2, 4
lb x5, 0(x2)
addi x2, x2, 4
lb x6, 0(x2)
add x5, x5, x6
sb x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lb x5, 0(x2)
add a0, x5, x0
addi x2, x2, -4
lui a7, 0x00000
addi a7, a7, 3
addi a7, a7, 3
addi a7, a7, 3
addi a7, a7, 2
ecall

