main:
@t0 = 0 INT
- INT i
i = @t0 INT
@t1 = 4 INT
- INT j
j = @t1 INT
@t2 = 0 INT
i = @t2 INT

#L0:
@t3 = 5 INT
@t4 = i < @t3 INT

if @t4 GOTO #L1 else GOTO #L2

#L3:
@t5 = 1 INT
@t6 = i + @t5 INT
i = @t6 INT
GOTO #L0

#L1:
@t7 = 2 INT
@t8 = j + @t7 INT
j = @t8 INT
GOTO #L3

#L2:
print j INT
end:

