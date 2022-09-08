%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <vector>
    #include <string.h>
    // #include "lex.yy.c"

    #define add_tac($$, $1, $2, $3) {strcpy($$.type, $1.type);\
                                        sprintf($$.lexeme, "@t%d", variable_count);\
                                        variable_count++;\
                                        tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " " + string($2.lexeme) + " " + string($3.lexeme) + " " + string($$.type));}
    
    #include <iostream>
    #include <string>

    using namespace std;

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int yytext();

    vector<string> tac;
    int variable_count = 0;
%}

%union{
    struct node { 
        char lexeme[100];
        int line_number;
        char type[100];
    } node;
}


%token <node> INT CHAR FLOAT RETURN INT_NUM ID LEFTSHIFT RIGHTSHIFT LE GE EQ NE GT LT AND OR NOT ADD SUBTRACT DIVIDE MULTIPLY MODULO BITAND BITOR NEGATION XOR STR CHARACTER CC OC CS OS CF OF COMMA COLON SCOL PRINT SCAN

%type <node> Program func func_list func_prefix param_list param stmt_list stmt declaration return_stmt data_type expr primary_expr unary_expr unary_op const assign

%right ASSIGN
%left OR
%left AND
%left BITOR
%left XOR
%left BITAND
%left EQ NE
%left LE GE LT GT
%left ADD SUBTRACT
%left MULTIPLY DIVIDE MODULO
%left NEGATION

%%

Program         :   func_list   {}
 
func_list       :   func_list func  {}
                    |
                    ;

func            :   func_prefix OF stmt_list CF {
                        tac.push_back("end:");
                    }
 
func_prefix     :   data_type ID {tac.push_back(string($2.lexeme) + ":");} OC param_list CC {
                        strcpy($$.lexeme, $2.lexeme);
                    }
 
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
                    | assign SCOL 
                    | expr SCOL 
                    | return_stmt SCOL 
                    ;
 
declaration     :   data_type ID SCOL {
                        strcpy($2.type, $1.type);
                        tac.push_back("- " + string($1.type) + " " + string($2.lexeme));
                    }
                    | data_type ID ASSIGN expr SCOL {
                        tac.push_back("- " + string($1.type) + " " + string($2.lexeme));
                        tac.push_back(string($2.lexeme) + " = " + string($4.lexeme) + " " + string($1.type));
                    }
                    ;
                   
return_stmt     :   RETURN expr {
                        tac.push_back("return " + string($2.lexeme) + " " + string($2.type));
                    }
                    ;
 
data_type       :   INT {
                        strcpy($$.type, "INT");
                    }
                    | FLOAT {
                        strcpy($$.type, "FLOAT");
                    }
                    | CHAR {
                        strcpy($$.type, "CHAR");
                    }
                    ;
               
 
/* Expressions */
expr      	    :   expr ADD expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr SUBTRACT expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr MULTIPLY expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr DIVIDE expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr LE expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr GE expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr LT expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr GT expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr EQ expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr NE expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr AND expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr OR expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr MODULO expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr BITAND expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr BITOR expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr XOR expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | unary_expr {
                        strcpy($$.type, $1.type);
                        strcpy($$.type, $1.type);
                        sprintf($$.lexeme, "%s", $1.lexeme);
                    }
                    | primary_expr {
                            strcpy($$.type, $1.type);
                            strcpy($$.type, $1.type);
                            strcpy($$.lexeme, $1.lexeme);
                        }
 
unary_expr      :   unary_op primary_expr {
                        // strcpy($$.type, $2.type);
                        // tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " " + string($2.lexeme) + " " + string($$.type));
                    }
                    ;
 
primary_expr    :   ID {
                        // strcpy($1.type, get_type($1.lexeme));
                        sprintf($$.lexeme, "@t%d", variable_count);
                        tac.push_back(string($$.lexeme) + " = " + string($1.lexeme));
                        variable_count++;
                        
                        strcpy($$.type, $1.type);
                    }
                    | const {
                        sprintf($$.lexeme, "@t%d", variable_count);
                        tac.push_back(string($$.lexeme) + " = " + string($1.lexeme));
                        variable_count++;
                        
                        strcpy($$.type, $1.type);
                    }
                    | OC expr CC {
                        strcpy($$.type, $1.type);
                        strcpy($$.lexeme, $1.lexeme);
                    }
                    ;
 
unary_op        :   ADD 
                    | SUBTRACT 
                    | NOT
                    | NEGATION
                    ;
 
const           :   INT_NUM {
                        strcpy($$.type, "INT");
                        // $$.lexeme = "@t" + variable_count;
                        // variable_count++;
                        // tac.push_back($$.lexeme + " = " + $1.lexeme + " " + $$.type + "\n);
                    }
                    | CHARACTER {
                        strcpy($$.type, "CHAR");
                        // $$.lexeme = "@t" + variable_count;
                        // variable_count++;
                        // tac.push_back($$.lexeme + " = " + $1.lexeme + " " + $$.type + "\n);
                    }
                    ;
                   
assign          :   ID ASSIGN expr {
                        // strcpy($1.type, get_type($1.lexeme));
                        sprintf($$.lexeme, "@t%d", variable_count);
                        variable_count++;
                        tac.push_back(string($1.lexeme) + " = " + string($3.lexeme) + " " + string($1.type));
                    }

%%

int main(int argc, char *argv[]) {
    // yydebug = 0;
    yyparse();
    for(auto x: tac)
        cout << x << endl;
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
