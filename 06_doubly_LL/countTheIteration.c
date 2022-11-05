#include <stdio.h>

void main(){
	int i, j, k, n, count = 0;
	printf("Enter value of n: ");
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			for(k = 1; k <= 100; ++k)
				++count;	
	printf("%d\n", count);	
}