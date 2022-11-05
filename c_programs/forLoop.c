#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i, j, n = 100, count = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j *= 2)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
