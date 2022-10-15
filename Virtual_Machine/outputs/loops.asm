.section
.data

.section
.text
main:
addi x30, x0, 0
sw x30, -4(x8)
add x31, x0, x30
addi x29, x0, 4
sw x29, -12(x8)
add x28, x0, x29
addi x6, x0, 0
sw x6, -20(x8)
add x31, x0, x6
# ---- start of spill ----
sw x31, -8(x8)
sw x28, -16(x8)
sw x6, -20(x8)
sw x29, -12(x8)
sw x30, -4(x8)
# ---- end of spill ----
__L0:
addi x30, x0, 5
sw x30, -24(x8)
lw x29, -8(x8)
sub x31, x29, x30
# ---- start of spill ----
sw x29, -8(x8)
sw x30, -24(x8)
sw x31, -28(x8)
# ---- end of spill ----
blt x31, x0, ___L100
beq x0, x0, ___L101
# ---- start of spill ----
# ---- end of spill ----
___L100:
addi x30, x0, 1
# ---- start of spill ----
sw x30, -32(x8)
# ---- end of spill ----
beq x0, x0, ___L102
# ---- start of spill ----
# ---- end of spill ----
___L101:
addi x30, x0, 0
# ---- start of spill ----
sw x30, -32(x8)
# ---- end of spill ----
___L102:
# ---- start of spill ----
# ---- end of spill ----
lw x30, -32(x8)
bne x30, x0, __L1
beq x0, x0, __L2
# ---- start of spill ----
sw x30, -32(x8)
# ---- end of spill ----
__L3:
addi x30, x0, 1
sw x30, -36(x8)
lw x29, -8(x8)
add x31, x29, x30
add x29, x0, x31
# ---- start of spill ----
sw x29, -8(x8)
sw x31, -40(x8)
sw x30, -36(x8)
# ---- end of spill ----
beq x0, x0, __L0
# ---- start of spill ----
# ---- end of spill ----
__L1:
addi x30, x0, 2
sw x30, -44(x8)
lw x29, -16(x8)
add x31, x29, x30
add x29, x0, x31
# ---- start of spill ----
sw x31, -48(x8)
sw x29, -16(x8)
sw x30, -44(x8)
# ---- end of spill ----
beq x0, x0, __L3
# ---- start of spill ----
# ---- end of spill ----
__L2:
# ---- start of spill ----
# ---- end of spill ----
lw a0, -16(x8)
addi a7, x0, 1
ecall