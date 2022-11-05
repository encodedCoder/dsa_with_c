#include <stdio.h>

int binarySearch(int a[], int size, int target){
	int left = 0, right = size-1, middle;
	while(left <= right){
		middle = (left + right)/2;
		if(a[middle] == target)
			return middle;
		else if(a[middle] > target)
			right = middle-1;
		else
			left = middle+1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int array[6] = {1, 5, 7, 8, 11, 18}, i;
	
	printf("List is:\n");
	for(i = 0; i < 6; ++i){
		printf("%d ", array[i]);
	}

	int target = 18, element;
	if ((element = binarySearch(array, 6, target)) != -1)
		printf("\nElement %d found at index: %d\n", target, element);
	else
		printf("\nElement %d not found\n", target);
	return 0;
}