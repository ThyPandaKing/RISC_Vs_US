.section
.data

.section
.text
main:
addi x30, x0, 4
sw x30, -4(x8)
add x31, x0, x30
addi x29, x0, 1
sw x29, -12(x8)
sub x28, x31, x29
# ---- end of block ----
sw x31, -8(x8)
sw x28, -16(x8)
sw x29, -12(x8)
sw x30, -4(x8)
# ---- end of spill ----
beq x28, x0, ___L100
beq x0, x0, ___L101
___L100:
addi x30, x0, 1
# ---- end of block ----
sw x30, -20(x8)
# ---- end of spill ----
beq x0, x0, ___L102
___L101:
addi x30, x0, 0
sw x30, -20(x8)
___L102:
# ---- end of block ----
sw x30, -20(x8)
# ---- end of spill ----
lw x30, -20(x8)
bne x30, x0, __L1
beq x0, x0, __L2
__L1:
addi x31, x0, 1
sw x31, -24(x8)
lb x28, -8(x8)
add x29, x28, x31
add x28, x0, x29
# ---- end of block ----
sw x28, -8(x8)
sw x29, -28(x8)
sw x31, -24(x8)
sw x30, -20(x8)
# ---- end of spill ----
beq x0, x0, __L0
__L2:
addi x30, x0, 2
sw x30, -32(x8)
lb x29, -8(x8)
sub x31, x29, x30
# ---- end of block ----
sw x29, -8(x8)
sw x30, -32(x8)
sw x31, -36(x8)
# ---- end of spill ----
beq x31, x0, ___L103
beq x0, x0, ___L104
___L103:
addi x30, x0, 1
# ---- end of block ----
sw x30, -40(x8)
# ---- end of spill ----
beq x0, x0, ___L105
___L104:
addi x30, x0, 0
sw x30, -40(x8)
___L105:
# ---- end of block ----
sw x30, -40(x8)
# ---- end of spill ----
lw x30, -40(x8)
bne x30, x0, __L3
beq x0, x0, __L4
__L3:
addi x31, x0, 2
sw x31, -44(x8)
lb x28, -8(x8)
add x29, x28, x31
add x28, x0, x29
# ---- end of block ----
sw x28, -8(x8)
sw x29, -48(x8)
sw x31, -44(x8)
sw x30, -40(x8)
# ---- end of spill ----
beq x0, x0, __L0
__L4:
addi x30, x0, 3
sw x30, -52(x8)
lb x29, -8(x8)
add x31, x29, x30
add x29, x0, x31
__L0:
# ---- end of block ----
sw x29, -8(x8)
sw x30, -52(x8)
sw x31, -56(x8)
# ---- end of spill ----
lw a0, -8(x8)
addi a7, x0, 1
ecall
addi x30, x0, 0
sw x30, -60(x8)