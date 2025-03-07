/**
* Clite Parser
* transforms cslite code into a sequence of strings, one per line
* based on clite rules
*/

%{
#include <stdio.h>
%}

/* this is neater imo */

INTEGER         [0-9]+
FLOAT           [0-9]+\.[0-9]+
KEYWORD         "if"|"else"|"while"|"for"|"int"|"float"
IDENTIFIER      [a-zA-Z_][a-zA-Z_0-9]*
ASSIGNMENT      "="
COMPARISON      "=="|"<"|">"|"<="|">="
OPERATOR        "+"|"-"|"*"|"/"
OPEN_BRACKET    "{"
CLOSE_BRACKET   "}"
OPEN_PAREN      "("
CLOSE_PAREN     ")"
NEWLINE         "\n"

%%
{FLOAT}         { printf("Float-%s\n", yytext); }
{INTEGER}       { printf("Integer-%s\n", yytext); }
{KEYWORD}       { printf("Keyword-%s\n", yytext); }
{IDENTIFIER}    { printf("Identifier-%s\n", yytext); }
{ASSIGNMENT}    { printf("Assignment\n"); }
{COMPARISON}    { printf("Comparison-%s\n", yytext); }
{OPERATOR}      { printf("Operator-%s\n", yytext); }
{OPEN_BRACKET}  { printf("Open-bracket\n"); }
{CLOSE_BRACKET} { printf("Close-bracket\n"); }
{OPEN_PAREN}    { printf("Open-paren\n"); }
{CLOSE_PAREN}   { printf("Close-paren\n"); }
{NEWLINE}       { /* ignore newlines */ }
.               { /* not recognized token do nothing */ }
%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
    }

    yylex();

    fclose(yyin);
    return 0;
}