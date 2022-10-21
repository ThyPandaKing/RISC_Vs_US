.section
.data

.section
.text
main:
addi x5, x0, 8
sw x5, -4(x8)
addi x6, x0, 3
sw x6, -8(x8)
lw x7, -12(x8)
and x7, x5, x6
# ---- start of spill ----
sw x5, -4(x8)
sw x6, -8(x8)
sw x7, -12(x8)
# ---- end of spill ----
lw a0, -12(x8)
addi a7, x0, 1
ecall
lw x5, -16(x8)
lw x6, -4(x8)
lw x7, -8(x8)
or x5, x6, x7
# ---- start of spill ----
sw x6, -4(x8)
sw x7, -8(x8)
sw x5, -16(x8)
# ---- end of spill ----
lw a0, -16(x8)
addi a7, x0, 1
ecall
lw x5, -20(x8)
lw x6, -4(x8)
lw x7, -8(x8)
xor x5, x6, x7
# ---- start of spill ----
sw x6, -4(x8)
sw x7, -8(x8)
sw x5, -20(x8)
# ---- end of spill ----
lw a0, -20(x8)
addi a7, x0, 1
ecall
lw x5, -24(x8)
lw x6, -4(x8)
lw x7, -8(x8)
sll x5, x6, x7
# ---- start of spill ----
sw x6, -4(x8)
sw x7, -8(x8)
sw x5, -24(x8)
# ---- end of spill ----
lw a0, -24(x8)
addi a7, x0, 1
ecall
lw x5, -28(x8)
lw x6, -4(x8)
lw x7, -8(x8)
srl x5, x6, x7
# ---- start of spill ----
sw x6, -4(x8)
sw x7, -8(x8)
sw x5, -28(x8)
# ---- end of spill ----
lw a0, -28(x8)
addi a7, x0, 1
ecall