main:
@t0 = 3 INT
- INT a
a = @t0 INT
@t1 = 5 INT
- INT b
b = @t1 INT
@t2 = a INT
@t3 = 3 INT
@t4 = @t2 == @t3 INT
if @t4 GOTO #L1 else GOTO #L2
#L1:
@t5 = 12 INT
b = @t5 INT
GOTO #L0
#L2:
@t6 = a INT
@t7 = 2 INT
@t8 = @t6 == @t7 INT
if @t8 GOTO #L3 else GOTO #L4
#L3:
@t9 = 14 INT
b = @t9 INT
GOTO #L0
#L4:
@t10 = 6 INT
b = @t10 INT
#L0:
end:
