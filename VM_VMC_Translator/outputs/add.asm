.global Main
Main:
addi x2, x8, -1284

li x5, 6
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -4(x8)
li x5, 7
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
sw x5, -648(x8)
lw x5, -4(x8)
sw x5, 0(x2)
addi x2, x2, -4

lw x5, -648(x8)
sw x5, 0(x2)
addi x2, x2, -4

addi x2, x2, 4
lw x5, 0(x2)
addi x2, x2, 4
lw x6, 0(x2)
add x5, x5, x6
sw x5, 0(x2)
addi x2, x2, -4
