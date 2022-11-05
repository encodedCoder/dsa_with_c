#include <stdio.h>

void main(){
	int num = 800547, sum = 0;

	while(num != 0){
		sum += (num%10);
		num /= 10;
	}

	printf("%d\n", sum);
}