#include <stdio.h>
#include <stdlib.h>

int change(const int, int, int);

int main(int argc, char **argv) {
	
	int *i = (int*)malloc(sizeof(int));
	int *p = (int*)malloc(sizeof(int));
	int *n = (int*)malloc(sizeof(int));

	printf("Enter the integer: ");
	scanf("%d", i);
	printf("Enter the position: ");
	scanf("%d", p);
	printf("Enter the amount of bits you want to invert: ");
	scanf("%d", n);

	printf("Inverted integer: \t %d \n", change(*i, *p, *n));
	
	free(i);
	free(p);
	free(n);

	return 0;
}

int change(const int i, int p, int n) {
	
	int mask = ~(~0 << n) << p;
	return i ^ mask;
	
}