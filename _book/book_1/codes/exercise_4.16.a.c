/*
 * find the second largest element
 */
#include <stdio.h>

void replace_smallest(int *a, int element){
	// find the smallest in arr
	if (a[0] > a[1]){
		a[1] = element;
	}else{
		a[0] = element;
	}

}


int main(){
    // stores the largest items
    int largest_arr[2] = {0 , 0};
    int arr[] = {5,6,9,2,1};
    
    // iterate throught the arr array
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		if ((arr[i] > largest_arr[0]) || (arr[i] > largest_arr[1])){
			// find the smallest value in largest_arr and 
			// replace it with the current element
			replace_smallest(largest_arr, arr[i]);
		}
    }
    

	// printing the largest elements
	printf("%d:%d",largest_arr[0],largest_arr[1]);
	return 0;
}
