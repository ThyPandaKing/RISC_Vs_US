.section
.data
a:
	.asciz "hello\n"
c:
	.asciz "hello\n"

.section
.text
main:
addi x30, x0, 3
# ---- end of block ----
sw x30, -4(x8)
# ---- end of spill ----
la a0, a
addi a7, x0, 4
ecall
# ---- end of block ----
# ---- end of spill ----
la a0, c
addi a7, x0, 4
ecall