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
    #include <stack>
    #include<algorithm>

    using namespace std;

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int yytext();

    bool check_declaration(string variable);
    bool multiple_declaration(string variable);
    bool is_reserved_word(string id);

    struct var_info {
        string data_type;
        int size;   // for arrays
        int isArray;
        int line_number; 
    };

    vector<string> tac;
    unordered_map<string, struct var_info> symbol_table;

    int variable_count = 0;
    int label_counter = 0;

    vector<string> sem_errors;

    int temp_index;
    int temp_label;

    stack<int> loop_continue, loop_break;

    // for array declaration with initialization
    string curr_array;
    int arr_index=0;

    extern int countn;

    struct func_info{
        string return_type;
        int num_params;
        vector<string> param_types;
        unordered_map<string, struct var_info> symbol_table;
    };

    unordered_map<string, struct func_info> func_table;
    string curr_func_name;

    vector<string> reserved = {"int", "float", "char", "void", "if", "elif", "else", "for", "while", "break", "continue", "main", "return", "switch", "case", "input", "output"};

%}

%union{
    struct node { 
        char lexeme[100];
        int line_number;
        char type[100];
        char if_body[5];
        char elif_body[5];
		char else_body[5];
        char loop_body[5];
        char parentNext[5];
        char case_body[5];
        char id[5];
        char temp[5];
        int nParams;
    } node;
}

%token <node> INT CHAR FLOAT STRING VOID RETURN INT_NUM FLOAT_NUM ID LEFTSHIFT RIGHTSHIFT LE GE EQ NE GT LT AND OR NOT ADD SUBTRACT DIVIDE MULTIPLY MODULO BITAND BITOR NEGATION XOR STR CHARACTER CC OC CS OS CF OF COMMA COLON SCOL OUTPUT INPUT SWITCH CASE BREAK DEFAULT IF ELIF ELSE WHILE FOR CONTINUE

%type <node> Program func func_list func_prefix param_list param stmt_list stmt declaration return_stmt data_type func_data_type expr primary_expr unary_expr unary_op const assign if_stmt elif_stmt else_stmt switch_stmt case_stmt case_stmt_list while_loop_stmt for_loop_stmt postfix_expr func_call

%right ASSIGN
%left OR
%left AND
%left BITOR
%left XOR
%left BITAND
%left EQ NE
%left LE GE LT GT
%left LEFTSHIFT RIGHTSHIFT
%left ADD SUBTRACT
%left MULTIPLY DIVIDE MODULO
%left NEGATION

%%

Program         :   func_list {}
 
func_list       :   func_list func {}
                    |
                    ;

func            :   func_prefix OF stmt_list CF {
                        tac.push_back("end:\n");
                    }
 
func_prefix     :   func_data_type ID 
                    {   
                        if(func_table.find(string($2.lexeme)) != func_table.end()){
                            sem_errors.push_back("Error: Duplicate function name - " + string($2.lexeme));
                        }
                        tac.push_back(string($2.lexeme) + ":"); 
                        curr_func_name = string($2.lexeme);
                    } 
                    OC param_list CC {
                        func_table[curr_func_name].return_type = string($1.type);
                        func_table[curr_func_name].num_params = $5.nParams;
                    }

func_data_type  :   data_type {
                        strcpy($$.type, $1.type);
                    }
                    | VOID {
                        sprintf($$.type, "void");
                    }
                    ;
 
param_list      :   param {
                        func_table[curr_func_name].param_types.push_back(string($1.type));
                        func_table[curr_func_name].symbol_table[string($1.lexeme)] = { string($1.type), 0, 0, countn+1 };
                        tac.push_back("- arg " + string($1.type) + " " + string($1.lexeme));                       
                    }
                    COMMA param_list {
                        $$.nParams = $4.nParams + 1;
                    }
                    | param {
                        $$.nParams = 1;
                        func_table[curr_func_name].param_types.push_back(string($1.type));
                        func_table[curr_func_name].symbol_table[string($1.lexeme)] = { string($1.type), 0, 0, countn+1 };
                        tac.push_back("- arg " + string($1.type) + " " + string($1.lexeme));
                    }
                    | {
                        $$.nParams = 0;
                    }
                    ;
 
param           :   data_type ID {
                        $$.nParams = 1;
                        strcpy($$.type, $1.type);
                        strcpy($$.lexeme, $2.lexeme);
                    }
                    ;
 
stmt_list       :   stmt stmt_list 
                    |
                    ;
 
stmt   		    :   declaration 
                    | assign SCOL 
                    | expr SCOL 
                    | return_stmt SCOL 
                    | if_stmt
                    | while_loop_stmt 
                    | for_loop_stmt
                    | BREAK SCOL {
                        if(!loop_break.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_break.top()));
                        }
                    }
                    | CONTINUE SCOL {
                        if(!loop_continue.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                        }
                    }     
                    | switch_stmt
                    | INPUT OC ID CC SCOL  {
                        check_declaration($3.lexeme);
                        tac.push_back("input " + string($3.lexeme) + " " + symbol_table[string($1.lexeme)].data_type);
                    }
                    | OUTPUT OC expr CC SCOL {
                        tac.push_back("output " + string($3.lexeme) + " " + string($3.type));
                    }
                    ;
 
declaration     :   data_type ID SCOL { 
                        is_reserved_word(string($2.lexeme));
                        multiple_declaration(string($2.lexeme));
                        tac.push_back("- " + string($1.type) + " " + string($2.lexeme));
                        func_table[curr_func_name].symbol_table[string($2.lexeme)] = { string($1.type), 0, 0, countn+1 };
                    }
                    /* | STRING ID ASSIGN STR SCOL {
                        tac.push_back("- STR " + string($2.lexeme));
                        tac.push_back(string($2.lexeme) + " = " + string($4.lexeme) + " STR");
                        func_table[curr_func_name].symbol_table[string($2.lexeme)] = { "STR", string($4.lexeme).length(), 0, countn+1 };
                    } */
                    | data_type ID ASSIGN expr SCOL {
                        is_reserved_word(string($2.lexeme));
                        multiple_declaration(string($2.lexeme));
                        tac.push_back("- " + string($1.type) + " " + string($2.lexeme));
                        tac.push_back(string($2.lexeme) + " = " + string($4.lexeme) + " " + string($1.type));
                        func_table[curr_func_name].symbol_table[string($2.lexeme)] = { string($1.type), 0, 0, countn+1 };
                    }
                    | data_type ID OS INT_NUM CS SCOL {
                        is_reserved_word(string($2.lexeme));
                        multiple_declaration(string($2.lexeme));
                        tac.push_back("- " + string($1.type) + " " + string($2.lexeme) + " [ " + string($4.lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string($2.lexeme)] = { string($1.type), stoi(string($4.lexeme)), 1, countn+1 };
                    }
                    | data_type ID OS INT_NUM CS ASSIGN {
                        is_reserved_word(string($2.lexeme));
                        multiple_declaration(string($2.lexeme));
                        tac.push_back("- " + string($1.type) + " " + string($2.lexeme) + " [ " + string($4.lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string($2.lexeme)] = { string($1.type), stoi(string($4.lexeme)), 1, countn+1 };
                        curr_array = string($2.lexeme);
                    } OF arr_values CF SCOL // array size must be a positive integer 
                    ;

arr_values      :   const {
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string($1.lexeme) + " " + string($1.type));
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(symbol_table[curr_array].size) + "]’");
                        }
                    } 
                    COMMA arr_values
                    | const {
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string($1.lexeme) + " " + string($1.type));
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + "error: too many initializers for ‘array [" + to_string(symbol_table[curr_array].size) + "]’");
                        }
                        arr_index=0;
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
                    | expr LEFTSHIFT expr {
                        add_tac($$, $1, $2, $3)
                    }
                    | expr RIGHTSHIFT expr {
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
                    | postfix_expr {
                        strcpy($$.type, $1.type);
                        sprintf($$.lexeme, "%s", $1.lexeme);
                    }

postfix_expr    :   func_call {
                        strcpy($$.type, $1.type);
                        sprintf($$.lexeme, "%s", $1.lexeme);
                    }
                    |
                    ID OS expr CS {
                        if(check_declaration(string($1.lexeme)) && func_table[curr_func_name].symbol_table[string($1.lexeme)].isArray == 0) { 
                            sem_errors.push_back("Variable is not an array"); 
                        }
                        strcpy($$.type, func_table[curr_func_name].symbol_table[string($1.lexeme)].data_type.c_str());
                        sprintf($$.lexeme, "@t%d", variable_count++);
                        tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " [ " + string($3.lexeme) + " ] " + " " + string($$.type));
                    }
                    ;
 
unary_expr      :   unary_op primary_expr {
                        strcpy($$.type, $2.type);
                        sprintf($$.lexeme, "@t%d", variable_count++);
                        tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " " + string($2.lexeme) + " " + string($$.type));
                    }
                    ;
 
primary_expr    :   ID {
                        check_declaration(string($1.lexeme));
                        strcpy($$.type, func_table[curr_func_name].symbol_table[string($1.lexeme)].data_type.c_str());
                        strcpy($$.lexeme, $1.lexeme);
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
                    | FLOAT_NUM {
                        strcpy($$.type, "FLOAT");
                        strcpy($$.lexeme, $1.lexeme);
                    }
                    | CHARACTER {
                        strcpy($$.type, "CHAR");
                        strcpy($$.lexeme, $1.lexeme);
                    }
                    ;
                   
assign          :   ID ASSIGN expr {
                        check_declaration(string($1.lexeme));
                        tac.push_back(string($1.lexeme) + " = " + string($3.lexeme) + " " + func_table[curr_func_name].symbol_table[string($1.lexeme)].data_type);
                    }
                    |
                    ID OS expr CS ASSIGN expr {
                        if(check_declaration(string($1.lexeme)) && func_table[curr_func_name].symbol_table[string($1.lexeme)].isArray == 0) { 
                            sem_errors.push_back("Line no " + to_string(countn+1) + " : Variable is not an array"); 
                        }
                        tac.push_back(string($1.lexeme) + " [ " + string($3.lexeme) + " ] " + " = " + string($6.lexeme) + " " + func_table[curr_func_name].symbol_table[string($1.lexeme)].data_type);
                    }


if_stmt         :   IF  {
                        sprintf($1.parentNext, "#L%d", label_counter++);
                    } 
                    OC expr CC { 
                        tac.push_back("if " + string($4.lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf($4.if_body, "#L%d", label_counter++);
                        sprintf($4.else_body, "#L%d", label_counter++); 
                        tac.push_back(string($4.if_body) + ":");
                    } 
                    OF stmt_list CF {  
                        tac.push_back("GOTO " + string($1.parentNext));
                        tac.push_back(string($4.else_body) + ":");
                    } 
                    elif_stmt  else_stmt {   
                        tac.push_back(string($1.parentNext) + ":");
                    }
                    ;        

elif_stmt       :   ELIF {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf($1.parentNext, "%s", hold);
                    } 
                    OC expr CC {
                        // sprintf(icg[ic_idx++], "\nif (%s != 0) GOTO L%d else GOTO L%d\n", $4.token, label, label+1);
                        tac.push_back("if " + string($4.lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf($4.if_body, "#L%d", label_counter++);
                        sprintf($4.else_body, "#L%d", label_counter++); 
                        tac.push_back(string($4.if_body) + ":");
                    } 
                    OF stmt_list CF {
                        tac.push_back("GOTO " + string($1.parentNext));
                        tac.push_back(string($4.else_body) + ":");
                    } 
                    elif_stmt  
                    |
                    ;

else_stmt       :   ELSE OF stmt_list CF
                    |
                    ;       

switch_stmt     :   SWITCH {
                        int temp_label = label_counter;
                        loop_break.push(temp_label);
                        sprintf($1.parentNext, "#L%d", label_counter++);
                    } 
                    OC ID {
                        temp_index = variable_count;
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string($4.lexeme));
                    } 
                    CC OF case_stmt_list {
                        // strcpy($8.id, $4.lexeme);
                        // strcpy($8.parentNext, $1.parentNext);
                    }
                    default_stmt CF {
                        tac.push_back("Label " + string($1.parentNext));
                        loop_break.pop();
                    }
                    ;

case_stmt_list  :   case_stmt case_stmt_list {
                        strcpy($1.id, $$.id);
                        strcpy($1.parentNext, $$.parentNext);
                    }
                    |
                    ;

case_stmt       :   CASE {
                        // tac.push_back(string($4.if_body) + ":");
                    } 
                    OC const {
                        char* hold = const_cast<char*>(to_string(variable_count).c_str());
                        sprintf($4.temp, "%s", hold);
                        tac.push_back("@t" + to_string(variable_count++) + " = " + $4.lexeme);
                        tac.push_back("@t" + to_string(variable_count++) + " = " + "@t" + to_string(temp_index) + " == " + "@t" + string($4.temp));
                        tac.push_back("if @t" + to_string(variable_count-1) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        tac.push_back("Label #L" + to_string(label_counter) + ":");
                        sprintf($4.case_body, "#L%d", label_counter++);
                        sprintf($4.parentNext, "#L%d", label_counter++);
                    }
                    CC COLON stmt_list {
                        // tac.push_back("Label " + string($4.parentNext) + ":");
                        tac.push_back("Label " + string($4.parentNext) + ":");
                    } 

default_stmt    :   DEFAULT COLON stmt_list
                    |
                    ;                       

while_loop_stmt :   WHILE {
                        sprintf($1.loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string($1.loop_body) + ":");
                    } 
                    OC expr CC 
                    {
                        sprintf($4.if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf($4.else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string($4.lexeme) + " GOTO " + string($4.if_body) + " else GOTO " + string($4.else_body));
                        tac.push_back("\n" + string($4.if_body) + ":");
                        
                    } 
                    OF stmt_list CF    
                    {
                        tac.push_back("GOTO " + string($1.loop_body));
                        tac.push_back("\n" + string($4.else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }

for_loop_stmt   :   FOR OC assign SCOL {
                        sprintf($1.loop_body, "#L%d", label_counter++); 
                        tac.push_back("\n" + string($1.loop_body) + ":");
                    } 
                    expr SCOL {  
                        sprintf($6.if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf($6.else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string($6.lexeme) + " GOTO " + string($6.if_body) + " else GOTO " + string($6.else_body));

                        sprintf($6.loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string($6.loop_body) + ":");
                    }
                    assign CC {
                        tac.push_back("GOTO " + string($1.loop_body));
                        tac.push_back("\n" + string($6.if_body) + ":");
                    }
                    OF stmt_list CF {
                        tac.push_back("GOTO " + string($6.loop_body));
                        tac.push_back("\n" + string($6.else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }

func_call       :   ID OC arg_list CC  {       
                        sprintf($$.lexeme, "@t%d", variable_count);
                        variable_count++;

                        // checking if function is declared
                        if(func_table.find(string($1.lexeme)) != func_table.end()){
                            printf("ERROR in line %d : Function %s is not declared\n", countn+1, $1.lexeme);
                            exit(0);
                        }

                        tac.push_back(string($$.lexeme) + " = @call " + string($1.lexeme) + " " + func_table[string($1.lexeme)].return_type + " " + to_string(func_table[string($1.lexeme)].num_params));
                    }
                    ;

arg_list        :   arg COMMA arg_list
                    | arg {}
                    | {}
                    ;

arg             :   expr {
                        tac.push_back("param " + string($1.lexeme) + " " + string($1.type));
                    }
                    ;

%%

int main(int argc, char *argv[]) {
    /* yydebug = 1; */
    yyparse();
    for(auto x: tac)
        cout << x << endl;
    for(auto item: sem_errors)
        cout << item << endl;
    /* for(auto item: func_table[curr_func_name].symbol_table)
        cout << item.first << "-->" << item.second.data_type << endl; */
}

bool check_declaration(string variable){
    if(func_table[curr_func_name].symbol_table.find(variable) == func_table[curr_func_name].symbol_table.end()){
        sem_errors.push_back("Variable not declared in line " + to_string(countn+1) + " before usage.");
        return false;
    }
    return true;
}

bool multiple_declaration(string variable){
    if(!(symbol_table.find(variable) == symbol_table.end())){
        sem_errors.push_back("redeclaration of '" + variable + "' in line " + to_string(countn+1));
        return false;
    }
    return true;
}

bool is_reserved_word(string id){
    for(auto &item: id){
        item = tolower(item);
    }
    auto iterator = find(reserved.begin(), reserved.end(), id);
    if(iterator != reserved.end()){
        sem_errors.push_back("usage of reserved keyword '" + id + "' in line " + to_string(countn+1));
        return true;
    }
    return false;
}

void yyerror(const char* msg) {
    sem_errors.push_back("syntax error in line " + to_string(countn+1));
    for(auto item: sem_errors)
        cout << item << endl;
    fprintf(stderr, "%s\n", msg);
    exit(1);
}


// check if void functions has return type