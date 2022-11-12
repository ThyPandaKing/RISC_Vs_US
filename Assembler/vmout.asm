.section
.data
.section
.text
main:
lw t2,12(s0)
beq t2,t2,le
sw t2,15(s0)
le:
sw t2,20(s0)