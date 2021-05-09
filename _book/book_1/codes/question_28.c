/*
 * Question 28
 * -----------
 * we have an unordered array X with n integers, find the array 
 * M which contains n integers, where each M[i] would be the product
 * of all integers in X except for X[i]
 *
 * you may not use division 
 */
#include <stdio.h>


int main() { 
	int n = 5;
	// array X with n integers
	int X[] = {1,2,3,4,5};
	// array M with n integers
	int M[] = {1,1,1,1,1};

	int temp = 1;

	// getting the product from left side
	for (int i = 0; i < n; i++){
		M[i] = temp;
		temp = temp * X[i];
	}

	temp = 1;
	
	// getting the product from right side
	for (int i = n - 1; i >= 0; i--){
		M[i] = M[i] * temp;
		temp = temp * X[i];
	}

	// printing the array
	for (int i = 0; i <n ; i++){
		printf("M[%d] = %d\n",i,M[i]);
	}


	return 0;

}
