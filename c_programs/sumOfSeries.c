#include <stdio.h>

void main(){
	int terms, sum = 0, i = 1, term = 1;
	printf("Enter number of terms: ");
	scanf("%d", &terms);


	printf("The series will look for %d terms:-\n", terms);
	printf("%d, ", term);
	while(i <= terms){
		sum += term;
		term += i;
		i++;
		if(i <= terms)
			printf("%d, ", term);
		else
			printf("%d", term);
	}
	printf("\nSum of the above series is: %d\n", sum);
}