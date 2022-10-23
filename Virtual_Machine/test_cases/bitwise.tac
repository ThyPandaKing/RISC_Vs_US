.global main

main:

- INT a
a = 8 INT
- INT b
b = 3 INT
- INT c
- INT d
- INT e
- INT f
- INT g

c = a & b INT
print c INT
d = a | b INT
print d INT
e = a ^ b INT
print e INT
f = a << b INT
print f INT
g = a >> b INT
print g INT

return 0 INT

end:

----------------- (code of mul_div.tac)
- FLOAT x
x = -4.3 FLOAT
- FLOAT y
y = 2.0 FLOAT
- FLOAT z
z = x / y FLOAT
print z FLOAT
- FLOAT Z
Z = x * y FLOAT
print Z FLOAT

return 0 INT
