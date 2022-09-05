%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    #include <iostream>
    #include <string>
    using namespace std;
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
%}

%token ID

%%

value: ID{cout << "hi" << endl;};

%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
