.section
.data

.section
.text
main:
addi x30, x0, 97
# ---- start of spill ----
sb x30, -4(x8)
# ---- end of spill ----
lw a0, -4(x8)
addi a7, x0, 11
ecall
lui x30, 0xc0b5c
addi x30, x30, 0x2
addi x30, x30, 0x8f
sw x30, -8(x8)
fmv.w.x f3, x30
# ---- start of spill ----
fsw f3, -8(x8)
# ---- end of spill ----
flw fa0, -8(x8)
addi a7, x0, 2
ecall
lui x30, 0x41099
addi x30, x30, 0x9
addi x30, x30, 0x9a
sw x30, -12(x8)
fmv.w.x f3, x30
flw f4, -8(x8)
fadd.s f3, f4, f3
# ---- start of spill ----
fsw f3, -12(x8)
fsw f4, -8(x8)
# ---- end of spill ----
flw fa0, -12(x8)
addi a7, x0, 2
ecall