#include<stdio.h>

int main(int argc, char const *argv[])
{
    int fibTable[10];
    fibTable[0] = fibTable[1] = 1;

    int i;
    for (i = 2; i < 8; i++)
    {
        fibTable[i] = fibTable[i-1] + fibTable[i-2];
    }

    for (i = 0; i < 9; i++)
    {
        printf("%d ", fibTable[i]);
    }
    
    
    
    return 0;
}
