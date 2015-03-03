//Karan Daryanani, tree.c, COEN12
//When executed, this program sorts a series of numbers by increasing order.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

struct tree //Initializing node/root to store data and point left, right, and to the parent
{
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
};

//This function creates a tree. it returns a pointer to a new tree with the specified left and right subtrees and data for its root. O(1).
struct tree *createTree (int data, struct tree *left, struct tree *right)
{
	struct tree *temp;
	temp=malloc(sizeof(struct tree));
	assert(temp!= NULL);
	
	temp->data=data;
	temp->left=left;
	temp->right=right;
	temp->parent=NULL;
	
	if(temp->left!=NULL)
		left->parent=temp;
    
	if (temp->right!= NULL)
		right->parent=temp;
	
	return temp;
}


//This function deletes a tree originating at the root. It deallocates all memory for the tree. O(logn)
void destroyTree (struct tree *root)
{
	if (root==NULL)
		return;
	
	return destroyTree(root -> left);
	return destroyTree(root -> right);
	
	free(root);
}

//This function returns the data within root. O(1).
int getData (struct tree *root)
{
	return root->data;
}
//This function returns the left subtree of the subtree pointed to by root. O(1)
struct tree *getLeft (struct tree *root)
{
	return root->left;
}

//This function returns the right subtree of the subtree pointed to by root. O(1)
struct tree *getRight (struct tree *root)
{
	return root->right;
}

//This function returns the parent tree of the subtree pointed to by root. O(1)
struct tree *getParent(struct tree *root)
{
	return root->parent;
}

//This function updates the left subtree of root. O(1).
void setLeft (struct tree *root, struct tree *left)
{
	assert(root!= NULL);
	root->left=left;
	left->parent=root;
	return;
}

//This function updates the right subtree of root. O(1)
void setRight (struct tree *root, struct tree *right)
{
	assert(root!=NULL);
	root->right=right;
	right->parent=root;
	return;
}
