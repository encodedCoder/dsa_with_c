#include<stdio.h>
#define NUMBER 5
#define POWER 0

int power(int num, int powr){
	if(powr == 0)
		return 1;
	if(powr == 1)
		return num;
	return num * power(num, powr-1);
}

void main(void){
	printf("Result of %d raise to the %d is: %d\n",NUMBER, POWER, power(NUMBER, POWER));
}