#include <stdio.h>
#include <stdlib.h>

typedef struct stack1{
	char *item;
	int size;
	int top;
}Stack;

typedef enum errors{FALSE, TRUE}Error;

void initStack(Stack *, int);
void deallocate(Stack *);
void checkExpr(char *);
char push(Stack *, char);
char pop(Stack *);
int isOpeningBrace(char);
int isClosingBrace(char);
int isStackEmpty(Stack *);
int isClosingBraceMatch(Stack *, char);
char nextChar(char *);

int main(){
	char *expression = "[((3+6))+{[5+6]}]";	
	checkExpr(expression);
}

void checkExpr(char *exprPtr){
	Stack stack1;
	initStack(&stack1, 50);
	Error error = FALSE;
	char next_char = nextChar(exprPtr++);
	while(next_char != '\0'){
		if(isOpeningBrace(next_char)){
			push(&stack1, next_char);
		}
		else if(isClosingBrace(next_char)){
			if(isStackEmpty(&stack1)){
				error = TRUE;
				break;
			}else if(isClosingBraceMatch(&stack1, next_char)){
				pop(&stack1);
			}else{
				error = TRUE;
				break;
			}
		}
		next_char = nextChar(exprPtr++);
	}

	if(error == TRUE && !isStackEmpty(&stack1))
		error = TRUE;

	if(error == TRUE)
		printf("The input expression does not contain well formed brackets.\n");
	else
		printf("The input expression is well formed.\n");

	deallocate(&stack1);
}

void initStack(Stack *stack1Ptr, int size){
	stack1Ptr->size = size;
	stack1Ptr->top = -1;
	stack1Ptr->item = (char *)malloc(sizeof(char) * stack1Ptr->size);
}

void deallocate(Stack *stack1Ptr){
	free(stack1Ptr->item);
	/**/
}

char nextChar(char *next_char){
	switch(*next_char){
		case '(' : return '('; break;
		case '[' : return '['; break;
		case '{' : return '{'; break;
		case ')' : return ')'; break;
		case ']' : return ']'; break;
		case '}' : return '}'; break;
	}
}

int isOpeningBrace(char next_char){
	if(next_char == '(' || next_char == '[' || next_char == '{')
		return 1;
	else 
		return 0;
}

int isClosingBrace(char next_char){
	if(next_char == ')' || next_char == ']' || next_char == '}')
		return 1;
	else 
		return 0;
}

int isStackEmpty(Stack *stack1Ptr){
	if(stack1Ptr->top == -1)
		return 1;
	else
		return 0;
}

int isClosingBraceMatch(Stack *stack1Ptr, char next_char){
	char stack1Top;
	switch(next_char){
		case ')' : stack1Top = '('; break;
		case ']' : stack1Top = '['; break;
		case '}' : stack1Top = '{'; break;
	}
	if(stack1Ptr->item[stack1Ptr->top] == stack1Top)
		return 1;
	else 
		return 0;
}

char push(Stack *stack1Ptr, char brace){
	if(stack1Ptr->item[stack1Ptr->top] == stack1Ptr->size-1){
		printf("Stack Overflow\n");
		return;
	}
	return stack1Ptr->item[++stack1Ptr->top] = brace;
}

char pop(Stack *stack1Ptr){
	if(stack1Ptr->item[stack1Ptr->top] == -1){
		printf("Stack Underflow.\n");
		exit(0);
	}
	return stack1Ptr->item[stack1Ptr->top--];
}
