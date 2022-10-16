.section
.data

.section
.text
main:
addi x30, x0, 24
sw x30, -4(x8)
addi x31, x0, 5
sw x31, -8(x8)
addi x29, x0, 0
sw x29, -12(x8)
add x28, x0, x30
addi x6, x0, 1
sw x6, -20(x8)
# ---- start of spill ----
sw x30, -4(x8)
sw x29, -12(x8)
sw x31, -8(x8)
sw x6, -20(x8)
sb x28, -16(x8)
# ---- end of spill ----
___L100:
lw x30, -24(x8)
lb x31, -16(x8)
lb x29, -8(x8)
sub x30, x31, x29
# ---- start of spill ----
sw x29, -8(x8)
sb x30, -24(x8)
sb x31, -16(x8)
# ---- end of spill ----
bge x30, x0, ___L101
beq x0, x0, ___L102
# ---- start of spill ----
# ---- end of spill ----
___L101:
lw x30, -12(x8)
lb x31, -20(x8)
add x30, x30, x31
lw x29, -16(x8)
lb x28, -8(x8)
sub x29, x29, x28
# ---- start of spill ----
sw x30, -12(x8)
sw x28, -8(x8)
sw x31, -20(x8)
sb x29, -16(x8)
# ---- end of spill ----
beq x0, x0, ___L100
# ---- start of spill ----
# ---- end of spill ----
___L102:
lw x30, -12(x8)
# ---- start of spill ----
sw x30, -12(x8)
# ---- end of spill ----
bne x30, x0, ___L103
beq x0, x0, ___L104
# ---- start of spill ----
# ---- end of spill ----
___L103:
addi x30, x0, 1
# ---- start of spill ----
sw x30, -12(x8)
# ---- end of spill ----
___L104:
# ---- start of spill ----
# ---- end of spill ----