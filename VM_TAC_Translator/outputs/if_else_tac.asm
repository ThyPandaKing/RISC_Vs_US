.section
.data

.section
.text
main:
addi x5, x0, 4
sw x5, -4(x8)
add x6, x0, x5
addi x7, x0, 1
sw x7, -12(x8)
lw x28, -16(x8)
sub x28, x6, x7
# ---- start of spill ----
sw x5, -4(x8)
sw x6, -8(x8)
sw x7, -12(x8)
sw x28, -16(x8)
# ---- end of spill ----
beq x28, x0, ___L100
beq x0, x0, ___L101
# ---- start of spill ----
# ---- end of spill ----
___L100:
addi x5, x0, 1
# ---- start of spill ----
sw x5, -20(x8)
# ---- end of spill ----
beq x0, x0, ___L102
# ---- start of spill ----
# ---- end of spill ----
___L101:
addi x5, x0, 0
# ---- start of spill ----
sw x5, -20(x8)
# ---- end of spill ----
___L102:
# ---- start of spill ----
# ---- end of spill ----
lw x5, -20(x8)
bne x5, x0, __L1
beq x0, x0, __L2
# ---- start of spill ----
sw x5, -20(x8)
# ---- end of spill ----
__L1:
addi x5, x0, 1
sw x5, -24(x8)
lw x6, -28(x8)
lw x7, -8(x8)
add x6, x7, x5
add x7, x0, x6
# ---- start of spill ----
sw x7, -8(x8)
sw x5, -24(x8)
sw x6, -28(x8)
# ---- end of spill ----
beq x0, x0, __L0
# ---- start of spill ----
# ---- end of spill ----
__L2:
addi x5, x0, 2
sw x5, -32(x8)
lw x6, -36(x8)
lw x7, -8(x8)
sub x6, x7, x5
# ---- start of spill ----
sw x7, -8(x8)
sw x5, -32(x8)
sw x6, -36(x8)
# ---- end of spill ----
beq x6, x0, ___L103
beq x0, x0, ___L104
# ---- start of spill ----
# ---- end of spill ----
___L103:
addi x5, x0, 1
# ---- start of spill ----
sw x5, -40(x8)
# ---- end of spill ----
beq x0, x0, ___L105
# ---- start of spill ----
# ---- end of spill ----
___L104:
addi x5, x0, 0
# ---- start of spill ----
sw x5, -40(x8)
# ---- end of spill ----
___L105:
# ---- start of spill ----
# ---- end of spill ----
lw x5, -40(x8)
bne x5, x0, __L3
beq x0, x0, __L4
# ---- start of spill ----
sw x5, -40(x8)
# ---- end of spill ----
__L3:
addi x5, x0, 2
sw x5, -44(x8)
lw x6, -48(x8)
lw x7, -8(x8)
add x6, x7, x5
add x7, x0, x6
# ---- start of spill ----
sw x7, -8(x8)
sw x5, -44(x8)
sw x6, -48(x8)
# ---- end of spill ----
beq x0, x0, __L0
# ---- start of spill ----
# ---- end of spill ----
__L4:
addi x5, x0, 3
sw x5, -52(x8)
lw x6, -56(x8)
lw x7, -8(x8)
add x6, x7, x5
add x7, x0, x6
# ---- start of spill ----
sw x7, -8(x8)
sw x5, -52(x8)
sw x6, -56(x8)
# ---- end of spill ----
__L0:
# ---- start of spill ----
# ---- end of spill ----
lw a0, -8(x8)
addi a7, x0, 1
ecall
addi x5, x0, 0
sw x5, -60(x8)