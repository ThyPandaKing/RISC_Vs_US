.section
.data

.section
.text
main:
addi x5, x0, 2
sw x5, -4(x8)
addi x6, x0, 3
sw x6, -8(x8)
lw x7, -12(x8)
add x7, x5, x6
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
add x5, x6, x7
lw x28, -20(x8)
sub x28, x5, x6
lw x29, -12(x8)
add x29, x28, x7
# ---- start of spill ----
sw x6, -4(x8)
sw x7, -8(x8)
sw x29, -12(x8)
sw x5, -16(x8)
sw x28, -20(x8)
# ---- end of spill ----
lw a0, -12(x8)
addi a7, x0, 1
ecall