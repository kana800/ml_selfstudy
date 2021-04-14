/*
 * Reverse a Given Singly-Linked List
 */
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *ptr;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node* create_node(int num){
	// creating a temp node pointer
	// allocating in heap
	struct node *temp_node = malloc(sizeof(struct node));
	
	temp_node->data = num;
	temp_node->ptr = NULL;
	return temp_node;
}

void addToTail(int num){
	// creating a node
	struct node *temp_node = create_node(num);
	
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
			printf("%d->end\n",temp_node->data);
			break;
		}
		printf("%d->",temp_node->data);
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

int main(){
	
	int list[] = {0,1,2,3,4,5};

	for (int i = 0; i < 6; i++){
		addToTail(i);
	}
	printList();
	reverseList();
	printList();
	reverseList();
	printList();

	return 0;
}
