/**
 * This program creates 3 variables
 * I made these variables have a value of
 * 1, 2, and 3, so that they are easier to spot
 * because reading hex is a hassle
 * it also has a point that is assigned itself
 * you use this to look at the memory
 * and investiage how the stack works in c
 *
 * Zachary Berg
 * 02/17/2025 
 */

#include <stdio.h>
#include <stdlib.h>
        
/* A short description of the function, if necessary
 */ 
int main (int arg, char *argv[]) {
                    
    // your stuff here	
    int fake = 1;
    int cringe = 2;
    int nope = 3;

    unsigned char *ptr = (unsigned char *)&ptr;

    for (int i = 0; i < 100; i++) {
        printf("%d: %02X\n", i, ptr[i]);
    }
                    
    return 0;
}  