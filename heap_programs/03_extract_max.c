#include<stdio.h>

void max_heapify(int *a, int index, int array_size);
void swap(int *a, int *b);
void print_array(int *a, int array_size);
void build_max_heap(int *a, int array_size);
void extract_max();

int array[9] = {80,210,15,610,30,910,10,5,100};

int main(int argc, char const *argv[])
{
    print_array(array, 9);
    build_max_heap(array, 9);
    print_array(array, 9);
    extract_max(array, 9);
    print_array(array, 8);
    return 0;
}

void print_array(int *a, int array_size)
{
    printf("\n\t");
    int i;
    for (i = 0; i < array_size; i++)
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

void build_max_heap(int *a, int array_size)
{
    int i = (array_size/2) - 1;
    while(i >= 0)
    {
        max_heapify(a, i, array_size);
        i--;
    }
}

void extract_max(int *a, int array_size)
{
    swap(&a[0], &a[array_size-1]);
    max_heapify(a, 0, 8);
}