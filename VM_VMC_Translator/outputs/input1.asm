.global main
main:

addi x2, x8, -1284
addi x5, x0, 10
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -648(x8)
lw x5, -648(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -4(x8)
lw x5, -656(x8)
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -664(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -656(x8)
lw x5, -660(x8)
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -652(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -660(x8)
#L3:
lw x5, -656(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -8(x8)

addi x5, x0, 0
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -664(x8)
lw x5, -664(x8)
sw x5, 0(x2)
addi x2, x2, -4

