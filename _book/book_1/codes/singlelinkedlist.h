#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

/*
// node structure for question #10
struct node{
	char data;
	struct node *ptr;
};
*/

// node structure for question #16
struct node{
	// assuming words in the list are no more than
	// 20 characters
	char data[20];
	struct node *ptr;
};

// foward declartion of all the functions
struct node* create_node(char *ch);
void addToTail(char *ch);
void printList();
void reverseList();


#endif
