.section
.data
a:
	.asciz "hello\n"
c:
	.asciz "hello\n"
x:
	.asciz "ab\n"

.section
.text
main:
addi x5, x0, 3
# ---- start of spill ----
sw x5, -4(x8)
# ---- end of spill ----
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x00
addi a7, x0, 4
ecall
# ---- start of spill ----
# ---- end of spill ----
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x0e
addi a7, x0, 4
ecall
# ---- start of spill ----
# ---- end of spill ----
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x07
addi a7, x0, 4
ecall