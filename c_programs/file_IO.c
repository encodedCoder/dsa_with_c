#include <stdio.h>
#include <stdlib.h>

int main(void){

	char *filePath = "C:\\Users\\Suresh\\Documents\\c_Programs\\__c_HelloWorld.c";

	char *fileWriteMode      = "w";	
	char *fileReadMode       = "r";
	char *fileAppendMode     = "a";
	char *fileWriteReadMode  = "w+";
	char *fileReadWriteMode  = "r+";
	char *fileAppendReadMode = "a+";

	FILE *fptr = fopen(filePath, fileReadMode);

	if(fptr == NULL){
		printf("There was some problem in opening the file.\\n------Exiting the program now------");
		exit(0);
	}else{
		printf("File opened successfully in \"%s\" mode.\n", fileReadMode);
	}

	FILE *f_ch = fptr;

	char ch;
	while((ch = fgetc(f_ch)) != EOF)
		printf("%c", ch);;

	fclose(fptr);

	return 0;
}