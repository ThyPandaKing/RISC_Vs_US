int main(){
	char a = 'a';
	int b = 0;
	
	return 0;
}

-------------------------

.global main

main:

- CHAR a
a = 'a' CHAR
- INT b
b = 0 INT

return 0 INT

end:
