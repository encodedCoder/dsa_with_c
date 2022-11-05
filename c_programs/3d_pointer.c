#include <stdio.h>

int main(void){

	char A[5][7][6];
	char *P[5][7][6];
	printf("%d\n", sizeof(*P));
	printf ("%d\n",(unsigned)(A+1)-(unsigned)A);
	printf ("%d",(unsigned)(P+1)-(unsigned)P);

	return 0;
}