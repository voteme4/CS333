/**
* Vowels
* Counts rows, chars, and each vowel in a given textfile
*/

%{
int rows = 1;
int chars = 0;
int vowels[5] = {0, 0, 0, 0, 0};
%}

%%
\n {rows++; chars++;}
[aA] {vowels[0]++; chars++;}   
[eE] {vowels[1]++; chars++;}
[iI] {vowels[2]++; chars++;}
[oO] {vowels[3]++; chars++;}
[uU] {vowels[4]++; chars++;}
. {chars++;}
%%

int main ( int argc, char *argv[] ) {

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
    }

	yylex();

    printf("Rows: %d\n", rows);
    printf("Chars: %d\n", chars);
    printf("Vowels: a: %d e: %d i: %d o: %d u: %d\n",
        vowels[0], vowels[1], vowels[2], vowels[3], vowels[4]
    );

    fclose(yyin);
    
	return 0;

}