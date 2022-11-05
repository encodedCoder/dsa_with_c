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

	FILE *fptr = fopen(filePath, fileWriteMode);

	if(fptr == NULL){
		printf("There was some problem in opening the file.\\n------Exiting the program now------");
		exit(0);
	}else{
		printf("File opened successfully in \"%s\" mode.\n", fileWriteMode);
	}

	FILE *f_ch = fptr;

	char *ch;
	while((gets(ch)) != '\0')
		fputs(ch, f_ch);

	fclose(fptr);

	return 0;
}