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
sb x5, -32(x8)
sw x6, -8(x8)
add x6, x0, x5
sw x7, -12(x8)
lw x7, -44(x8)
sw x28, -16(x8)
lw x28, -8(x8)
add x7, x28, x29
sw x29, -20(x8)
add x29, x0, x7
sb x30, -24(x8)
addi x30, x0, 2
sw x30, -48(x8)
sb x31, -28(x8)
lw x31, -52(x8)
sub x31, x29, x30
# ---- start of spill ----
sw x28, -8(x8)
sb x5, -32(x8)
sb x6, -36(x8)
sw x29, -40(x8)
sw x7, -44(x8)
sw x30, -48(x8)
sw x31, -52(x8)
# ---- end of spill ----
beq x31, x0, ___L100
beq x0, x0, ___L101
# ---- start of spill ----
# ---- end of spill ----
___L100:
addi x5, x0, 1
# ---- start of spill ----
sw x5, -56(x8)
# ---- end of spill ----
beq x0, x0, ___L102
# ---- start of spill ----
# ---- end of spill ----
___L101:
addi x5, x0, 0
# ---- start of spill ----
sw x5, -56(x8)
# ---- end of spill ----
___L102:
# ---- start of spill ----
# ---- end of spill ----
lw x5, -56(x8)
bne x5, x0, __L1
beq x0, x0, __L2
# ---- start of spill ----
sw x5, -56(x8)
# ---- end of spill ----
__L1:
addi x5, x0, 1
sw x5, -60(x8)
lw x6, -64(x8)
lb x7, -28(x8)
sub x6, x7, x5
add x7, x0, x6
# ---- start of spill ----
sb x7, -28(x8)
sw x5, -60(x8)
sb x6, -64(x8)
# ---- end of spill ----
beq x0, x0, __L0
# ---- start of spill ----
# ---- end of spill ----
__L2:
lw x5, -68(x8)
lb x6, -28(x8)
lb x7, -36(x8)
sub x5, x6, x7
addi x28, x0, 97
sb x28, -72(x8)
lw x29, -76(x8)
sub x29, x5, x28
add x6, x0, x29
# ---- start of spill ----
sb x6, -28(x8)
sb x7, -36(x8)
sb x5, -68(x8)
sb x28, -72(x8)
sb x29, -76(x8)
# ---- end of spill ----
__L0:
# ---- start of spill ----
# ---- end of spill ----
lw a0, -28(x8)
addi a7, x0, 11
ecall