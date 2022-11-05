#include <stdio.h>
#include <stdlib.h>

void stringCopyFrom_X_to_Y(char *x, char *y){
	while((*y++ = *x++) != '\0');
}

int main(void){
	char *x = "suresh2";
	char *y = (char *)malloc(sizeof(char)*7);

	stringCopyFrom_X_to_Y(x, y);

	printf(y);
	
	return 0;
}