/**
 *This program makes a variable for each of the following types: 
 * char, short, int, long, float, and double
 * and then prints out the value of each variable in hexdecimal
 * it does this so we can observe the endianess of my computer
 * 
 * Zachary Berg
 * 02/10/2025 
 */

#include <stdio.h>
#include <stdlib.h>
        
/* As stated above
 */ 
int main (int arg, char *argv[]) {
    char c = 'Z';       //For Zach
    short s = 333;      //CS333
    int i = 333;        //CS333       
    long l = 65536;     //2^16
    float f = 3.14;     //pi
    double d = 2.72;    //e

    unsigned char *ptr;

    //%02X causes program to print in hexdecimal format
    int j;

    printf("Char \n");
    ptr = (unsigned char *)&(c);
    for(j=0; j<sizeof(char); j++){
        printf("%d: %02X\n", j, ptr[j]);
    }

    printf("Short \n");
    ptr = (unsigned char *)&(s);
    for(j=0; j<sizeof(short); j++){
        printf("%d: %02X\n", j, ptr[j]);
    }

    printf("Int \n");
    ptr = (unsigned char *)&(i);
    for(j=0; j<sizeof(int); j++){
        printf("%d: %02X\n", j, ptr[j]);
    }

    printf("Long \n");
    ptr = (unsigned char *)&(l);
    for(j=0; j<sizeof(long); j++){
        printf("%d: %02X\n", j, ptr[j]);
    }

    printf("Float \n");
    ptr = (unsigned char *)&(f);
    for(j=0; j<sizeof(float); j++){
        printf("%d: %02X\n", j, ptr[j]);
    }

    printf("Double \n");
    ptr = (unsigned char *)&(d);
    for(j=0; j<sizeof(double); j++){
        printf("%d: %02X\n", j, ptr[j]);
    }
    return 0;
}  