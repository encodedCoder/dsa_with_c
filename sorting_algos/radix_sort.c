#include <stdio.h>

void radix_sort(int *, int);
void counting_sort(int *, int);
void print_array(int *);
int max_element_in_array(int *, int);

int main(int argc, char const *argv[])
{
	int arr[] = {452, 325, 632, 957, 541, 125, 319};
	radix_sort(arr, 7);
	print_array(arr);
	return 0;
}

int max_element_in_array(int *arr, int array_size){
    int max = arr[0];
    for (int i = 1; i < array_size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i]
        }
    }
    return max;
}

void radix_sort(int *arr, int num_of_elements){
	//
}

void counting_sort(int *arr, int num_of_elements){
	//
}