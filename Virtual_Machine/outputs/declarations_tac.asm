.section
.data

.section
.text
main:
addi x5, x0, 97
# ---- start of spill ----
sb x5, -4(x8)
# ---- end of spill ----
lw a0, -4(x8)
addi a7, x0, 11
ecall
lui x5, 0xc0b5c
addi x5, x5, 0x2
addi x5, x5, 0x8f
sw x5, -8(x8)
fmv.w.x f3, x5
# ---- start of spill ----
fsw f3, -8(x8)
# ---- end of spill ----
flw fa0, -8(x8)
addi a7, x0, 2
ecall
lui x5, 0x41099
addi x5, x5, 0x9
addi x5, x5, 0x9a
sw x5, -12(x8)
fmv.w.x f3, x5
flw f4, -8(x8)
fadd.s f3, f4, f3
# ---- start of spill ----
fsw f4, -8(x8)
fsw f3, -12(x8)
# ---- end of spill ----
flw fa0, -12(x8)
addi a7, x0, 2
ecall