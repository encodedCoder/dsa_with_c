#include<stdio.h>

int main(void){
	int a[2][3] = {1, 2, 3, 4, 5, 6};

	int b[2][3] = {{1, 2, 3}, {4, 5, 6}};

	int i, j;
	for(i = 0; i < 2; ++i){
		for(j = 0; j < 3; ++j){
			printf("%4d", *(*(a+i)+j));
		}
		printf("\n\n");
	}

	printf("\n\n\n");

	for(i = 0; i < 2; ++i){
		for(j = 0; j < 3; ++j){
			printf("%4d", b[i][j]);
		}
		printf("\n\n");
	}

	return 0;
}