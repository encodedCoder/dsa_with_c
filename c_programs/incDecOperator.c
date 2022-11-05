#include <stdio.h>

void main(){
	int a = 6;
	a -= (a--) - (--a);
	printf("%d\n", a);
}