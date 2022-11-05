#include <stdio.h>

void main(){
	int num = 435;
	int count = 0;
	while(num){
		count++;
		num >>= 1;
	}

	printf("%d\n", count);

}