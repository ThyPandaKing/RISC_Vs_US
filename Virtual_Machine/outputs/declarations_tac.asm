.section
.data

.section
.text
main:
addi x30, x0, 97
# ---- end of block ----
sb x30, -4(x8)
# ---- end of spill ----
lw a0, -4(x8)
addi a7, x0, 11
ecall
lui x30, 0xc0b5c
addi x30, x30, 0x28f
sw x30, -8(x8)
fmv.w.x f3, x30
# ---- end of block ----
fsw f3, -8(x8)
# ---- end of spill ----
flw fa0, -8(x8)
addi a7, x0, 2
ecall