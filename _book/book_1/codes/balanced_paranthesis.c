#include <string.h>
#include <stdio.h>


int count(char *string, char *substring){
	// returns the count of substring'
	int string_len = strlen(string);
	int counter = 0;
	// simple counter O(n)
	for (int i = 0; i < string_len; i++){
		if (string[i] == *substring){
			counter++;
		}
	}
	return counter;
}



int main(int argc, char *argv[]){

	printf("input argument -> %s\n",argv[1]);
	
	if (argc == 2){
		char *string = argv[1];
		char *lcharacter = "(";
		char *rcharacter = ")";

		// count of the left ( character
		int leftcount = count(string, lcharacter);
		int rightcount = count(string, rcharacter);

		printf("count ( -> %d\n",leftcount);
		printf("count ) -> %d\n",rightcount);
		
		if (leftcount == rightcount){
			printf("Brackets are balanced\n");
		}else{
			
			printf("Brackets are not balanced\n");

		}

	}else {
		printf("Too many arguments\n");
		return 1;
	}

	
	return 0;
}
