#include<stdio.h>

int arr[8] = {11,15,41,13,81,21,17,61};
// int arr[4] = {4,3,1,2};
int ar[10];

void merge_procedure(int *, int, int, int);
void merge_sort(int *, int, int);
void printArray();

int main(int argc, char const *argv[])
{
    printArray();
    merge_sort(arr, 0, 7);
    printArray();
    return 0;
}

void merge_sort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = (p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge_procedure(A, p, q, r);
    }
}

void merge_procedure(int *A, int p, int q, int r)
{
    int i, j;
    
    //coying into first array
        i = p;
        j = p;
        while (j <= q)
        {
            ar[i++] = A[j++];
        }
        ar[i++] = 9999;
        int t = i;
    //copying into second array
        j = q+1;
        while (j <= r)
        {
            ar[i++] = A[j++];
        }
        ar[i] = 9999;

    //merging the two arrays
        int k = p;
        j = t;
        i = p;
        while (1)
        {
            int flag1 = 0, flag2 = 0;
            if(ar[i] == 9999){
                flag1 = 1;
            }
            if(ar[j] == 9999){
                flag2 = 1;
            }
            if(flag1 && flag2){
                break;
            }
            if(ar[i] < ar[j])
            {
                A[k++] = ar[i++];
            }else if (ar[i] > ar[j])
            {
                A[k++] = ar[j++];
            }   
        }
}

void printArray()
{
    int i;
    printf("\n");
    for (i = 0; i <= 7; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}