#include <stdio.h>

void fizzbuzz(int n){
	int i;
	for (i = 1; i<= n; ++i)
	{
		if(!(i%3) && !(i%5))
			printf("FizzBuzz\n");
		else if(!(i%3))
			printf("Fizz\n");
		else if(!(i%5))
			printf("Buzz\n");
		else
			printf("%d\n", i);
	}
}

int main(){
	fizzbuzz(15);
	return 0;
}