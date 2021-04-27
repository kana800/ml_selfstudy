/*
 * Create a Data Structure to support the following operations
 * insert(x, T) - Insert item x into the set T
 * delete(k, T) - Delete the kth smallest element from T
 * member(x, T) - Return true iff x\elementofT
 * Best DataStructure would be a BinaryTree
 */

#include <stdio.h>
#include <stdlib.h>
#include "treeds.h"

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

// Function to delete a node from a tree
struct node* Delete(struct node * root, int data){
	if (root == NULL){
		return root;
	} else if (data < root->data){
		root->leftptr = Delete(root->leftptr, data);
	} else if (data > root->data){
		root->rightptr = Delete(root->rightptr, data);
	} else {
		// No children for the nodes
		if ((root->leftptr == NULL) && (root->rightptr==NULL)){
			free(root);
			root = NULL;
		}
		// One child
		else if(root->leftptr == NULL){
			struct node *temp = root;
			root = root->rightptr;
			free(temp);
		}
		else if(root->rightptr == NULL){
			struct node *temp = root;
			root = root->leftptr;
			free(temp);
		}
		// 2 children
		else {
			struct node *temp = FindMinimum(root->rightptr);
			root->data = temp->data;
			root->rightptr =  Delete(root->rightptr, temp->data);
		}
		
	}
}

// Return True if number is memeber of Datastructure
int search(struct node *root, int data){
	if (root == NULL){
		return 1;
	}else if (root->data == data){
		return 0;
	}else if (data <= root->data){
		return search(root->leftptr, data);
	}else{
		return search(root->rightptr, data);
	}
}
/*
int main(int argc, char *argv[]){
	// EMPTY TREE
	struct node* root = NULL;
	root = addToTree(root, 5);
	root = addToTree(root, 2);
	root = addToTree(root, 1);
	root = addToTree(root, 7);
	
	printTree(root);
	printf("\n");
	
	//printf("%d ",search(root, 1));
	//printf("%d ",search(root, 100));
	Delete(root, 5);
	printTree(root);
	printf("\n");


	return 0;	
}
*/
