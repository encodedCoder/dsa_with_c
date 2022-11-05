#include <stdio.h>

void main(){
	char c = 'a';
	switch(c){
		case 'a' && 1: printf("hello1\n");
		case 'b' && 1: printf("hello2\n");
			break;
		default: printf("none\n");
	}
}