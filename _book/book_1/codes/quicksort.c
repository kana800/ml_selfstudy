/*
 * IMPLEMENTATION OF QUICKSORT ALGORITHM
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition(int *arr, int start, int end){
	// selecting the pivot poin
	int pivot = arr[end];
	// parition index
	int partitionIndex = start;
	for (int i = start; i < end; i++){
		if (arr[i] <= pivot){
			swap(&arr[i], &arr[partitionIndex]);
			// increment partition index
			partitionIndex++;
		}
	}
	swap(&arr[partitionIndex],&arr[end]);
	return partitionIndex;
}

int randomizedPartition(int *arr, int start, int end){
	srand((unsigned) time(NULL));
	int random = start + rand() % (start - end);
	return partition(arr, start, end);
}

void quickSort(int *arr, int start, int end){
	// base case
	if (start < end){
		// obtain the partition inde
		//int partitionIndex = randomizedPartition(arr, start, end);
		int partitionIndex = partition(arr, start, end);
		quickSort(arr, start, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, end);
	}
}



int main(int argc, char *argv[]){
	
	int arr[] = {4,6,2,5,-1,-3};

	for (int i = 0; i < 6; i++){
		printf("%d ",arr[i]);
	}

	quickSort(arr, 0, 5);
	printf("\n");
	
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
