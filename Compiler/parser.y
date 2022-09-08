%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <vector>
    #include <string.h>

    #define add_tac($$, $1, $2, $3) {strcpy($$.type, $1.type);\
                                        sprintf($$.lexeme, "@t%d", variable_count);\
                                        variable_count++;\
                                        tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " " + string($2.lexeme) + " " + string($3.lexeme) + " " + string($$.type));}
    
    #include <iostream>
    #include <string>
    #include <unordered_map>

    using namespace std;

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int yytext();

    bool check_declaration(string variable);

    struct var_info {
        string data_type;
        int line_number; 
    };
    vector<string> tac;
    unordered_map<string, struct var_info> symbol_table;
    int variable_count = 0;
    int label_counter = 0;
    vector<string> sem_errors;

    extern int countn;
%}

%union{
    struct node { 
        char lexeme[100];
        int line_number;
        char type[100];
        char if_body[5];
        char elif_body[5];
		char else_body[5];
        // char loop_body[5];
        char parentNext[5];
    } node;
}


%token <node> INT CHAR FLOAT RETURN INT_NUM ID LEFTSHIFT RIGHTSHIFT LE GE EQ NE GT LT AND OR NOT ADD SUBTRACT DIVIDE MULTIPLY MODULO BITAND BITOR NEGATION XOR STR CHARACTER CC OC CS OS CF OF COMMA COLON SCOL PRINT SCAN SWITCH CASE BREAK DEFAULT IF ELIF ELSE

%type <node> Program func func_list func_prefix param_list param stmt_list stmt declaration return_stmt data_type expr primary_expr unary_expr unary_op const assign if_stmt elif_stmt else_stmt

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
                    | if_stmt
                    ;

// switch_stmt     :   SWITCH OC ID CC OF case_stmt_list default_stmt CF
//                     ;

// case_stmt_list  :   case_stmt
//                     |
//                     ;

// case_stmt       :   CASE const COLON stmt_list break_stmt

// break_stmt      :   BREAK
//                     |
//                     ;

// default_stmt    :   DEFAULT COLON stmt_list
//                     |
//                     ;          
 
declaration     :   data_type ID SCOL {
                        strcpy($2.type, $1.type);
                        tac.push_back("- " + string($1.type) + " " + string($2.lexeme));
                        symbol_table[string($2.lexeme)] = { string($1.type), countn+1 };
                    }
                    | data_type ID ASSIGN expr SCOL {
                        tac.push_back("- " + string($1.type) + " " + string($2.lexeme));
                        tac.push_back(string($2.lexeme) + " = " + string($4.lexeme) + " " + string($1.type));
                        symbol_table[string($2.lexeme)] = { string($1.type), countn+1 };
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
                        if(check_declaration(string($1.lexeme))){
                            strcpy($$.type, symbol_table[string($1.lexeme)].data_type.c_str());
                            sprintf($$.lexeme, "@t%d", variable_count++);
                            tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " " + string($$.type));
                        }
                    }
                    | const {
                        strcpy($$.type, $1.type);
                        sprintf($$.lexeme, "@t%d", variable_count++);
                        tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " " + string($$.type)); 
                    }
                    | OC expr CC {
                        strcpy($$.type, $2.type);
                        strcpy($$.lexeme, $2.lexeme);
                    }
                    ;
 
unary_op        :   ADD 
                    | SUBTRACT 
                    | NOT
                    | NEGATION
                    ;
 
const           :   INT_NUM {
                        strcpy($$.type, "INT");
                        strcpy($$.lexeme, $1.lexeme);
                    }
                    | CHARACTER {
                        strcpy($$.type, "CHAR");
                        strcpy($$.lexeme, $1.lexeme);
                    }
                    ;
                   
assign          :   ID ASSIGN expr {
                        check_declaration(string($1.lexeme));
                        tac.push_back(string($1.lexeme) + " = " + string($3.lexeme) + " " + symbol_table[string($1.lexeme)].data_type);
                    }

if_stmt         :   IF  {
                        sprintf($1.parentNext, "L%d", label_counter++);
                    } 
                    OC expr CC { 
                        tac.push_back("if ( " + string($4.lexeme) + " != 0) GOTO L" + to_string(label_counter) + " else GOTO L" + to_string(label_counter+1));
                        sprintf($4.if_body, "L%d", label_counter++);
                        sprintf($4.else_body, "L%d", label_counter++); 
                        tac.push_back("LABEL " + string($4.if_body) + " :");
                    } 
                    OF stmt_list CF {  
                        tac.push_back("GOTO " + string($1.parentNext));
                        tac.push_back("LABEL " + string($4.else_body) + ":");
                    } 
                    elif_stmt  else_stmt {   
                        tac.push_back("LABEL " + string($1.parentNext) + ":");
                    }
                    ;        

elif_stmt       :   ELIF {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf($1.parentNext, "%s", hold);
                    } 
                    OC expr CC {
                        // sprintf(icg[ic_idx++], "\nif (%s != 0) GOTO L%d else GOTO L%d\n", $4.token, label, label+1);
                        tac.push_back("if (" + string($4.lexeme) + " != 0) GOTO L" + to_string(label_counter) + " else GOTO L" + to_string(label_counter+1));
                        sprintf($4.if_body, "L%d", label_counter++);
                        sprintf($4.else_body, "L%d", label_counter++); 
                        tac.push_back("LABEL " + string($4.if_body) + ":");
                    } 
                    OF stmt_list CF {
                        tac.push_back("GOTO " + string($1.parentNext));
                        tac.push_back("LABEL " + string($4.else_body) + ":");
                    } 
                    elif_stmt  
                    |
                    ;

else_stmt       :   ELSE OF stmt_list CF
                    |
                    ;                    

%%

int main(int argc, char *argv[]) {
    // yydebug = 0;
    yyparse();
    for(auto x: tac)
        cout << x << endl;
    for(auto item: sem_errors)
        cout << item << endl;
    for(auto item: symbol_table)
        cout << item.first << "-->" << item.second.data_type << endl;
}

bool check_declaration(string variable){
    if(symbol_table.find(variable) == symbol_table.end()){
        sem_errors.push_back("Variable not declared in line " + to_string(countn+1) + " before usage.");
        return false;
    }
    return true;
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
