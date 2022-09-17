main:
@t0 = 2 INT
- INT a
a = @t0 INT
- INT b
@t1 = a INT
@t2 = 3 INT
@t3 = @t1 == @t2 INT
if @t3 GOTO #L1 else GOTO #L2
#L1:
@t4 = 1 INT
b = @t4 INT
GOTO #L0
#L2:
@t5 = a INT
@t6 = 2 INT
@t7 = @t5 == @t6 INT
if @t7 GOTO #L3 else GOTO #L4
#L3:
@t8 = 4 INT
b = @t8 INT
GOTO #L0
#L4:
@t9 = 5 INT
b = @t9 INT
#L0:
@t10 = 0 INT
return @t10 INT
end: