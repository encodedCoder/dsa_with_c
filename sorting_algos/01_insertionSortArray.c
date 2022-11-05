#include <stdio.h>
#define ARRAYSIZE 10

void insertionSortArray(int array[], int arraySize){
	int i, j, key;
	for(j = 1; j < arraySize; ++j){
		key = array[j];
		i = j-1;
		while(i >= 0 && array[i] > key){
			array[i+1] = array[i];
			i--;
		}
		array[++i] = key; 
	}
}

int main(int argc, char const *argv[])
{
	int a[ARRAYSIZE] = {100, 50, 697, 647 ,10, 54, 68, 63, 97, 55};
	insertionSortArray(a, ARRAYSIZE);

	int i;
	for (i = 0; i < ARRAYSIZE; ++i)
	{
		printf("%d ", a[i]);
	}

	return 0;
}