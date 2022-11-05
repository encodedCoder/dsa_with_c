#include <stdio.h>
//hello //hello
void main(){
	int i = 1, num, sum = 0;
	float avg = 0;

	printf("Enter 5 numbers: \n");
	while(i <= 5){
		printf("Enter number %d: ", i);
		scanf("%d", &num);

		sum += num;
		i++;
	}
	avg = (float)sum/5.0;
	printf("sum: %d\navg: %f\n", sum, avg);
}