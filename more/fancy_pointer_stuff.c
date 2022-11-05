#include<stdio.h>

int * fun()
{
    int q = 10;
    int *p;
    p = &q;
    return p;
}    

int main()
{
    int *res;
    res= fun();
    printf("%d", *res);
    return 0;
}