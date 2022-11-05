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
	char *expression = "[((3+6)+{[5+6]}]";
	
	printf("main() function called, now calling checkExpr() PRESSANY.\n\n");/////////
	getch();////////////////////
	
	checkExpr(expression);
}

void checkExpr(char *exprPtr){
	
	printf("checkExpr() called and created a Stack instance,now calling initStack() PRESSANY.\n");////
	getch();////

	Stack stack1;
	initStack(&stack1, 50);

	printf("returned from initStack() call.\n");////
	printf("now calling nextChar() to fetch next_char from expession string. PRESSANY.\n");////
	getch();////

	Error error = FALSE;
	char next_char = nextChar(exprPtr++);

	printf("next_char is: %c\n", next_char);
	// printf("next_char++ is: %c\n", nextChar(exprPtr));
	printf("now entering while loop for checking parenthesis in expression. PRESSANY.\n");
	getch();

	while(next_char != '\0'){
		printf("now we're in while loop. now calling isOpeningBrace(). PRESSANY.\n");
		getch();

		if(isOpeningBrace(next_char)){

			printf("returned from isOpeningBrace() call. now calling push(). PRESSANY.\n");
			getch();

			printf("current pushed parenthesis: %c\n", push(&stack1, next_char));

			printf("returned from push() call. now calling isClosingBrace(). PRESSANY.\n");
			getch();
		}
		else if(isClosingBrace(next_char)){

			printf("returned from isClosingBrace() call. now calling isStackEmpty(). PRESSANY.\n");
			getch();

			if(isStackEmpty(&stack1)){

				printf("returned from isStackEmpty() call. now calling isClosingBraceMatch(). PRESSANY.\n");
				getch();

				error = TRUE;
				break;
			}else if(isClosingBraceMatch(&stack1, next_char)){

				printf("returned from isClosingBrace() call. now calling pop(). PRESSANY.\n");
				getch();

				pop(&stack1);

				printf("returned from pop() call. PRESSANY.\n");
				getch();

			}else{
				error = TRUE;
				break;
			}
		}
		next_char = nextChar(exprPtr++);
	}

	printf("=================================================================\n");
	printf("now we're outside while loop. now comparing various flags. PRESSANY\n");
	printf("=================================================================\n");\
	getch();

	if(!error && isStackEmpty(&stack1))
		error = TRUE;

	if(!error)
		printf("The input expression does not contain well formed brackets.\n");
	else
		printf("The input expression is well formed.\n");

	deallocate(&stack1);
}

void initStack(Stack *stack1Ptr, int size){
	// printf("initStack() is called, re\n");
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
