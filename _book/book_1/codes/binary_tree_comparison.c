/*
 * Question #21
 * Compare two binary search trees and
 * tell them whether they are identical
 * or Not.
 */
#include <stdio.h>
#include "treeds.h"

// returns the height of tree
int maximumDepth(struct node* root){
	if (root == NULL){
		return -1;
	} else{
	int leftHeight = maximumDepth(root->leftptr);
	int rightHeight = maximumDepth(root->rightptr);
	int height = (leftHeight < rightHeight)? rightHeight+1: leftHeight+1;
	return height;
	}
}

// returns the number of leaf nodes in a tree
int numberOfLeafNodes(struct node* root){
	if (root == NULL){
		return 1;
	} else {
		return 1;
	}
}

// returns pointer to an array with tree 'data'
int * dataInTree(struct node *tree){
	if (root == NULL){
		return 0;
	}
	printTree(root->leftptr);
	printTree(root->rightptr);
}

void compareTree(struct node* tree1, struct node* tree2){
	if (maximumDepth(tree1) == maximumDepth(tree2)){
		printf("Trees are identical\n");
		return;
	}else {
		printf("Trees are not identical\n");
	}
}

int main(int argc, char *argv[]){
	// EMPTY TREE
	struct node* tree1 = NULL;
	tree1 = addToTree(tree1, 5);
	tree1 = addToTree(tree1, 2);
	tree1 = addToTree(tree1, 1);
	tree1 = addToTree(tree1, 7);
	

	struct node* tree2 = NULL;
	tree2 = addToTree(tree2, 5);
	tree2 = addToTree(tree2, 2);
	tree2 = addToTree(tree2, 1);
	tree2 = addToTree(tree2, 7);

	compareTree(tree1, tree2);

	return 0;	
}
