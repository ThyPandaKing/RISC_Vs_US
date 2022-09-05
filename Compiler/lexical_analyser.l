%{
    #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%

{alpha}({alpha}|{digit})*   { return ID; }

%%

int yywrap() {
    return 1;
}
