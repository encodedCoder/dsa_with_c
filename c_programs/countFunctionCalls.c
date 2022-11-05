#include<stdio.h>

int count;

int countFunction(){
	return count++;
}

int main(void){
	countFunction();
	countFunction();
	countFunction();

	printf("%d\n", count);

	return 0;
}