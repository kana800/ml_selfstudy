/*
 * Question 14
 * -----------
 * Extend the data structure of the previous problem to support insertions and deletions,
 * Each element now has both a key and a value. An element is accessed by its key.
 * The addition operation is applied to the values, but the elements are accessed by its key.
 * The `Partial_sum` operation is different.
 * -------------
 *
 *
 * Add(k,y): Add the value y to the item with key k
 * Insert(k,y): Insert a new item with key k and value y
 * Delete(k) - Delete the item with key k
 * PartialSum(k) = Return Sum of elements until the k value.
 *
 * We will be using a binary tree datastruture to hold the key and the value also the left and right ptr
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key; // This also can be a random # for simplicity sake lets keep it as an integer
	int data;
	struct node *leftptr;
	struct node *rightptr;	
};

// HelperFunction for Add
struct node* create_node(int k,int num){
	struct node *temp_node = malloc(sizeof(struct node));

	temp_node->key = k;
	temp_node->data = num;
	temp_node->leftptr = NULL;
	temp_node->rightptr = NULL;
	return temp_node;
}

struct node* insert(struct node* root, int k,int num){
	// root node not present
	if (root == NULL){
		// creating a node
		struct node *temp_node = create_node(k,num);
		return temp_node;
	}else if(k <= root->key){
		// recursion
		root->leftptr = insert(root->leftptr, k, num);
	}else {
		root->rightptr = insert(root->rightptr, k, num);
	}
	return root;
}

struct node* add(struct node* root, int k, int num){
	if (root == NULL){
		return NULL;
	}else if(k == root->key){
		// found the key!
		root->data += num;
	}else if(k <= root->key){
		root->leftptr = add(root->leftptr, k, num);
	}else{
		root->rightptr = add(root->rightptr, k, num);
	}
}

// print the tree
void print(struct node*root){
	if (root == NULL){
		return;
	}
	print(root->leftptr);
	printf("[%d:%d] ", root->key,root->data);
	print(root->rightptr);
}

// Function to find the minimum
struct node* FindMinimum(struct node *root){
	while (root->leftptr != NULL){
		root = root->leftptr;
	}
	return root;
}

// Function to delete a node from a tree
struct node* Delete(struct node * root, int key){
	if (root == NULL){
		return root;
	} else if (key < root->key){
		root->leftptr = Delete(root->leftptr, key);
	} else if (key > root->key){
		root->rightptr = Delete(root->rightptr, key);
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
			root->key = temp->key;
			root->rightptr =  Delete(root->rightptr, temp->key);
		}
	}
}

// Return the sum of all the elements currently in the set whose 
// key is less than y.
int partialSum(struct node* root, int key, int sum){
	if (root == NULL){
		return sum;
	}else if (key <= root->key){
		sum += root->key;
		return partialSum(root->leftptr, key, sum);
	}else{
		return partialSum(root->rightptr, key, sum);
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

int main(int argc, char *argv[]){
	// tree
	struct node * root = NULL;
	
	// insert function
	root = insert(root,10, 1);
	root = insert(root,11, 2);
	root = insert(root,12, 3);
	root = insert(root,13, 4);
	
	print(root);
	printf("\n");
	// add function
	// adding 1 to the 10 key
	struct node *test;
	test = add(root ,10, 1);
	
	print(root);
	printf("\n");
	
	int sum = 0;
	printf("Partial Sum is %d\n", partialSum(root,11,sum));

	return 0;	
}
