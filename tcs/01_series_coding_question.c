#include <stdio.h>
#include <math.h>

void printSeriesUptoN(int);
void printNthTerm(int);

void main(){
	printSeriesUptoN(20);
	printNthTerm(16);
}

void printSeriesUptoN(int n){
	int i = 0;
	while(i < (n/2)){
		printf("%.f, ", pow(2, i));
		printf("%.f, ", pow(3, i));
		++i;
	}
	printf("\n\n");
}

void printNthTerm(int Nth){
	int i = (int)ceil(Nth/2.0);
	if(Nth%2 == 0){
		printf("%.f\n", pow(3, i-1));
	}else{
		printf("%.f\n", pow(2, i-1));
	}
}