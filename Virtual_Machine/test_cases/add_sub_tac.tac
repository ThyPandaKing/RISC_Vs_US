int main(){
	int a = 2;
	int b = -3;
	
	int c;
	
	c = a + b;
	c = a - b;
	
	return 0;
}

--------------------------------------

.global main

main:

- INT a
a = 2 INT
- INT b
b = 3 INT
- INT c

c = a + b INT
return 0 INT

end:

