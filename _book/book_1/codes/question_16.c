/*
 * Question #16
 * Compare Different Dictionary Data Structures
 */
#include <stdio.h>
#include <stdlib.h>
#include "singlelinkedlist.h"


void readFile(char *filename){
	//file pointer
	FILE *fp;
	char ch;
	
	printf("filename %s\n", filename);
	// opening the file in read mode
	fp = fopen(filename, "r");
	
	if (fp == NULL){
		perror("Error while opening file\n");
		exit(EXIT_FAILURE);
	}

	while((ch = fgetc(fp)) != EOF){
		printf("%c",ch);
		addToTail(ch);
	}
	fclose(fp);
}


int main(int argc, char **argv){

	if (argc == 2){
		// file name is present
		// display content of the file
		readFile(argv[1]);
	}
	printList();
}
