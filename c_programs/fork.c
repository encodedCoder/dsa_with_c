#include <stdio.h>
#include <unistd.h>

int main(void){
	int i;
	i = fork();
	if(i == 0){
		printf("Hello\n");
	}
	else if(i > 0){
		printf("Namaste\n");
	}
	printf("Hi....\n");
	return 0;
}
