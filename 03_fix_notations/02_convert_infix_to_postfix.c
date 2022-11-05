#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
typedef enum{
	FALSE, TRUE
	/**/
}BOOLEAN;

// *********************** Implementation of Stack for the operators *************//
typedef struct Stack{
	char item[SIZE];
	int top;
}OprStack;

void opr_push(OprStack *sp, char value){
	if (sp->top == SIZE - 1){
		printf("Stack Overflow\n");
		return;
	}

	//top++;
	sp->item[++sp->top] = value;
} 

char opr_pop(OprStack *sp){
	if (sp->top == -1){
		printf("Stack Underflow\n");
		return '\0';
	}
	int value = sp->item[sp->top--];
	return value;
}
// ************************ End of stack implementation for operators **************************/

//                  (           )
/**
	oprtrPrecedence (op, '(' ) = FALSE
	oprtrPrecedence ('(', op ) = FALSE,
	oprtrPrecedence(op, ')') = TRUE,  except op = '('
	oprtrPrecedence('(', ')') = FALSE, we should push, however instead of PUSH we will pop
	oprtrPrecedence('/', '')
*/
BOOLEAN oprtrPrecedence(char left, char right){
	if (left == '(' || right == '(')
		return FALSE;
	if (right == ')')
		return TRUE;

	if (left == '*' || left == '/'){
		if (right == '*' ||  right == '/' || right == '+' || right == '-')
			return TRUE;
		else 
			return FALSE;
	}
	if (left == '+' || left == '-'){
		if (right == '+' || right == '-')
			return TRUE;
		else 
			return FALSE;
	}
	if (left == '$'){
		return TRUE;
	}
	else 
		return FALSE;
}

void convert(char infix[], char postfix[]){
	OprStack stack1;
	stack1.top == -1;
	int i = 0, j = 0;
	while(infix[i] != '\0'){
		char token = infix[i];
		if(token >= '\0' && token <= '\0'){
			postfix[j++] = token;
		}else if(token=='+'||token=='-'||token=='*'||token=='/'||token=='$'||token=='('||token==')'){
			while(stack1.top != -1 && oprtrPrecedence(stack1.top, token)){
				postfix[j++] = opr_pop(&stack1);
			}
			if(token == ')')
				opr_pop(&stack1);
			else
				opr_push(&stack1, token);
		}
		++i;
	}
	while(stack1.top != -1){
		postfix[j++] = opr_pop(&stack1);
	}
}

int main(int argc, char const *argv[]){
	char postfix[SIZE], infix[SIZE];
	printf("Input infix string: ");
	
	scanf("%s", infix);
	convert(infix, postfix);
	printf("Postfix string: %s\n", postfix);
	return 0;
}









