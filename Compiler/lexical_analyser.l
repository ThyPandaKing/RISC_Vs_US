%{
    #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%

"printf"                    { return PRINTFF; }
"scanf"                     { return SCANFF; }
"int"                       { return INT; }
"return"                    { return RETURN; }
[-]?{digit}+                { return NUMBER; }
{alpha}({alpha}|{digit})*   { return ID; }


"<<"			            { return LEFTSHIFT; }
">>"			            { return RIGHTSHIFT; }


"<="                        { return LE; }
">="                        { return GE; }
"=="                        { return EQ; }
"!="                        { return NE; }
">"	                        { return GT; }
"<"	                        { return LT; }
"&&"	                    { return AND; }
"||"	                    { return OR; }


"+"                         { return ADD; }
"-"                         { return SUBTRACT; }
"/"                         { return DIVIDE; }
"*"                         { return MULTIPLY; }


"&"			                { return BITAND; }
"|"			                { return BITOR; }
"~"			                { return NEGATION; }
"^"			                { return XOR; }


\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
.	                        { return *yytext; }
["].*["]                    { return STR; }
['].[']                     { return CHARACTER; }

%%

int yywrap() {
    return 1;
}
