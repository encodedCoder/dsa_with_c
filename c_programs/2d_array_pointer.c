#include <stdio.h>

int main(void){

	{	
		int a[5];
		char (*p)[5];
		// printf("%d\n", sizeof(a));
		// printf("%d\n", sizeof(p));
		printf("%p\n", a);
		printf("%p\n", a+1);
		printf("%p\n", &p);
	}

	{
		// char a[5][6];
		// char *p[5][6];
		// printf("%d\n", sizeof(a));
		// printf("%d\n", sizeof(p));
	}


	// printf("%d\n", (unsigned)a+1 - (unsigned)a);
	// printf("%d\n", (unsigned)p+1 - (unsigned)p);


	return 0;
}