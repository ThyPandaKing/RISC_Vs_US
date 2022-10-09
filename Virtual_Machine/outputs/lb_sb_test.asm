.section
.data

.section
.text
main:
addi x5, x0, 5
sw x5, -4(x8)
add x6, x0, x5
addi x7, x0, 3
sw x7, -12(x8)
sub x28, x0, x7
add x29, x0, x28
addi x30, x0, 120
sb x30, -24(x8)
add x31, x0, x30
sw x5, -4(x8)
addi x5, x0, 119
sb x5, -26(x8)
sw x6, -8(x8)
add x6, x0, x5
sw x7, -12(x8)
sw x28, -16(x8)
lb x28, -8(x8)
add x7, x28, x29
sw x29, -20(x8)
add x29, x0, x7
sw x30, -24(x8)
addi x30, x0, 2
sw x30, -36(x8)
sw x31, -25(x8)
sub x31, x29, x30
# ---- end of block ----
sw x28, -8(x8)
sb x5, -26(x8)
sb x6, -27(x8)
sw x29, -28(x8)
sw x7, -32(x8)
sw x30, -36(x8)
sw x31, -40(x8)
# ---- end of spill ----
beq x31, x0, ___L100
beq x0, x0, ___L101
___L100:
addi x5, x0, 1
# ---- end of block ----
sw x5, -44(x8)
# ---- end of spill ----
beq x0, x0, ___L102
___L101:
addi x5, x0, 0
sw x5, -44(x8)
___L102:
# ---- end of block ----
sw x5, -44(x8)
# ---- end of spill ----
lw x5, -44(x8)
bne x5, x0, __L1
beq x0, x0, __L2
__L1:
lb x7, -25(x8)
lb x28, -27(x8)
sub x6, x7, x28
add x7, x0, x6
# ---- end of block ----
sb x7, -25(x8)
sb x28, -27(x8)
sw x5, -44(x8)
sb x6, -48(x8)
# ---- end of spill ----
beq x0, x0, __L0
__L2:
lb x6, -25(x8)
lb x7, -27(x8)
sub x5, x6, x7
addi x28, x0, 97
sb x28, -50(x8)
sub x29, x5, x28
add x6, x0, x29
__L0:
# ---- end of block ----
sb x6, -25(x8)
sb x7, -27(x8)
sb x5, -49(x8)
sb x28, -50(x8)
sb x29, -51(x8)
# ---- end of spill ----
li a0, x
li a7, 11
ecall