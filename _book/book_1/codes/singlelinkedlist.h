#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H


// node structure
struct node{
	char data;
	struct node *ptr;
};

// foward declartion of all the functions
struct node* create_node(char ch);
void addToTail(char ch);
void printList();
void reverseList();


#endif
