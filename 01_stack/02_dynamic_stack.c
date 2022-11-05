#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	int * item;
	int top;
	int size;
}Stack;

void initStack(Stack *, int);
void push(Stack *, int);
int pop(Stack *);
int getStackSize(Stack *);
void deallocateMallocMemory(Stack *);
int isOverflow(Stack *);
int isUnderflow(Stack *);
void printBinary(unsigned int);

void main(){
	printBinary(24);
}

void initStack(Stack *sp, int size){
	sp->top = -1;
	sp->item = (int *)malloc(sizeof(int) * size);
	if(sp->item == NULL){
		printf("Error assigning memory.\n");
		printf("Enter any key to exit.\n");
		getch();
		exit(0);
	}
	sp->size = size;
}

void push(Stack *sp, int value){
	if(isOverflow(sp)){
		int *temp = (int *)malloc(sizeof(int) * sp->size * 2);
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

int pop(Stack *sp){
	if(isUnderflow(sp)){
		printf("Stack Underflow.\n");
		return -9999;
	}
	return sp->item[sp->top--];
}

int getStackSize(Stack *sp){
	return sp->size;
}

void deallocateMallocMemory(Stack *sp){
	free(sp->item);
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

void printBinary(unsigned int num){
	Stack s1;
	initStack(&s1, 10);
	int rem;
	const int BASE = 2;
	while(num > 0){
		rem = num % BASE;
		push(&s1, rem);
		num /= BASE;
	}

	while(!isUnderflow(&s1)){
		printf("%d", pop(&s1));
	}
}