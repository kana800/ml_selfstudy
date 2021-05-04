/*
 * Reverse a Given Singly-Linked List
 *
 *
 * contains a part of question 16
 */
#include <stdio.h>
#include <stdlib.h>
#include "singlelinkedlist.h"

struct node *head = NULL;
struct node *tail = NULL;

struct node* create_node(char ch){
	// creating a temp node pointer
	// allocating in heap
	struct node *temp_node = malloc(sizeof(struct node));
	
	temp_node->data = ch;
	temp_node->ptr = NULL;
	return temp_node;
}

void addToTail(char ch){
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
			printf("%c->end\n",temp_node->data);
			break;
		}
		printf("%c->",temp_node->data);
		temp_node = temp_node->ptr;
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
