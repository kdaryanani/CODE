//Karan Daryanani, huffman.c, COEN12
//When executed, this program compresses the data behind characters based on their occurence values.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
#include "pack.h"
#define MAX 257

//Defining different parts of the tree
#define parent(x) (((x)-1)/2) 
#define left(x) ((x)*2+1)
#define right(x) ((x)*2+2) 

int count = 0;
static struct tree *heap[MAX];
struct tree *leaves[MAX];

//This function inserts the tree into the heap. O(logn).
void insert (struct tree *node){
    
	int i;
	int data;
	
	data=getData(node);//Calling getData from tree.c
	i = count++;
	
	while (i>0 && getData(heap[parent(i)]) > data) // Checking values of parent and data and ensuring parent is larger than data
	{
		heap[i]=heap[parent(i)];
		i=parent(i);
	}
	heap[i] = node;
	
}

//This function swaps the root of the heap with the very last element. It compares the current root with the children, and if it senses an error, it swaps root and child and checks again. O(logn).
struct tree * delete ()
{
	int i = 0;
	int child;
	struct tree *min, *p;
	min=heap[0];
	p=heap[--(count)];
	while (left(i) < count)
	{
		child=left(i);
		if (right(i) < count && getData(heap[left(i)]) > getData(heap[right(i)]))
			child = right(i);
		if (getData(p) > getData(heap[child]))
		{
			heap[i] = heap[child];
			i = child;
		}
		else {
			break;
		}
	}
	heap[i] = p;
	return min; 
};

//This function prints out the binary path using recursion. O(log n)
void printBranch(struct tree *leaf)
{
    if (getParent(leaf) != NULL)
    {
        printBranch(getParent(leaf));
        printf("%d", leaf == getLeft(getParent(leaf)));
    }
}

int main (int argc, char *argv[])
{
	FILE *fp;
    int i;
    int c;
    int counterArray[MAX+1];
    char *infile;
    struct tree *left, *right;
    
    infile = argv[1];
    
    if (argc != 3) //ensures correct amount of arguemnts being accepted.
    {
        fprintf(stderr, "Error with one or more files\n"); 
        exit(EXIT_FAILURE); //returns a generic failure of completion
    }
    
    fp = fopen(infile, "rb"); //Opens text file
    
    if (fp == NULL)
    {
        fprintf(stderr, "File is empty or Null, Fix then try again.\n");
        exit(EXIT_FAILURE); //returns a generic failure of completion
    }
    //creating array
    for (i=0; i<MAX; i++)
    {
        counterArray[i]=0;
    }
    //counts amount of characters that are not zero
    while ((c = fgetc(fp)) != EOF)
    {
        counterArray[c]++;
    }
    //intializes leafs
	for (i=1; i < (MAX); i++)
	{
		if (counterArray[i] > 0 || i == 256)
		{
			insert(leaves[i] = createTree(counterArray[i], NULL, NULL));
		}
		else
			leaves[i] = NULL;
	}
	
	
	while (count > 1) //creates heap by passing to delete and insert
	{
		left = delete();
		right = delete();
        //initializing heap by calling on delete from tree.c as well as getdata, and uses insert to create it. 
		insert(createTree((getData(left) + getData(right)), left, right));
	}
    //this prints the binary path and number of times a character is present.
	for (i = 0; i < MAX; i++)
	{
		if ((counterArray[i] != 0 || i == 256) && isprint(i) != 0)
		{
			printf ("%c : %d ", (char)i, counterArray[i]);
			printBranch(leaves[i]);
			printf(" \n");
		}
		if ((counterArray[i] != 0 || i == 256) && isprint(i) == 0)
		{
			printf ("%o : %d ", i, counterArray[i]);
			printBranch(leaves[i]);
			printf(" \n");
		}
	}
	
	//this uses the pack function from professor looney to compress into the second file. 
	pack(argv[1],argv[2],leaves);
	destroyTree(heap[0]);
    //this calls the destroy tree function from tree.c
	
	
	fclose(fp); //closes the file
	return 0;
}
