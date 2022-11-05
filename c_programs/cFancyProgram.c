#include <stdio.h>
#define print(a) printf("%d ",a)

int a;
void A (int p){
	p += a;
	print (p);
}

void B(int *q){
	int p = *q + 3;
	A (a);
	*q = a-2;
	print (a);
}

void main (void){
	a = 6;
	B(&a);
	print(a);
}