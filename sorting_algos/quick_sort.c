#include<stdio.h>

void quick_sort(int *a,int pivot, int upper_bound_of_array);
int partitioning(int *a,int pivot, int upper_bound_of_array);
void printArray();

int a[8] = {110,125,401,103,81,21,417,61};

int main(int argc, char const *argv[])
{
    printArray();
    quick_sort(a, 0, 7);
    printArray();
    return 0;
}

void quick_sort(int *a,int pivot, int upper_bound_of_array)
{
    if (pivot <= upper_bound_of_array)
    {
        int index = partitioning(a, pivot, upper_bound_of_array);
        quick_sort(a, pivot, index-1);
        quick_sort(a, index+1, upper_bound_of_array - index);
    }
    
}

partitioning(int *a,int pivot, int upper_bound_of_array)
{
    int i = pivot, j = pivot+1, temp;
    while (j <= upper_bound_of_array)
    {
        if (a[pivot] <= a[j])
        {
            j++;
        }else if (a[pivot] > a[j])
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
    temp = a[i];
    a[i] = a[pivot];
    a[pivot] = temp;
    return i;
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