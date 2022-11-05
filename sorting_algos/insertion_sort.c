#include<stdio.h>

int a[10] = {45,26,87,21,30,10,5,97,34,3};

// int a[3] = {3, 1, 2};

void insertionSort(int *array, int size_of_array)
{
    int i, j, key;
    j = 1;
    while(j < size_of_array)
    {
        key = a[j];
        i = j-1;
        while(i >= 0)
        {
            if(key >= a[i])
            {
                a[i+1] = key;
                break;
            }else if (key <= a[i])
            {
                a[i+1] = a[i];
                a[i] = key;
            }
            i--;
        }
        j++;
    }
}

void printArray(int *array, int size_of_array){
    int i;
    printf("\n");
    for ( i = 0; i < size_of_array; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    printArray(a, 10);
    insertionSort(a, 10);
    printArray(a, 10);
    return 0;
}
