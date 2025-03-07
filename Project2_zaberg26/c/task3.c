/**
* HTML Parser
* Strips inputed HTML file of tags, single line comments,
* and extraneous whitespace
*/

%{
int newline = 0;
int startoffile = 1;
int line = 1;
%}

%%
"<"!--([^-]|-[^-]|--+[^->])*--+">" { /* Removes html comments */ }
"<"(h[1-6]|title|ul|ol|li|p)[^>]*">" { if(!startoffile) newline = 1; /* removes html tags and add newline for headers, titles, lists begining, list items, and paragraphs */}
"<"[^>]*">" { /* Removes html tags */ }
[\t]+ { /* printf("\t"); /* Removes extra tabs */ }
[ ]+ { printf(" "); /* Removes extra spaces */ }
\n {line ++; /* FOR NEWLINES nothing to print because we want to remove native newlines and only do newlines tag dependant */ }
"&gt;" { printf(">"); }
"&lt;" { printf("<"); }
"&ge;" { printf("≥"); }
"&le;" { printf("≤"); }
"&amp;" { printf("&"); }
. { if (newline) { newline = 0; printf("\n"); } printf("%c", *yytext); startoffile = 0; }
%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
    }

    yylex();

    printf("\n"); //because final newline is not printed by yylex

    fclose(yyin);
    
    return 0;
}