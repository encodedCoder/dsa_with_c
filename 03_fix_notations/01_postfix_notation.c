#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	double *item;
	int top;
	int size;
}Stack;

void initStack(Stack *, int);
double evalPostFix(char *);
void push(Stack *, double);
double pop(Stack *);
double operate(double, double, char);

void main(){
	char *expression;
	expression = (char *)malloc(sizeof(char) * 50);
	printf("Enter an expression: ");
	scanf("%s", expression);
	printf("%lf\n", evalPostFix(expression));;
}

void initStack(Stack *sp, int size){
	sp->size = size;
	sp->top = -1;
	sp->item = (double *)malloc(sizeof(double) * sp->size);
}

void push(Stack *sp, double num){
	if(sp->top == sp->size -1){
		printf("Stack Overflow. exiting program.\n");
		exit(0);
	}
	sp->item[++sp->top] = num;
}

double pop(Stack *sp){
	if(sp->top == -1){
		printf("Stack Underflow.\n");
		exit(0);
	}
	return sp->item[sp->top--];
}

double evalPostFix(char *exprPtr){
	Stack stack1;
	initStack(&stack1, 50);
	char next_char= *exprPtr;
	while(next_char != '\0'){
		if(next_char >= '0' && next_char <= '9'){
			int num = next_char - '0';

			// printf("current number is: %d\n", num);
			
			push(&stack1, (double)num);

			// printf("returned from push() call.\n");

		}else if(next_char == '+' || next_char == '-' || next_char == '*' || next_char == '/'){
			double result = operate(pop(&stack1), pop(&stack1), next_char);
			push(&stack1, result);
		}else{
			printf("Invalid character found\n");
		}
		next_char= *(exprPtr++);
	}
	return pop(&stack1);
}

double operate(double op1, double op2, char operand){
	switch(operand){
		case '+' : return op1 + op2; break;
		case '-' : return op1 - op2; break;
		case '/' : return op1 / op2; break;
		case '*' : return op1 * op2; break;
		default  : printf("Invalid character found.\n");
				   exit(0);
	}
}
