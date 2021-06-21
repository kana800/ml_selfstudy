// implementation of selection sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word{
	// assuming the longest
	// word in the list is 
	// no longer than 20 characters
	char data[20];
	int score;
};

// return a score to the word
// according to the acsii characters
int scoreWord(char *ch){
	int score;
	int size = sizeof(ch)/sizeof(ch[0]);
	for (int i = 0 ; i < size; i++){
		score += (int) ch[i]; 
	}
	return score;
}

// returns a word pointer of the structure
// that stored the word inputted to the func
struct word * createWord(char *ch){
	struct word * temp = malloc(sizeof(struct word));
	strcpy(temp->data, ch);	
	temp->score = (int) ch[0];
	//printf("word copied %s\n",temp->data);
	//printf("word score %d\n",temp->score);
	return temp;
}

// swap the two elements in the array
void swapElements(struct word ** one, struct word ** two){
	struct word * temp = *one;
	*one = *two;
	*two = temp;
}

// selection sort 
// parameters:
//			arr -> array need to be sorted
//			start -> start value of the sub-array
//			end -> end value of the sub-array
//			size -> size of the array
void selectionsort(struct word * arr[], int size){
	int minimum;
	for (int i = 0 ; i < size; i++){
		minimum = i;
		for (int j = i + 1; j < size; j++){
			if (arr[j]->score < arr[minimum]->score){
				minimum = j;
			}
		}
		// swap the elements
		swapElements(&arr[minimum], &arr[i]);
	}
}


int main(int argc, char **argv){

	struct word * arr[3];	
	int size = sizeof(arr)/sizeof(arr[0]);

	arr[0] = createWord("calculator");	
	arr[1] = createWord("random");	
	arr[2] = createWord("man");	

	selectionsort(arr,3);


	for (int i = 0 ; i < size; i++){
		printf("%s \n", arr[i]->data);
	}

	return 0;
}
