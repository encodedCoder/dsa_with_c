#include <stdio.h>

int count = 0;

int main(){
	int count1 = 1, count2;
	while(count1<5){
		count2 = 2;
		while(count2<=5){
			// printf("Here, ");
			count2++;
			count++;
		}
		count1++;
	}
	printf("%d\n", count);
}