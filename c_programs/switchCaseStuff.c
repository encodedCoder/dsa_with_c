#include <stdio.h>

int main(void){
	// char c = 'a';

	float f = 4.2;

	switch(f){
		case 4.2: printf("correct\n"); break;
		case 5.2: printf("incorrect\n"); break;
		case default: printf("nothng\n");
	}


	// switch(c){
	// 	 case 'a' && 1: 
	// 	 	printf("Hello.\n");
	// 	 case 'b' && 1: 
	// 	 	printf("Boy.\n");
	// 	 	break;
	// 	 case default: 
	// 	 	printf("nothing.\n");
	// }
	
	return 0;
}