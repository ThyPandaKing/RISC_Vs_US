.global main

main:

- INT a
a = 2 INT
- INT b
b = 3 INT
- INT c

c = a + b INT
print c INT

@t0 = a + b INT
@t1 = @t0 - a INT
c = @t1 + b INT
print c INT
return 0 INT

- INT x
x = 7 INT
x = a + b
print x INT

return 0 INT

end:

