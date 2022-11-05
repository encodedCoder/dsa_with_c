#include<stdio.h>

float stack[50];
int top = -1;

float postfix_evaluation(char *);
void push_into_stack(float);
float pop_from_stack();

int main(void){
    char *source = "8221-*/2-";
    printf("%s is evaluated to: %.2f", source, postfix_evaluation(source));

}

void push_into_stack(float number){
    if(top == 49){
        printf("\nStack Overflow.\n");
        return;
    }else
    {
        stack[++top] = number;
    }
}

float pop_from_stack(){
    if(top == -1){
        printf("\nStack Underflow.\n");
    }else
    {
        return stack[top--];
    }
}

float postfix_evaluation(char *str){
    char *p = str;
    while(*p != '\0'){
        if('0' <= *p && *p <= '9'){
            push_into_stack((float)(*p - 48.0));
            ++p;
            continue;
        }
        if(*p == '*' || *p == '/' || *p == '+' || *p == '-'){
            float operand2 = pop_from_stack();
            float operand1 = pop_from_stack();
            switch (*p)
            {
            case '*':
                push_into_stack(operand1 * operand2);
                break;
            case '/':
                push_into_stack(operand1 / operand2);
                break;
            case '+':
                push_into_stack(operand1 + operand2);
                break;
            case '-':
                push_into_stack(operand1 - operand2);
                break;
            default:
                printf("\nSomething wrong\n");
                return -9999;
                break;
            }++p;
        }       
    }
    if(top == 0){
        return pop_from_stack();
    }else
    {
        printf("\nSomething wrong.\n");
        return -9999;
    }
}