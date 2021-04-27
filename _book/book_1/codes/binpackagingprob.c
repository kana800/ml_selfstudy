/*
 * Bin Packaging Problem
 * 
 * question_8.c consist of tree datastructure
 */
#include <stdio.h>
#include "treeds.h"


int main(int argc, char **argv){
	
	// array to hold the weights
	int w[] = {0.5,1,0.3,0.4,0.5,1.0,0.4,0.7,0.5,0.6,0.4,0.1};
	
	// creating an empty tree
	struct node* root = NULL;

	// sum of the weights
	for (int i = 0; i < sizeof(w)/sizeof(w[0]); i++){
	// iterating through the elements
		int weight = w[i];
		struct node* tempnode = root;
		int minimumSpace = 1;
		// pointer to the current partial filled node
		struct node* partialFilledNode = NULL;
		while(tempnode != NULL){
			// check space left
			if (node.data > weight) { 
				int spaceLeft = node.data - weight;
				if (minimumSpace > spaceLeft){
					minimumSpace = spaceLeft;
					partialFilledNode = tempnode;
					tempnode = tempnode.leftptr;
				}
			}else{
				tempnode = tempnode.rightptr;
			}
		} 
		if (partialFilledNode == NULL){
			// create a new bin 
			root = addToTree(root,1 - weight);
		}else{
			// 
			partialFilledNode.data -= weight;
			Delete(partialFilledNode);
			addToTree(partialFilledNode);
		}
	}
	printTree(root);
	printf("\n");
	return 0;	
	
}
