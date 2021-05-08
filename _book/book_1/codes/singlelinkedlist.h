#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

// node structure for question #10, question#22
struct node{
	char data;
	struct node *ptr;
};

/*
// node structure for question #16
struct node{
	// assuming words in the list are no more than
	// 20 characters
	char data[20];
	struct node *ptr;
};
*/

// foward declartion of all the functions
struct nodeList* create_node(int ch);
void addToTail(int ch);
void printList();
void reverseList();


#endif
