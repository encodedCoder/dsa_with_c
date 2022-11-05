#include <stdio.h>

int fun():

static int num;

void main(){
	num = 10;
	printf("%d\n", num);

	fun();
}

int fun(){
	return num--;
}