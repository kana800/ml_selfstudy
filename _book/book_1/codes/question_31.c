/*
 * Given array A of n sorted number that has been circularly shifted k positions to the right
 * Suppose you dont know what k is. Give and O(log n) algorithm to find the largest number in 
 * A
 */
#include <stdio.h>

int findMaximum(int *arr, int left, int right){
	// normal array
	if (arr[left] < arr[right]){
		return arr[right];	
	}else if(left == right){
	// array only contains one element
		return arr[right];
	}
	int mid = (left + right) / 2;
}

int main(){

	int A[] = {35,42,5,15,27,29};
	int size = sizeof(A)/sizeof(A[0]);
	//int max = A[0];
	// O(n) algorithm
	//for (int i = 1; i < size; i++){
	//	if (A[i] > max) {
	//		max = A[i];
	//	}
	//}

	int max = findMaximum(A, 0,size);
	printf("maximum is the %d\n", max);

	return 0;
}
