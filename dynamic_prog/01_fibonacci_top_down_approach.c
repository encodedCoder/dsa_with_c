#include<stdio.h>

int fibTable[10];

int fibonacci(int num){
    if (fibTable[num] != 0)
    {
        return fibTable[num];
    }
    fibTable[num] = fibonacci(num-1) + fibonacci(num-2);
    return fibTable[num];
}

int main(int argc, char const *argv[])
{
    fibTable[0] = 1;
    fibTable[1] = 1;
    int i;
    fibonacci(9);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", fibTable[i]);
    }
    
    return 0;
}
