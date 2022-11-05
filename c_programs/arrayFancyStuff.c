#include<stdio.h>

int arraySize(int size){
	return size;
}

int main(void){
	int a = arraySize(5);
	int b[a];

	int i;
	for (i = 0; i < a; ++i){
		b[i] = i;
	}

	for (i = 0; i < a; ++i){
		printf("%d\t", b[i]);
	}
	printf("\n");

	return 0;
}