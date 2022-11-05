#include <stdio.h>

void main(){
	int num, tNum = 2, flag = 0;
	printf("Enter a numer: ");
	scanf("%d", &num);

	if(num == 0){
		printf("Neither Prime nor Composite.\n");
		return;
	}

	while(tNum*tNum == num){
		if(num%tNum == 0){
			flag = 1;
			break;
		}
	}

	if(flag)
		printf("Composite Number.\n");
	else
		printf("Prime Number.\n");
}