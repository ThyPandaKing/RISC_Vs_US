int main(){
	int a = 2;
	int b = -3;
	
	int c;
	
	c = a * b;
	c = a / b;
	c = a + b - a * b;
	
	return 0;
}

---------------------------------

.global main

main:

- INT a
a = 2 INT
- INT b
b = - 3 INT
- INT c

c = a * b INT
c = a / b INT

@t0 = a * b INT
@t1 = a + b INT
c = @t1 - @t0 INT

return 0 INT

end:
