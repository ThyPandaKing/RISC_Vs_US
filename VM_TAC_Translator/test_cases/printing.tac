.global main

main:

- STR a
a = "hello\n" STR

- INT b
b = 3 INT

- STR c
c = a STR
print a STR

- STR x
x = "ab\n" STR

print x STR

print c STR
return 0 INT

end:
