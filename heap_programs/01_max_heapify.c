#include<stdio.h>

void max_heapify(int *a, int index, int array_size);
void swap(int *a, int *b);
void print_array();

int array[9] = {18,2,15,6,3,9,10,5,1};

int main(int argc, char const *argv[])
{
    print_array();
    max_heapify(array, 1, 9);
    print_array();
    return 0;
}

void print_array()
{
    printf("\n\t");
    int i;
    for (i = 0; i < 9; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int *a, int parent_index, int array_size)
{
    int index_of_largest;
    int left_child_index = 2*parent_index + 1;
    int right_child_index = 2*parent_index + 2;
    if (a[parent_index] <= a[left_child_index] && left_child_index <= array_size-1)
    {
        index_of_largest = left_child_index;
    }
    else
    {
    	index_of_largest = parent_index;
    }
    if (a[index_of_largest] <= a[right_child_index] && right_child_index <= array_size-1)
    {
    	index_of_largest = right_child_index;
    }
    if (a[parent_index] != a[index_of_largest])
    {
        swap(&a[parent_index], &a[index_of_largest]);
        max_heapify(a, index_of_largest, array_size);
    } 
    
}