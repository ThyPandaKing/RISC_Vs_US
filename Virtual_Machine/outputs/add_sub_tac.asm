.section
.data

.section
.text
main:
addi x30, x0, 2
sw x30, -4(x8)
addi x31, x0, 3
sw x31, -8(x8)
add x29, x30, x31
# ---- start of spill ----
sw x30, -4(x8)
sw x29, -12(x8)
sw x31, -8(x8)
# ---- end of spill ----
lw a0, -12(x8)
addi a7, x0, 1
ecall
lw x31, -4(x8)
lw x29, -8(x8)
add x30, x31, x29
sub x28, x30, x31
add x6, x28, x29
# ---- start of spill ----
sw x31, -4(x8)
sw x6, -12(x8)
sw x29, -8(x8)
sw x28, -20(x8)
sw x30, -16(x8)
# ---- end of spill ----
lw a0, -12(x8)
addi a7, x0, 1
ecall