#include <stdio.h>

int main(){
	int s[] = {6,13,19,3,8};
	int max = s[0];
	int min = s[0];

	for (int i = 1; i < sizeof(s)/sizeof(s[0]); i++){
		// comparing max, with the val in the array
		if (s[i] > max){
			max = s[i];
		} else if (s[i] < min){
			min = s[i];
		}
	}

	printf("%d - %d = %d",max,min,max - min);
	return 0;
}
