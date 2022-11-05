.section
.data
s:	
	.word 15
a:
	.asciz "He\tllo\nt"
b:
	.word 18
.section
.text
main:
addi a1,a2,2
sw a3,-4(a4)
sw a5,4(a6)
sw a7,+4(x8)
add t6,t0,x5
addi t5,t1,1
sw t4,-12(t2)
sub t3,s0,s1
# ----#end of block----
sw s2,-4(s3)
sw s4,-8(s5)
sw s6,-12(s7)
sw s8,-16(s9)
# ---- end of spill ----
beq s10,s11,___L100
beq a0,x0,___L101
___L100:
addi x5,x0,1
# ---- end of block ----
sw x5,-20(x8)
# ---- end of spill ----
beq x0,x0,___L102
___L101:
addi x5,x0,0
sw x5,-20(x8)
___L102:
# ---- end of block ----
sw x5,-20(x8)
# ---- end of spill ----
bne x5,x0,__L1
beq x0,x0,__L2
__L1:
addi x6,x0,1
sw x6,-24(x8)
lw x28,-8(x8)
add x7,x28,x6
add x28,x0,x7
# ---- end of block ----
sw x28,-8(x8)
sw x5,-20(x8)
sw x6,-24(x8)
sw x7,-28(x8)
# ---- end of spill ----
beq x0,x0,__L0
__L2:
addi x5,x0,2
sw x5,-32(x8)
lw x7,-8(x8)
sub x6,x7,x5
# ---- end of block ----
sw x7,-8(x8)
sw x5,-32(x8)
sw x6,-36(x8)
# ---- end of spill ----
beq x6,x0,___L103
beq x0,x0,___L104
___L103:
addi x5,x0,1
# ---- end of block ----
sw x5,-40(x8)
# ---- end of spill ----
beq x0,x0,___L105
___L104:
addi x5,x0,0
sw x5,-40(x8)
___L105:
# ---- end of block ----
sw x5,-40(x8)
# ---- end of spill ----
bne x5,x0,__L3
beq x0,x0,__L4
__L3:
addi x6,x0,2
sw x6,-44(x8)
lw x28,-8(x8)
add x7,x28,x6
add x28,x0,x7
# ---- end of block ----
sw x28,-8(x8)
sw x5,-40(x8)
sw x6,-44(x8)
sw x7,-48(x8)
# ---- end of spill ----
beq x0,x0,__L0
__L4:
addi x5,x0,3
sw x5,-52(x8)
lw x7,-8(x8)
add x6,x7,x5
add x7,x0,x6
__L0:
# ---- end of block ----
sw x7,-8(x8)
sw x5,-52(x8)
sw x6,-56(x8)
# ---- end of spill ----
ecall
addi x5,x0,0
sw x5,-60(x8)