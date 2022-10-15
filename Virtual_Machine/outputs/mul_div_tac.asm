.section
.data

.section
.text
main:
addi x30, x0, 8
sw x30, -4(x8)
addi x31, x0, 3
sw x31, -8(x8)
div x29, x30, x31
addi x28, x0, 0
sw x28, -16(x8)
addi x6, x0, 0
sw x6, -20(x8)
addi x7, x0, 1
sw x7, -24(x8)
addi x5, x0, 0
sw x5, -28(x8)
___L100:
sub x5, x6, x29
# ---- end of block ----
sw x30, -4(x8)
sw x29, -12(x8)
sw x31, -8(x8)
sw x7, -24(x8)
sw x5, -28(x8)
sw x6, -20(x8)
sw x28, -16(x8)
# ---- end of spill ----
blt x5, x0, ___L101
beq x0, x0, ___L102
___L101:
# ---- end of block ----
# ---- end of spill ----
beq x0, x0, ___L100
___L102:
# ---- end of block ----
# ---- end of spill ----
lw a0, -16(x8)
addi a7, x0, 1
ecall