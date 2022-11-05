#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	char * item;
	int top;
	int size;
}Stack;

void initStack(Stack *, int);
void push(Stack *, char);
char pop(Stack *);
int getStackSize(Stack *);
void deallocate(Stack *);
int isOverflow(Stack *);
int isUnderflow(Stack *);
int reverseTextFile(char *, char *);

void main(){
	int i = reverseTextFile("D:\\helloSuresh2.txt", "D:\\helloSuresh3.txt");
	if(i)
		printf("Success reverseTextFile.\n");
	else
		printf("Failes reverseTextFile.\n");
}

void initStack(Stack *sp, int size){
	sp->top = -1;
	sp->size = size;
	sp->item = (char *)malloc(sizeof(char) * sp->size);
	if(sp->item == NULL){
		printf("Error assigning memory.\n");
		printf("Enter any key to exit.\n");
		getch();
		exit(0);
	}
}

void push(Stack *sp, char value){
	if(isOverflow(sp)){
		char *temp = (char *)malloc(sizeof(char) * sp->size * 2);
		if(temp == NULL){
			printf("Stack Overflow.\n");
			return;
		}
		int i;
		for(i = 0; i <= sp->top; ++i){
			temp[i] = sp->item[i];
		}
		free(sp->item);
		sp->item = temp;
		sp->size *= 2;
	}
	sp->item[++sp->top] = value;
}

char pop(Stack *sp){
	if(isUnderflow(sp)){
		printf("Stack Underflow.\n");
		exit(0);
	}
	return sp->item[sp->top--];
}

void deallocate(Stack *sp){
	free(sp->item);
	/**/
}

int isOverflow(Stack *sp){
	if(sp->top == sp->size-1)
		return 1;
	else 
		return 0;
}

int isUnderflow(Stack *sp){
	if(sp->top == -1)
		return 1;
	else 
		return 0;
}

int reverseTextFile(char * source, char * destination){
	Stack stack1;
	const int SIZE = 50;
	initStack(&stack1, SIZE);

	FILE *fps = fopen(source, "r");
	if(fps == NULL){
		printf("Error opening file.");
		return 0;
	}

	FILE *fpd = fopen(destination, "w");
	if(fpd == NULL){
		printf("Error opening file.\n");
		return 0;
	}

	while(!feof(fps)){
		push(&stack1, fgetc(fps));	
	}

	while(!isUnderflow(&stack1)){
		fputc(pop(&stack1), fpd);
	}

	free(fps);
	free(fpd);
	deallocate(&stack1);

	return 1;
}