#include <stdio.h>
#include <string.h>

void printlength(char *s, char *t) {
	unsigned int c=0;
	int len = ((strlen(s) - strlen(t)) > c) ? strlen(s) : strlen(t);
	printf("%d\n", len);
}


void main() {
	char *x = "abc";
	char *y = "defgh";
	printlength(x,y);
}