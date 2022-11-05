#include <stdio.h>
#include <stdlib.h>

void print_arr(int *, int);
int max_element_in_array(int *, int);
void counting_sort(int *, int);

int main(int argc, char const *argv[]){
    int arr[15] = {6,2,0,7,8,1,3,5,0,1,2,6,5,6,4};
    print_arr(arr, 15);

    counting_sort(arr, 15);
    print_arr(arr, 15);
    return 0;
}

void print_arr(int * arr, int array_size){
    printf("\n");
    for (int i = 0; i < array_size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max_element_in_array(int *arr, int array_size){
    int max = arr[0];
    for (int i = 1; i < array_size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void counting_sort(int *arr, int array_size){
    int max_element_in_arr = max_element_in_array(arr, array_size) + 1;

    int * count_arr = (int *)malloc(sizeof(int) * max_element_in_arr);

    int *auxiliary_arr = (int *)malloc(array_size*sizeof(int));

    //initialize count_arr
    for (int i = 0; i < max_element_in_arr; ++i)
    {
        count_arr[i] = 0;
    }
    //do the counting in count_arr
    for (int i = 0; i < array_size; ++i)
    {
        count_arr[arr[i]]++; 
    }

    //now find the cummulative count in court_array
    for (int i = 1; i < max_element_in_arr; ++i)
    {
        count_arr[i] += count_arr[i-1];
    }

    //final sorting
    for (int i = array_size-1; i >= 0; --i)
    {
        auxiliary_arr[count_arr[arr[i]]-1] = arr[i];
        count_arr[arr[i]]--;
    }

    //copy the auxiliary_arr to original arrray
    for (int i = 0; i < array_size; ++i)
    {
        arr[i] = auxiliary_arr[i];
    }
}