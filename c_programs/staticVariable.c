#include <stdio.h>

static int a = 89;

void func(void);

void main(){
	printf("%d\n", a);

	static int a = 10;
	printf("%d\n", a);
	
	func();
	printf("%d\n", a);
	
	func();
	printf("%d\n", a);
}

void func(void){
	a++;
	printf("%d-------\n", a);
}