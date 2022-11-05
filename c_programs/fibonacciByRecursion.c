#include <stdio.h>

int fibonacci(int num);

void main(){
	fibonacci(5);
}

int fibonacci(int nTerm){
	int term;
	if(nTerm == 0){
		term = 0;
	}
	else if(nTerm == 1){
		term = 1;
	}
	else{
		term = fibonacci(nTerm-2) + fibonacci(nTerm-1);
	}
	// printf("%d\t", term);
	return term;
}