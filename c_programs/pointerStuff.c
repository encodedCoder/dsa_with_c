#include <stdio.h>
#include <stdlib.h>
int main(void){

	int *p;
	p = NULL;
	free(p);
	printf("%d\n", *p);
	return 0;
}