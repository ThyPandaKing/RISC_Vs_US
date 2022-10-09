.section
.data
a:
	.asciz "hello\n"
c:
	.asciz "hello\n"

.section
.text
.global main
main:
addi x5, x0, 3
# ---- end of block ----
sw x5, -4(x8)
# ---- end of spill ----
la a0, a
li a7, 4
ecall
# ---- end of block ----
# ---- end of spill ----
la a0, c
li a7, 4
ecall