#include <stdio.h>

int foo(int num){
	return num & num | 1;
}

void main(){
	printf("%d\n", foo(12));
}