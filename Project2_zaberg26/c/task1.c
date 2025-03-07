/**
* Encode
* Takes any character a-z or A-Z
* and shifts in 13 spaces forward in the alphabet
* to test, use twice and you should get original text
*/

%%
[a-zA-Z] {
    int ascii = *yytext;
    if (ascii >= 'a' && ascii <= 'z') {
        ascii = (ascii - 'a' + 13) % 26 + 'a';
    } else if (ascii >= 'A' && ascii <= 'Z') {
        ascii = (ascii - 'A' + 13) % 26 + 'A';
    }
    *yytext = ascii;
} printf("%c", *yytext);
. printf("%c", *yytext);
%%

int main ( int argc, char *argv[] ) {

	yylex();

    fclose(yyin);

	return 0;

}