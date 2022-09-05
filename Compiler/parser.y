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

%union{
    struct node { 
        string lexeme;
        string token;
        string type;
        int line_number;
        char type;    // category : keyword K; variable V; Constant C; Functions V
    } node;
}


%token <node> INT RETURN NUMBER ID LEFTSHIFT RIGHTSHIFT LE GE EQ NE GT LT AND OR ADD SUBTRACT DIVIDE MULTIPLY MODULO BITAND BITOR NEGATION XOR STR CHARACTER

%type <node> Program func func_list func_prefix param_list param stmt_list stmt declaration return_stmt data_type expr postfix_expr primary_expr unary_expr unary_op const assign

%right ASSIGN
%left OR
%left AND
%left EQ NE
%left LE GE LT GT
%left ADD SUBTRACT
%left MULTIPLY DIVIDE MODULO

%%

Program         :   func_list   {}
 
func_list       :   func_list func  {}
                    |
                    ;

func            :   func_prefix OF stmt_list CF
 
func_prefix     :   data_type ID OC param_list CC
 
param_list      :   param_list COMMA param 
                    | param  
                    |
                    ;
 
param           :   data_type ID 
                    | data_type ID OS CS COLON INT ID
                    ;
 
stmt_list       :   stmt stmt_list 
                    | 
                    ;
 
stmt   		    :   declaration 
                    | data_type ID ASSIGN expr SCOL 
                    | assign SCOL 
                    | expr SCOL 
                    | return_stmt SCOL 
                    ;
 
declaration     :   data_type ID SCOL 
                    | data_type ID OS INT_NUM CS SCOL
                    ;
                   
return_stmt     :   RETURN expr
                    ;
 
data_type       :   INT 
                    | FLOAT 
                    | CHAR
                    ;
               
 
/* Expressions */
expr      	    :   expr ADD expr 
                    | expr SUBTRACT expr 
                    | expr MULTIPLY expr 
                    | expr DIVIDE expr 
                    | expr LE expr 
                    | expr GE expr 
                    | expr LT expr 
                    | expr GT expr 
                    | expr EQ expr 
                    | expr NE expr 
                    | expr AND expr 
                    | expr OR expr 
                    | expr MODULO expr 
                    | unary_expr 
                    | primary_expr 
                    | postfix_expr
                    ;
 
postfix_expr    :   func_call 
                    | arr
                    ;
 
unary_expr      :   unary_op postfix_expr 
                    | unary_op primary_expr
                    ;
 
primary_expr    :   ID 
                    | const 
                    | OC expr CC
                    ;
 
unary_op        :   ADD 
                    | SUBTRACT 
                    | NOT
                    ;
 
const           :   INT_NUM 
                    | FLOAT_NUM 
                    | CHARACTER
                    ;
                   
assign          :   ID ASSIGN expr 


%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
