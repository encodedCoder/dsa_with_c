#include<stdio.h>

int binary_search_recursive(int *a, int lowerBound, int upperBound, int serachItem);

int binary_search_iterative(int *a, int lowerBound, int upperBound, int searchItem);

int main(void)
{
    int a[9] = {0,1,2,3,4,5,6,7,8};
    // printf("\n%d\n", binary_search_recursive(a, 0, 8, 0));
    printf("\n\t%d\n\n", binary_search_iterative(a, 0, 8, 5));
    return 0;
}

int binary_search_recursive(int *a, int lowerBound, int upperBound, int searchItem)
{
    if(lowerBound <= upperBound)
    {
        int middle = (lowerBound + upperBound)/2;
        if (a[middle] == searchItem)
        {
            return 1;
        }else if (a[middle] > searchItem)
        {
            return binary_search_recursive(a, lowerBound, middle-1, searchItem);
        }else if (a[middle] < searchItem)
        {
            return binary_search_recursive(a, middle+1, upperBound, searchItem);
        }  
    }else
    {
        return 0;
    }
}

int binary_search_iterative(int *a, int lowerBound, int upperBound, int searchItem)
{
    int middle, flag = 0;
    while (lowerBound <= upperBound)
    {
        middle = (lowerBound + upperBound)/2;
        if (a[middle] == searchItem)
        {
            flag = 1; break;
        }else if (a[middle] > searchItem)
        {
            upperBound = middle-1;
            continue;
        }else if (a[middle] < searchItem)
        {
            lowerBound = middle+1;
            continue;
        }
    }
    return flag;
}
