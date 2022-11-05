#include <stdio.h>


int find(int x, int y){
	return (x<y)?0:(x-y);
}

void main(){
	printf("%d\n", find(5, find(5,4)));
}