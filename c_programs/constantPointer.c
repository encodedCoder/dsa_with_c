#include <stdio.h>

int main(void){
	int a[3] = {1, 2, 3};
	
	const int *b = a;
	printf("%d\n", *b);

	b++;
	printf("%d\n", *b);
	
	return 0;
}