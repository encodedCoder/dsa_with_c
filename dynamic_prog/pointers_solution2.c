//What is the output of following program

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[2][3] = {9, 2, 5, 8, 4, 6};
    int (*p)[3] = a;

    printf("%d", p[1][1]);

    return 0;
}