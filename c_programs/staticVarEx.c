#include <stdio.h>

void main(){
	static int a[10];

	int i = 0;

	a[i] = ++i;

	printf("%d %d %d\n", a[0], a[1], a[2]);
}