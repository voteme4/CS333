/**
 * Defines 3 structs
 * CoolStruct, LameStruct, and NormalStruct
 * to investigate how c handles the memory
 * of structs depending on how the variables
 * are ordered.
 *
 * Zachary Berg
 * 02/19/2025 
 */

#include <stdio.h>
#include <stdlib.h>
        
struct CoolStruct {
    char a;
    char b;
    short n;
    int m;
};

struct LameStruct {
    char a;
    short n;
    char b;
    int m;
};

struct NormalStruct {
    char a;
    short n;
    int m;
    char b;
};

/* A short description of the function, if necessary
 */ 
int main (int arg, char *argv[]) {
    struct CoolStruct *cs_ptr = (struct CoolStruct *)malloc(sizeof(struct CoolStruct));
    
    cs_ptr->a = 'a';
    cs_ptr->b = 'b';
    cs_ptr->n = 1;
    cs_ptr->m = 2;

    unsigned char *mem_prt = (unsigned char *)cs_ptr;
    
    printf("CoolStruct \n");
    for (int i = 0; i < sizeof(struct CoolStruct); i++) {
        printf("%d: %02X\n", i, mem_prt[i]);
    }

    free(cs_ptr);

    struct LameStruct *ls_ptr = (struct LameStruct *)malloc(sizeof(struct LameStruct));

    ls_ptr->a = 'a';
    ls_ptr->b = 'b';
    ls_ptr->n = 1;
    ls_ptr->m = 2;

    mem_prt = (unsigned char *)ls_ptr;

    printf("LameStruct \n");
    for (int i = 0; i < sizeof(struct LameStruct); i++) {
        printf("%d: %02X\n", i, mem_prt[i]);
    }

    free(ls_ptr);

    struct NormalStruct *ns_ptr = (struct NormalStruct *)malloc(sizeof(struct NormalStruct));

    ns_ptr->a = 'a';
    ns_ptr->b = 'b';
    ns_ptr->n = 1;
    ns_ptr->m = 2;

    mem_prt = (unsigned char *)ns_ptr;

    printf("NormalStruct \n");
    for (int i = 0; i < sizeof(struct NormalStruct); i++) {
        printf("%d: %02X\n", i, mem_prt[i]);
    }

    free(ns_ptr);

    return 0;
}  