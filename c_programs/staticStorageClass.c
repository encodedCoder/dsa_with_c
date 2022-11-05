#include <stdio.h>

void func(void){
	a++;
}

void main(){
	static int a = 10;
	func();
	printf("%d\n", a);
}