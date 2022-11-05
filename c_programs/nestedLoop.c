#include <stdio.h>

void main(){
	int i, j, count = 0;

	for(i = 1; i <= 5; i++)
		for(j = 1; j <= 3; j++)
			count++;
	printf("%d\n", count);
}