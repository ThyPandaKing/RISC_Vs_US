.section
.text
.global main
# ---- end of block ----
# ---- end of spill ----
main:
addi x5, x0, 2
sw x5, -4(x8)
addi x6, x0, 3
sw x6, -8(x8)
add x7, x5, x6
add x28, x5, x6
sub x29, x28, x5
add x7, x29, x6
