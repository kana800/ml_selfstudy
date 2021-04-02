/*
 * Implementation of Queues
 * FIFO -> First In First Out method
 *
 * Enqueue(x,q): Insert item x at back of queue q
 * Dequeue(q): Return (and remove) the front item from queue q
 */
#include <stdio.h>
#include <stdlib.h>

struct queue {
	int *data;
	int maxsize;
	int currentindex;
};

int isEmpty(struct stack *s){
	return s->maxsize == -1;
}

int isFull(struct stack *s){
	return s->currentindex == s->maxsize;
}


// initializing the stack
struct stack* initstack(int size){
	// creating a struct pointer and storing the pointer in the heap
	struct stack *p = (struct stack*)malloc(sizeof(struct stack));

	p->maxsize = size;
	// currentindex starts from 0
	p->currentindex = -1;
	// creating a space to store the data in the heap
	p->data = (int*)malloc(sizeof(int) * size);

	return p;
}

void Put(int x,struct stack *s){
	// checking if the stack is full
	if (isFull(s)){
		printf("Stack is Full\n");
	}else {
		printf("Pushing %d\n",x);
		// In s.data will return a pointer
		// s->currentindex return the posistion
		// store x
		s->currentindex++;
		s->data[s->currentindex] = x;
		// incrementing the currentindex
	}
}

void Pop(struct stack *s){
	// checking if the stack is empty
	if (isEmpty(s)){
		printf("stack is Empty");
	} else {
		printf("Removing %d\n",s->data[s->currentindex]);
		s->data[s->currentindex] = '\0';
		s->currentindex--;
	}
}	

int main() {
	// creating a stack called 's'
	struct stack *s = initstack(5);


	Put(3,s);
	Put(2,s);
	Put(1,s);

	Pop(s);


	return 0;
}
