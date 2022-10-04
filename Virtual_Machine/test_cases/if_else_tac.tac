main:
@t0 = 2 INT
- INT a
a = @t0 INT
@t1 = 1 INT
@t2 = a == @t1 INT
if @t2 GOTO #L1 else GOTO #L2
#L1:
@t3 = 1 INT
@t4 = a + @t3 INT
a = @t4 INT
GOTO #L0
#L2:
@t5 = 2 INT
@t6 = a == @t5 INT
if @t6 GOTO #L3 else GOTO #L4
#L3:
@t7 = 2 INT
@t8 = a + @t7 INT
a = @t8 INT
GOTO #L0
#L4:
@t9 = 3 INT
@t10 = a + @t9 INT
a = @t10 INT
#L0:
print a INT
@t11 = 0 INT
return @t11 INT
end:

