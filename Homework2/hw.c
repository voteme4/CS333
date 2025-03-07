#include <stdio.h>

int main (int arg, char *argv[]) {
	int i = 3;
	int * ptr = &i;
	printf("%u\n", *ptr);
}