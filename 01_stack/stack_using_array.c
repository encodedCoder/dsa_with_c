#include <stdio.h>
#include <string.h>

int anything;

const int stackSize = 3;

int stackTop = -1;

typedef struct stack{
	int data;
}Stack;

{//Function Delarations
	void menu(void);
	int printStack(Stack *stack);
	int push_into_stack(Stack *stack, int data);
	int pop_from_stack(Stack *stack);
	int check_validity_of_parenthesis();
}

int main(void){
	Stack stack1[stackSize];
	int temp, data;
	int num = 3;
	while(num){
		if(num--){
			printf("\n\tPress any key to continue............");
			getchar();
			num++;
		}
		menu();
		scanf("%d", &temp);
		switch(temp){
			case 1: 
				printf("You have chosen push() operation.\n");
				printf("Enter an Integer value to push into stack: ");
				scanf("%d", &data);
				if(push_into_stack(stack1, data) != -9999){
					printf("Successfully pushed value %d into stack.\n", data);
				}
				else{
					printf("Failed to push data. Some Error occured.\n");
				}
				// printf("Press any key to continue.\n"); getchar();
				break;
			case 2:
				printf("You have Chosen pop() operation.\n");
				data = pop_from_stack(stack1);
				if(data == -9999){
					;
				}else{
					printf("%d Item is popped of the stack.", data);
				}
				// printf("Press any key to continue.\n"); getchar();
				break;
			case 3:
				printf("You have chosen to print the items of stack\n");
				print_stack(stack1);
				// printf("Press any key to continue.\n"); getchar();
				break;
			case 4:
				printf("Check Parenthesis validy of a string.\n");
				if(check_validity_of_parenthesis()){
					printf("Input string has valid parenthesis.\n");
				}
				break;
			default:
				printf("Invalid Selection, Please Enter Valid Input.\n");
				temp = 0;
				// printf("Press any key to continue.\n"); getchar();
				break;
		}
	}
	return 0;
}

void menu(void){
	printf("\nSelect the operation you want to perform:\n");
	printf("\t1. Push an Integer.\n");
	printf("\t2. Pop an Integer.\n");
	printf("\t3. Print the Stack Elements.\n");
}

int push_into_stack(Stack *stack, int data){
	if(stackTop == stackSize-1){
		printf("Stack Overflow\n");
		return -9999;
	}
	++stackTop;
	stack[stackTop].data = data;

	// printf("Press any key to continue.....................\n");
	// getchar();
	return;
}

int pop_from_stack(Stack *stack){
	if(stackTop == -1){
		printf("Stack Underflow\n");
		return -9999;
	}

	// printf("Press any key to continue.....................\n");
	// getchar();
	return stack[stackTop--].data;
}

int print_stack(Stack *stack){
	if(stackTop == -1){
		printf("Stack Underflow\n");
		printf("Nothing to print here. :)\n");
		return -9999;
	}else{
		int i;
		printf("Items of stack are: ");
		for(i = 0; i <= stackTop; ++i){
			printf("%d\t", stack[i].data);
		}
		printf("\nTop of stack is at item: %d\n", stack[stackTop].data);
		printf("Total items in stack: %d\n", stackTop+1);
		printf("Total Size of Stack: %d\n", stackSize);
		printf("Remaining places in stack: %d\n", ((stackSize-1)-stackTop));
		printf("Successfully printed items of stack.\n");

		// printf("Press any key to continue.....................\n");
		// getchar();
		return 0;
	}
}

int check_validity_of_parenthesis(){
	
	char str[50];
	char *example_string = ((10+20)*(200-66));
	printf("Enter a string whose validity you want to check ");
	printf("[For example: %s]: ", example_string);
	scanf("%s", str);

	stackSize = 50;
	int stackTop = -1;
	Stack stack1[50];

	char *temp = str;
	while(temp){
		if(*p == '('){
			push_into_stack(stack1, *p);
		}
	}
}
