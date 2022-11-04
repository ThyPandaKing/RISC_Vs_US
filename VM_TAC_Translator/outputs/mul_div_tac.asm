.section
.data

.section
.text
main:
addi x5, x0, 24
sw x5, -4(x8)
addi x6, x0, 5
sw x6, -8(x8)
addi x7, x0, 0
sw x7, -12(x8)
add x28, x0, x5
addi x29, x0, 1
sw x29, -20(x8)
# ---- start of spill ----
sw x5, -4(x8)
sw x6, -8(x8)
sw x7, -12(x8)
sw x28, -16(x8)
sw x29, -20(x8)
# ---- end of spill ----
___L100:
lw x5, -24(x8)
lw x6, -16(x8)
lw x7, -8(x8)
sub x5, x6, x7
# ---- start of spill ----
sw x7, -8(x8)
sw x6, -16(x8)
sw x5, -24(x8)
# ---- end of spill ----
bge x5, x0, ___L101
beq x0, x0, ___L102
# ---- start of spill ----
# ---- end of spill ----
___L101:
lw x5, -12(x8)
lw x6, -20(x8)
add x5, x5, x6
lw x7, -16(x8)
lw x28, -8(x8)
sub x7, x7, x28
# ---- start of spill ----
sw x28, -8(x8)
sw x5, -12(x8)
sw x7, -16(x8)
sw x6, -20(x8)
# ---- end of spill ----
beq x0, x0, ___L100
# ---- start of spill ----
# ---- end of spill ----
___L102:
# ---- start of spill ----
# ---- end of spill ----
lw a0, -12(x8)
addi a7, x0, 1
ecall