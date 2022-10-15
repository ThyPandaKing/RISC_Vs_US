.section
.data

.section
.text
main:
addi x30, x0, 8
sw x30, -4(x8)
addi x31, x0, 3
sw x31, -8(x8)
and x29, x30, x31
# ---- end of block ----
sw x30, -4(x8)
sw x29, -12(x8)
sw x31, -8(x8)
# ---- end of spill ----
lw a0, -12(x8)
li a7, 1
ecall
lb x31, -4(x8)
lb x29, -8(x8)
or x30, x31, x29
# ---- end of block ----
sw x31, -4(x8)
sw x29, -8(x8)
sw x30, -16(x8)
# ---- end of spill ----
lw a0, -16(x8)
li a7, 1
ecall
lb x31, -4(x8)
lb x29, -8(x8)
xor x30, x31, x29
# ---- end of block ----
sw x31, -4(x8)
sw x29, -8(x8)
sw x30, -20(x8)
# ---- end of spill ----
lw a0, -20(x8)
li a7, 1
ecall
lb x31, -4(x8)
lb x29, -8(x8)
sll x30, x31, x29
# ---- end of block ----
sw x31, -4(x8)
sw x29, -8(x8)
sw x30, -24(x8)
# ---- end of spill ----
lw a0, -24(x8)
li a7, 1
ecall
lb x31, -4(x8)
lb x29, -8(x8)
srl x30, x31, x29
# ---- end of block ----
sw x31, -4(x8)
sw x29, -8(x8)
sw x30, -28(x8)
# ---- end of spill ----
lw a0, -28(x8)
li a7, 1
ecall