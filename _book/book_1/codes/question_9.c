/*
 * Concatenate Two Trees
 */

#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct node {
	int data;
	struct node *leftptr;
	struct node *rightptr;	
};

struct node* create_node(int num){
	struct node *temp_node = malloc(sizeof(struct node));

	temp_node->data = num;
	temp_node->leftptr = NULL;
	temp_node->rightptr = NULL;
	return temp_node;
}

struct node* addToTree(struct node *root, int num){
	// root node not present
	if (root == NULL){
		// creating a node
		struct node *temp_node = create_node(num);
		return temp_node;
	}else if(num <= root->data){
		// recursion
		root->leftptr = addToTree(root->leftptr, num);
	}else {
		root->rightptr = addToTree(root->rightptr, num);
	}
	return root;
}

// prints the tree
void printTree(struct node*root){
	if (root == NULL){
		return;
	}
	printTree(root->leftptr);
	printf("%d ", root->data);
	printTree(root->rightptr);
}

// Function to find the minimum
struct node* FindMinimum(struct node *root){
	while (root->leftptr != NULL){
		root = root->leftptr;
	}
	return root;
}

void concatenate(struct node* tree1, struct node* tree2){
	// finding the minimum in the left sub tree
	struct node*temp = FindMinimum(tree1->leftptr);
	// No children
	if (temp->leftptr == NULL && temp->rightptr == NULL){
		// temp leftptr is going to be s2
		temp->leftptr = tree2;
	}	
}

int main(int argc, char *argv[]){
	// SET 1
	//			50
	//			/ \
	//		   10 20
	//		        \
	//				70
	//				 \
	//				 80
	struct node* s1 = NULL;
	s1 = addToTree(s1, 50);
	s1 = addToTree(s1, 20);
	s1 = addToTree(s1, 10);
	s1 = addToTree(s1, 9);
	s1 = addToTree(s1, 15);
	s1 = addToTree(s1, 70);
	s1 = addToTree(s1, 80);
	
	// SET 2
	struct node* s2 = NULL;
	s2 = addToTree(s2, 5);
	s2 = addToTree(s2, 2);
	s2 = addToTree(s2, 1);
	s2 = addToTree(s2, 7);
	
	printf("set 1 :");
	printTree(s1);
	printf("\n");
	
	printf("set 2 :");
	printTree(s2);
	printf("\n");
	
	concatenate(s1,s2);

	printf("set 1 :");
	printTree(s1);
	printf("\n");
	return 0;	
}
