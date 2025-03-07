/**
 * Memory leak simulator
 * Allocates memory in a loop to a single variable
 * frees at end of loop
 * designed for observing memory usage with top
 *
 * Zachary Berg
 * 02/19/2025 
 */

#include <stdio.h>
#include <stdlib.h>
 
/* 
 * Without free implementation
 */ 
int leakM (int arg, char *argv[]) {
                    
    for (int i = 0; i < 10000000000; i++) {
        printf("%d\n", i);
        char *ptr = malloc(8);
    };
                    
    return 0;
}  

/*
 * With free implementation
 */
int freeM (int arg, char *argv[]) {
                    
    for (int i = 0; i < 10000000000; i++) {
        printf("%d\n", i);
        char *ptr = malloc(8);
        free(ptr);
    };
                    
    return 0;
}

/*
 * Main function to expecute leakM or freeM
 */
int main (int arg, char *argv[]) {
    freeM(arg, argv);
}