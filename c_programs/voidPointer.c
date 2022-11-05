#include<stdio.h>

int main(void){
	int a = 10;
	int *intp = &a;
	void *voidp = intp;

	printf("%d\n", (*(int *)voidp)++ + 5);
	printf("%d\n", *(int *)voidp);

	return 0;
}