#include<stdio.h>
#include<string.h>
void fun1(char *p){
	if(*p){
	fun1(p+1);
	printf("%c",*p++);
	}
}

void fun2(char *p){
	if(*p){
		fun2(p+1);
		printf("%c",*p--);
	}
}

int main(){
	char *str="FLOW";
	fun2(str);
	printf("\t");
	fun1(str);
	return 0;
}