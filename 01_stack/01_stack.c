#include <stdio.h>
#define SIZE 10

typedef struct Stack
{
	int item[SIZE];
	int top;
}Stack;

void push(Stack *, int);
int pop(Stack *);
void initTopOfStack(Stack *);

void main(){
	Stack s1, s2, s3;

	initTopOfStack(&s1);
	initTopOfStack(&s2);
	initTopOfStack(&s3);

	push(&s1, 10);
	push(&s1, 20);
	
	printf("Popped from s1: %d\n", pop(&s1));
	printf("Popped from s1: %d\n", pop(&s1));
	printf("Popped from s1: %d\n", pop(&s1));
	printf("Popped from s1: %d\n", pop(&s1));
}

void push(Stack *sp, int value){
	if(sp->top == SIZE-1){
		printf("Overflow Condition.\n");
		return;
	}
	// sp->top++;
	sp->item[++sp->top] = value;
}

int pop(Stack *sp){
	if(sp->top == -1){
		printf("Underflow Condition.\n");
		return -9999;
	}
	return sp->item[sp->top--];
	// sp->top--;
}

void initTopOfStack(Stack *sp){
	sp->top = -1;
}