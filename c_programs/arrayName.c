#include<stdio.h>

int main(void){
	int a[5] = {1,2,3,4,5,};
	printf("%p\n", &a[0]);
	printf("%p\n", &(*(a+0)));
	printf("%p\n", &a);
	printf("%p\n", a);
	return 0;
}