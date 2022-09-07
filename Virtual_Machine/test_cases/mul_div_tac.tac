.global main

main:

- INT a
a = 8 INT
- INT b
b = 3 INT
- INT c

c = a / b INT

@t0 = a * c INT
@t1 = a + b INT
c = @t1 - @t0 INT

return 0 INT

end:
