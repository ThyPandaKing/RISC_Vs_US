%{
    #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%

"print"                     { strcpy(yylval.node.lexeme, yytext); return PRINT; }
"scan"                      { strcpy(yylval.node.lexeme, yytext); return SCAN; }
"int"                       { strcpy(yylval.node.lexeme, yytext); return INT; }
"char"                      { strcpy(yylval.node.lexeme, yytext); return CHAR; }
"return"                    { strcpy(yylval.node.lexeme, yytext); return RETURN; }
[-]?{digit}+                { strcpy(yylval.node.lexeme, yytext); return INT_NUM; }
{alpha}({alpha}|{digit})*   { strcpy(yylval.node.lexeme, yytext); return ID; }


"<<"			            { strcpy(yylval.node.lexeme, yytext); return LEFTSHIFT; }
">>"			            { strcpy(yylval.node.lexeme, yytext); return RIGHTSHIFT; }


"<="                        { strcpy(yylval.node.lexeme, yytext); return LE; }
">="                        { strcpy(yylval.node.lexeme, yytext); return GE; }
"=="                        { strcpy(yylval.node.lexeme, yytext); return EQ; }
"!="                        { strcpy(yylval.node.lexeme, yytext); return NE; }
">"	                        { strcpy(yylval.node.lexeme, yytext); return GT; }
"<"	                        { strcpy(yylval.node.lexeme, yytext); return LT; }
"&&"	                    { strcpy(yylval.node.lexeme, yytext); return AND; }
"||"	                    { strcpy(yylval.node.lexeme, yytext); return OR; }


"+"                         { strcpy(yylval.node.lexeme, yytext); return ADD; }
"-"                         { strcpy(yylval.node.lexeme, yytext); return SUBTRACT; }
"/"                         { strcpy(yylval.node.lexeme, yytext); return DIVIDE; }
"%"                         { strcpy(yylval.node.lexeme, yytext); return MODULO;}
"*"                         { strcpy(yylval.node.lexeme, yytext); return MULTIPLY; }
"="                         { strcpy(yylval.node.lexeme, yytext); return ASSIGN; }


"&"			                { strcpy(yylval.node.lexeme, yytext); return BITAND; }
"|"			                { strcpy(yylval.node.lexeme, yytext); return BITOR; }
"~"			                { strcpy(yylval.node.lexeme, yytext); return NEGATION; }
"^"			                { strcpy(yylval.node.lexeme, yytext);return XOR; }

"!"					        { strcpy(yylval.node.lexeme, yytext); return NOT;}
";"                         { strcpy(yylval.node.lexeme, yytext); return SCOL;}
","                         { strcpy(yylval.node.lexeme, yytext); return COMMA;}
":"                         { strcpy(yylval.node.lexeme, yytext); return COLON;}
"{"                         { strcpy(yylval.node.lexeme, yytext); return OF;}
"("                         { strcpy(yylval.node.lexeme, yytext); return OC;}
"["                         { strcpy(yylval.node.lexeme, yytext); return OS;}
"}"                         { strcpy(yylval.node.lexeme, yytext); return CF;}
")"                         { strcpy(yylval.node.lexeme, yytext); return CC;}
"]"                         { strcpy(yylval.node.lexeme, yytext); return CS;}


\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
["].*["]                    { strcpy(yylval.node.lexeme, yytext); return STR; }
['].[']                     { strcpy(yylval.node.lexeme, yytext); return CHARACTER; }
.                           { ; }

%%

int yywrap() {
    return 1;
}
