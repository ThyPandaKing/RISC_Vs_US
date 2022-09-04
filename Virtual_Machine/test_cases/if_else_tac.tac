int main(){
	int a = 1;
	int b;
	
	if(a == 1){
		b = 1;
	}
	else if(a == 2){
		b = 2;
	}
	else{
		b = 0;
	}
	return 0;
}

---------------------------------------

.global main

main:

- INT a
a = 1 INT
- INT b

@t1 = a <= 1

if @t1 GOTO #L1 else GOTO #L2
#L1:
b = 1 INT

#L2:
@t2 = a == 2
if @t2 == 2 GOTO #L3 else GOTO #L4

#L3:
b = 2 INT

#L4:
b = 0 INT

return 0 INT

end:

