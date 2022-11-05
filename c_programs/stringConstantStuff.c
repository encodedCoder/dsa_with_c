#include<stdio.h>

int main(void){

	char *p = "suresh"  " "  "Rao";

	printf("%c\t", "suresh"[2]);

	printf("%c\t", *(("suresh")+2));

	printf("%s\t", ("suresh")+2);

	printf("%s\t", &("suresh"[2]));;;;

	printf("%s\n", "suresh" "rao");

	printf("%s\n", p);
	return 0;
}