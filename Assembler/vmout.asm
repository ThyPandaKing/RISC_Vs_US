.section
.data
.section
.text
main:
beq x1,x1,doubler
addi x1,x1,4
doubler:
addi a0,a0,42
jal x0,doubler

addi x1,x1,4

addi x1,x1,4

addi x1,x1,4

