/*
 * Question 13
 * Let A[1..n] be an array of real numbers. Design an algorithm to perform any sequence of the following
 * operations
 *
 * Add(i,y) : Add the value y to the ith number
 * Partial-sum(i) : Return the sum of the first i numbers (summation)
 */
#include <stdio.h>

// Global Pointer storing address of the first element
int *arr;


void Add(int i, int y){
	arr[i] += y;
}

int PartialSum(int i){
	int sum = 0;
	for (int j = 0; j < i; j++){
		printf("%d,",arr[i]);
		sum += arr[i];
	}	
	return sum;
}

int main(){
	
	// sample array
	int a[] = {1,1,1,1,1,1};
	arr = a;

	// Add operation
	Add(5,1);

	// Partial sum
	printf("Partial sum: %d",PartialSum(2));

}
