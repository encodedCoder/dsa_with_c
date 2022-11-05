#include<stdio.h>
#include<conio.h>

int fact(int num){
	if(num == 0){
		return 1;
	}else{
		if(num > 2){
			int tNum = num-1;
			return (num * fact(tNum));
		}else if(num == 1){
			return 1;
		}else{
			return 2;	
		}}
}


void main(){
	int terms;
	printf("Enter the number of terms of series: ");
	scanf("%d", &terms);

	printf("Series for %d terms is: ", terms);
	int i, sum = 0, term;
	for(i = 1; i <= terms; i++){
		term = fact(i);
		sum += term;
		if(i < terms)
			printf("%d, ", term);
		else
			printf("%d\n", term);
	}
	printf("Sum of above series is: %d", sum);
}