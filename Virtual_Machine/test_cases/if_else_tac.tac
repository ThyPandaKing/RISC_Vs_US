main:
@t0 = 1 INT
- INT b
b = @t0 INT
@t1 = 2 INT
- INT c
c = @t1 INT
@t2 = b INT
@t3 = c INT
@t4 = @t2 && @t3 INT
- INT a
a = @t4 INT
@t5 = 0 INT
return @t5 INT
end:
