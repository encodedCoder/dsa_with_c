#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a=10, b=0, c;
    c = a&&b?1:0;
    printf("\t%d\n", c);
    return 0;
}
