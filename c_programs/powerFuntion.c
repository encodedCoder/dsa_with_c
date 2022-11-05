#include <stdio.h>
#define NUMBER 4
#define POWER 2

int power(int, int);

void main(){
	printf("The value power(NUMBER, POWER) = %d\n", power(NUMBER, POWER));
}

int power(int x, int y){
	if (y >= 2)
		return x*power(x, --y);
	else if (y == 1)
		return x;
}