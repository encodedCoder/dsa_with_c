#include <stdio.h>

void main(){
	int i, c, a = 1, b = 1;
	printf("%d %d ", a, b);

	for(i = 1; i <= 10; i++){
		c = a + b, a = b, b = c;
		printf("%d ", b);
	}
}