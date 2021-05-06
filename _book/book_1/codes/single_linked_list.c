/*
 * Question #2
 * Reverse a Given Singly-Linked List
 *
 *
 * Question #16
 * Implement a 'linked list' dictionary word datastructure
 */
#include <stdio.h>
#include <stdlib.h>
#include "singlelinkedlist.h"
#include <string.h>

struct node *head = NULL;
struct node *tail = NULL;

struct node* create_node(char *ch){
	// creating a temp node pointer
	// allocating in heap
	struct node *temp_node = malloc(sizeof(struct node));
	
	// copy content in the array to the node
	strcpy(temp_node->data, ch);
	temp_node->ptr = NULL;
	return temp_node;
}

void addToTail(char *ch){
	// creating a node
	struct node *temp_node = create_node(ch);
	
	// if empty
	if (tail == NULL){
		// head and tail same
		head = temp_node;
		tail = temp_node;
		return;
	}else{
		// update the previous pointer tail
		tail->ptr = temp_node;
		tail = temp_node;
		return;
	}
}

void printList(){
	// print the list from head->tail
	struct node *temp_node = head;
	while (1){
		if (temp_node->ptr == NULL){
			printf("%s->end\n",temp_node->data);
			break;
		}
		printf("%s->",temp_node->data);
		temp_node = temp_node->ptr;
	}
}

// check if the word is present in
// the array
int isPresent(char *word){
	struct node *temp_node = head;
	while(1){
		if (temp_node->ptr == NULL) {
			return 1;
		}
		if (strcmp(temp_node->data,word) == 0){
			return 0;
		}else {
			temp_node = temp_node->ptr;
		}
	}
}

void reverseList(){
	// reverse from tail to head
	
	struct node *temp_node = head;
	struct node *node_ahead = NULL;
	struct node *node_passed = NULL;
	
	// changing tail
	tail = head;
	while (temp_node != NULL) {
		node_ahead = temp_node->ptr;
		// changing the current node pointer to before
		temp_node->ptr = node_passed;
		// node we passed becomes new node
		node_passed = temp_node;
		temp_node = node_ahead;
	}
	// changing head
	head = node_passed;
}

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
	
	int counter;
	char word[20];

	while (1){
		if ((ch = fgetc(fp)) == EOF){
			break;
		} else if (ch == '\n'){
			// reset the array
			//printf("%s\n",word);
			// create a node
			if (isPresent(word) == 0){
				printf("word is present!\n");	
			}else{
				addToTail(word);
			}
			for (int i=0; i< 20; i++) word[i] = '\0';
			counter = 0;
		}
		word[counter] = ch;
		counter++;
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
