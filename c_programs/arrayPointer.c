#include <stdio.h>

int main(void){

	static char *s[] = {"black", "white", "yellow", "voilet"};
	char **ptr[] = {s+3, s+2, s+1, s}, ***p;
	p = ptr;
	**++p;
	printf("%s\n", *--*++p + 3);
	return 0;
}