#include<stdio.h>

char stack[50];
int top = -1;

void push_into_stack(char);
char pop_from_stack();
char *infix_to_posfix(char *,  char *);

int main(void){
    char *infixString = "(4/(2*(2-1))-2)";
    char postfixString[50];

    printf("%s", infix_to_posfix(infixString, postfixString));
}

void push_into_stack(char pushChar){
    if(top == 49){
        printf("Stack Overflow. Cannot Preceed. Allocate more space for STACK.\n");
        return;
    }
    else{
        stack[++top] = pushChar;
        return;
    }
}

char pop_from_stack(void){
    if(top == -1){
        printf("Stack Underflow. Something's wrong. Debug Your Code.\n");
    }else
    {
        return stack[top--];
    } 
}

char * infix_to_posfix(char *source, char destination[50]){
    char *p = source;
    int i = 0;

    while(*p != '\0'){
        //when character is number
        if(*p >= '0' && *p <= '9'){
            destination[i++] = *p;
            ++p; 
            continue;
        }

        //when character is '(' parenthesis
        if(*p == '('){
            push_into_stack(*p);
            ++p;
            continue;
        }

        //when top is stack is '(' parenthesis
        if(*p == '*' || *p == '/' || *p == '+' || *p == '-'){
            if(stack[top] == '('){
                push_into_stack(*p);
                ++p;
                continue;
            }
        }

        //when *p is either '*' or '/'
        if(*p == '*' || *p == '/'){
            //when top of stack are equal precedence operators
            if(stack[top] == '*' || stack[top] == '/'){
                destination[i++] = pop_from_stack();
                continue;
            }
            //when top of stack have lower precendece than '*' and '/' e.g: +, -, %
            if(stack[top] == '+' || stack[top] == '-'){
                push_into_stack(*p);
                ++p;
                continue;
            }
        }

        //when *p is '+' or '-'
        if(*p == '+' || *p == '-'){
            //when top of stack have higher precedence operators
            if(stack[top] == '*' || stack[top] == '/'){
                destination[i++] = pop_from_stack();
                continue;
            }
            //when top of stack have equal precedence operators
            if(stack[top] == '+' || stack[top] == '-'){
                destination[i++] = pop_from_stack();
            }
        }

        //when we encounter ')' parethesis
        if(*p == ')'){
            while(stack[top] != '('){
                destination[i++] = pop_from_stack();
            }
            ++p;
            pop_from_stack();
        }
    }
    destination[i] = *p;
    return destination;
}