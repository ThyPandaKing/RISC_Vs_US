.global main

main:

- INT a
a = 1 INT
- INT b

@t0 = a <= 1 INT

if @t1 GOTO #L1 else GOTO #L2
#L1:
b = 1 INT

#L2:
@t2 = a == 2 INT
if @t2 == 2 GOTO #L3 else GOTO #L4

#L3:
b = 2 INT

#L4:
b = 0 INT

return 0 INT

end:

