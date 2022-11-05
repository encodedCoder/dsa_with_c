#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *a[10];
	// int b = 36;
	
	// a[3] = &b;
	// printf("%d\n", *a[3]);

	
	a[2][3] = 89;
	printf("%d\n", a[2][3]);
	
	
	return 0;
}