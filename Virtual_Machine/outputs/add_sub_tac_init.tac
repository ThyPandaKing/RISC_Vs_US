.section
.text
.global main
# ---- end of block ----
# ---- end of spill ----
main:
sw x0, -4(x8)
lw x5, -4(x8)
addi x5, x0, 2
sw x5, -4(x8)
sw x0, -8(x8)
lw x6, -8(x8)
addi x6, x0, 3
sw x6, -8(x8)
sw x0, -12(x8)
lw x7, -12(x8)
add x7, x5, x6
sw x0, -16(x8)
lw x28, -16(x8)
add x28, x5, x6
sw x0, -20(x8)
lw x29, -20(x8)
sub x29, x28, x5
add x7, x29, x6
