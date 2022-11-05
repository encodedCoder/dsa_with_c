#include<stdio.h>

int main(void){
	int a[3][4] = {{ 1, 2, 3, 4}, { 5, 6, 4, 8}, {9,10,11,12}};

	// printf("%d\n\n", sizeof(int));
	
	// printf("%p\n", a);
	// printf("%p\n", a+1);
	// printf("%p\n", a+2);
	// printf("\n");

	// printf("%p\n", *(a+0)+1);
	// printf("\n");

	// printf("%p\n", a[0]);
	// printf("%p\n", a[1]);

	printf("%d\t", a[0][0]);
	printf("%d\n", *(*(a+0)+0));

	printf("%d\t", a[2][3]);
	printf("%d\n", *(*(a+2)+3));

	return 0;
}