.section
.data

.section
.text
main:
addi x30, x0, 5
sw x30, -4(x8)
add x31, x0, x30
addi x29, x0, 3
sw x29, -12(x8)
sub x28, x0, x29
add x6, x0, x28
addi x7, x0, 120
sb x7, -24(x8)
add x5, x0, x7
sw x5, -28(x8)
addi x5, x0, 119
sb x5, -32(x8)
sw x6, -20(x8)
add x6, x0, x5
sw x7, -24(x8)
sw x28, -16(x8)
lb x28, -20(x8)
add x7, x31, x28
sw x29, -12(x8)
add x29, x0, x7
sw x30, -4(x8)
addi x30, x0, 2
sw x30, -48(x8)
sw x31, -8(x8)
sub x31, x29, x30
# ---- end of block ----
sw x29, -40(x8)
sw x28, -20(x8)
sw x30, -48(x8)
sw x7, -44(x8)
sb x5, -32(x8)
sb x6, -36(x8)
sw x31, -52(x8)
# ---- end of spill ----
beq x31, x0, ___L100
beq x0, x0, ___L101
___L100:
addi x30, x0, 1
# ---- end of block ----
sw x30, -56(x8)
# ---- end of spill ----
beq x0, x0, ___L102
___L101:
addi x30, x0, 0
sw x30, -56(x8)
___L102:
# ---- end of block ----
sw x30, -56(x8)
# ---- end of spill ----
lw x30, -56(x8)
bne x30, x0, __L1
beq x0, x0, __L2
__L1:
lb x29, -28(x8)
lb x28, -36(x8)
sub x31, x29, x28
add x29, x0, x31
# ---- end of block ----
sb x31, -60(x8)
sw x30, -56(x8)
sb x28, -36(x8)
sb x29, -28(x8)
# ---- end of spill ----
beq x0, x0, __L0
__L2:
lb x31, -28(x8)
lb x29, -36(x8)
sub x30, x31, x29
addi x28, x0, 97
sb x28, -68(x8)
sub x6, x30, x28
add x31, x0, x6
__L0:
# ---- end of block ----
sb x30, -64(x8)
sb x6, -72(x8)
sb x28, -68(x8)
sb x29, -36(x8)
sb x31, -28(x8)
# ---- end of spill ----
lw a0, -28(x8)
addi a7, x0, 11
ecall