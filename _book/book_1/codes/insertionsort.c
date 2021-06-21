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

// insertion sort 
void insertionsort(struct word * arr[], int size){
	int i,j, key;
	for (int i = 1 ; i < size; i++){
		key = arr[i]->score;
		j = i - 1;
		
		while (j >= 0 && arr[j]->score > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1]->score = key;
	}
}


int main(int argc, char **argv){

	struct word * arr[3];	
	int size = sizeof(arr)/sizeof(arr[0]);

	arr[0] = createWord("calculator");	
	arr[1] = createWord("random");	
	arr[2] = createWord("man");	

	insertionsort(arr,size);


	for (int i = 0 ; i < size; i++){
		printf("%s \n", arr[i]->data);
	}

	return 0;
}
