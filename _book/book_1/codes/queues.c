/*
 * Implementation of Queues using Linked List
 * FIFO -> First In First Out method
 *
 * Enqueue(x,q): Insert item x at back of queue q
 * Dequeue(q): Return (and remove) the front item from queue q
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode {
	int data; /*data item*/
	struct queueNode *next; /*pointer to the next queue Node*/
}queueNode;


queueNode *last = NULL; // pointer to the last node
queueNode *first = NULL; // pointer to the first node




void enqueue(int x, queueNode *q){
	// temp pointer
	queueNode *temp;	

	// checking if the last value is null ?
	// empty queue 
	if ((last == NULL) && (first == NULL)) {
		// add the item
		temp = (queueNode*)malloc(sizeof(queueNode));
		temp->data = x;
		temp->next = NULL;

		// updating the last value
		last = temp; 
		// updating the first value
		first = temp;
	}else {
		temp = (queueNode*)malloc(sizeof(queueNode));
		temp->data = x;
		temp->next = NULL;
		
		// updating the ptr of last node
		*last->next = temp;
		// changing the last node
		last = temp;	
	}
}
