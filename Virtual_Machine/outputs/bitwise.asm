.section
.text
.global main
main:
addi x5, x0, 8
sw x5, -4(x8)
addi x6, x0, 3
sw x6, -8(x8)
and x7, x5, x6
or x28, x5, x6
xor x29, x5, x6
sll x30, x5, x6
srl x31, x5, x6
