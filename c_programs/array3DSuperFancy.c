#include<stdio.h>

int main(void){
	char arr[2][3][3] = {'A', 'P', 'P', 'L', 'I', 'E', 'D', ' ', 'C', 'O', 'U', 'R', 'S', 'E'};
	char (*p)[2][3][3] = &arr;

	printf("%d\n", (*(*(*p)[0] + 5)) - (*(*(*p)[1] - 3)));
	
	return 0;
}


// (*(*(*p)[0] + 5))