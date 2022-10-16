.section
.data

.section
.text
.global main
# ---- start of spill ----
# ---- end of spill ----
main:
addi x30, x0, 8
sw x30, -4(x8)
addi x31, x0, 3
sw x31, -8(x8)
div x29, x30, x31
addi x28, x0, 0
sw x28, -16(x8)
addi x6, x0, 0
sw x6, -20(x8)
addi x7, x0, 1
sw x7, -24(x8)
addi x5, x0, 0
sw x5, -28(x8)
# ---- start of spill ----
sw x30, -4(x8)
sw x29, -12(x8)
sw x31, -8(x8)
sw x7, -24(x8)
sw x5, -28(x8)
sw x6, -20(x8)
sw x28, -16(x8)
# ---- end of spill ----
___L100:
lw x31, -20(x8)
lw x29, -12(x8)
sub x30, x31, x29
# ---- start of spill ----
sw x29, -12(x8)
sw x30, -28(x8)
sw x31, -20(x8)
# ---- end of spill ----
blt x30, x0, ___L101
beq x0, x0, ___L102
# ---- start of spill ----
# ---- end of spill ----
___L101:
# ---- start of spill ----
# ---- end of spill ----
beq x0, x0, ___L100
# ---- start of spill ----
# ---- end of spill ----
___L102:
lw x31, -4(x8)
lw x29, -12(x8)
mul x30, x31, x29
# ---- start of spill ----
sw x31, -4(x8)
sw x29, -12(x8)
sw x30, -16(x8)
# ---- end of spill ----
lw a0, -16(x8)
addi a7, x0, 1
ecall
# ---- start of spill ----
# ---- end of spill ----
lui x30, 0xc0899
addi x30, x30, 0x9
addi x30, x30, 0x9a
sw x30, -32(x8)
fmv.w.x f3, x30
lui x30, 0x40000
addi x30, x30, 0x0
addi x30, x30, 0x00
sw x30, -36(x8)
fmv.w.x f4, x30
fdiv.s f5, f3, f4
# ---- start of spill ----
fsw f5, -40(x8)
fsw f4, -36(x8)
fsw f3, -32(x8)
# ---- end of spill ----
flw fa0, -40(x8)
addi a7, x0, 2
ecall
flw f4, -32(x8)
flw f5, -36(x8)
fmul.s f3, f4, f5
# ---- start of spill ----
fsw f3, -44(x8)
fsw f5, -36(x8)
fsw f4, -32(x8)
# ---- end of spill ----
flw fa0, -44(x8)
addi a7, x0, 2
ecall