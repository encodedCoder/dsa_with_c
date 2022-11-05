#include<stdio.h>

void max_heapify(int *a, int index, int array_size);
void swap(int *a, int *b);
void print_array();
void build_max_heap(int *a, int array_size);

// int array[9] = {80,210,15,610,30,910,10,5,100};
int array[10] = {19,4,10,14,7,9,3,2,8,1};

int main(int argc, char const *argv[])
{
    print_array();
    build_max_heap(array, 10);
    print_array();
    return 0;
}

void print_array()
{
    printf("\n\t");
    int i;
    for (i = 0; i < 10; i++)
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
    if (left_child_index <= array_size-1 && a[parent_index] <= a[left_child_index])
    {
        index_of_largest = left_child_index;
    }
    else
    {
    	index_of_largest = parent_index;
    }
    if (right_child_index <= array_size-1 && a[index_of_largest] <= a[right_child_index])
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