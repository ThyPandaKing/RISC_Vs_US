.section
.data

.section
.text
main:
addi x30, x0, 8
sw x30, -4(x8)
addi x31, x0, 3
sw x31, -8(x8)
div x29, x30, x31
# ---- end of block ----
sw x30, -4(x8)
sw x29, -12(x8)
sw x31, -8(x8)
# ---- end of spill ----
lw a0, -12(x8)
addi a7, x0, 1
ecall
lb x31, -4(x8)
lb x29, -12(x8)
mul x30, x31, x29
# ---- end of block ----
sw x31, -4(x8)
sw x29, -12(x8)
sw x30, -16(x8)
# ---- end of spill ----
lw a0, -16(x8)
addi a7, x0, 1
ecall
lui x30, 0xc0899
addi x30, x30, 0x9
addi x30, x30, 0x9a
sw x30, -20(x8)
fmv.w.x f3, x30
lui x30, 0x40000
addi x30, x30, 0x0
addi x30, x30, 0x00
sw x30, -24(x8)
fmv.w.x f4, x30
fdiv.s f5, f3, f4
# ---- end of block ----
fsw f4, -24(x8)
fsw f3, -20(x8)
fsw f5, -28(x8)
# ---- end of spill ----
flw fa0, -28(x8)
addi a7, x0, 2
ecall
flw f4, -20(x8)
flw f5, -24(x8)
fmul.s f3, f4, f5
# ---- end of block ----
fsw f3, -32(x8)
fsw f5, -24(x8)
fsw f4, -20(x8)
# ---- end of spill ----
flw fa0, -32(x8)
addi a7, x0, 2
ecall