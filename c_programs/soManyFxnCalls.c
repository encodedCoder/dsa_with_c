#include <stdio.h>

int fun(){
	int static num = 10;
	return num--;
}

void main(){
	for(fun(); fun(); fun())
		printf("%d ", fun());
}