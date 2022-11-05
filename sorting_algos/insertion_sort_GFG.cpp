// https://practice.geeksforgeeks.org/problems/insertion-sort/1
#include <stdio.h>
#include <math.h>

void insertionSort(int arr[], int n);
void printArray(int arr[], int size){
	for (int i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int n = 5, arr[20] = {4,1,3,9,7};
	insertionSort(arr, n);
	printArray(arr, n);
	return 0;
}

void insert(int arr[], int i){
	int key = arr[i];
	int j = i-1;
	while(j >= 0){
		if(key < arr[j]) {arr[j+1] = arr[j]; j--;} 
		else break;
	}
	arr[j+1] = key; 
}
void insertionSort(int arr[], int n){
	for(int i = 1; i < n; i++){
		insert(arr, i);
	}
}