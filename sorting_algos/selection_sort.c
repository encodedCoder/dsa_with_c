#include<stdio.h>

void selection_sort(int *a,int size_of_array);
void printArray();

int a[8] = {11,5,401,13,81,21,47,61};

int main(int argc, char const *argv[])
{
    printArray();
    selection_sort(a, 8);
    printArray();
    return 0;
}

void selection_sort(int *a,int size_of_array)
{
    int minLocation, i, j, temp;
    i = 0;
    while(i < size_of_array)
    {
        minLocation = i;
        j = i + 1 ;
        while (j < size_of_array)
        {
            if(a[minLocation] <= a[j]){
                j++;
            }else if (a[minLocation] > a[j])
            {
                minLocation = j;
                j++;
            }
        }
        temp = a[i];
        a[i] = a[minLocation]; 
        a[minLocation] = temp;
        i++;
    }
}

void printArray()
{
    int i;
    printf("\n");
    for (i = 0; i <= 7; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}