#include <stdio.h>

int main (int arg, char *argv[]) {
    double a = 1.0e32;
    double b = -1.0e32;
    double c = 1.0;

    printf( "%f\n", (a + b) + c );
    printf( "%f\n", a + (b + c) );
}