.section
.data
b:
	.asciz "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

.section
.text
main:
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x00
addi a1, x0, 30
addi a7, x0, 8
ecall
# ---- start of spill ----
# ---- end of spill ----
lui a0, 0x10010
addi a0, a0, 0x0
addi a0, a0, 0x00
addi a7, x0, 4
ecall