#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "tree.h"

struct tree
{
	int data;
	struct tree *left, *right, *parent;
};


struct tree *createTree(int data, struct tree *left, struct tree *right)
{
	struct tree *new;
	new=malloc(sizeof(struct tree));
	
	assert(new!=NULL);
	new->data=data;
	new->left=left;
	new->right=right;
	new->parent=NULL;

	if(new->left!=NULL)
		left->parent = new;
	if(new->right!=NULL)
		right->parent = new;
	
	return new;
}

void destroyTree(struct tree *root)
{
	if(root==NULL)
		return;

	return destroyTree(root->left);
	return destroyTree(root->right);
	
	free(root);

}

int getData(struct tree *root)
{
	assert(root->data !=NULL);
	return root->data;
}

struct tree *getLeft(struct tree *root)
{
	return root->left;
}
struct tree *getRight(struct tree *root)
{
	return root->right;
}

struct tree getParent(struct tree *root)
{
	return root->parent;

void setLeft(struct tree *root, struct tree *left)
{
	assert (root!=NULL);
	root->left=left;
	left->parent=root;
	return;
}
void setRight(struct tree *root, struct tree *right)
{
	assert(root!=NULL);
	root->right=right;
	right->parent=root;
	return;
}

