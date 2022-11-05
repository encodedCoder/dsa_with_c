#include <stdio.h>

void main(){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	if(num<0){
		printf("Number is negative\n");
		num = -num;
	}
	else
		printf("Number is positive\n");

	printf("magnitude of the number is: %d\n", num);
}