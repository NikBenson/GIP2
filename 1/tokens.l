%{
#include "y.tab.h"
%}

digit         [0-9]
number        {digit}+(\.{digit}+)?      /* regex for matching a number */

%%
{number}             { yylval.num = atof(yytext); return NUMBER; }
[+-*/]               { return BINARY_OPERATOR; }
[ \t\n\r]            /* skip whitespace */
%%

int yywrap(void) { return 1; }
