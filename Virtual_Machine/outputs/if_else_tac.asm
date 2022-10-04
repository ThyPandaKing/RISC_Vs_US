.section
.text
main:
addi x5, x0, 1
sw x5, -4(x8)
add x6, x0, x5
addi x7, x0, 2
sw x7, -12(x8)
add x28, x0, x7
add x29, x0, x6
add x30, x0, x28
sw x5, -4(x8)
add x5, x0, x31
sw x6, -8(x8)
addi x6, x0, 0
sw x6, -36(x8)
