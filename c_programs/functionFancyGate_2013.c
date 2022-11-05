#include<stdio.h>

int f (int *x, int c) {
	c = c - 1;
	if (c==0) return 1;
	x = x + 1;
	int res = f(x,c);
	return res * x;
}


int main(void){
	int p = 5;
	printf("%d\n", f(&p, p));
	return 0;
}