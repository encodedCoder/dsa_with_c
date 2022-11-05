#include <stdio.h>

char str1[100];

char *mystery(char str[]){
	static int i = 0;
	if(*str){
		mystery(str+1);
		str1[i++] = *str;
	}
	return str1;
}


int main(void){
	char str[] = "ehT etaG kooB";
	printf("%s\n", mystery(str));

	char s[10];
	printf("%s\n", s);

	return 1;
}