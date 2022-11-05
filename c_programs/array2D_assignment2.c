#include<stdio.h>

void main()

{

int arr[][] = {{4,5,6},{6,7,8}};

int i, j;

for (i = 0; i < 2; i++)

   for (j = 0; j < 3; j++)

       printf("%d ", arr[i][j]);

}