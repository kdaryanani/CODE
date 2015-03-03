#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"

//declares the structure globally
struct set
{
	int count;
	int legnth;
	char** elts;
};


//this function creates a set and allocates memory for it. BIG O=O(1)

SET* createSet(int maxElts)
{
	SET *sp;
	sp=malloc(sizeof(SET));
	assert(sp!=NULL);

	sp->count=0;
	sp->legnth=maxElts;
	sp->elts=malloc(maxElts*sizeof(char*));
	assert(sp->elts!=NULL);

	return sp;
}

//This returns the number of elements in the array. it can be used to calculate load factors.
//the big O is O(1)
int numElements(SET *sp)
{
	return (sp->count);
} 


//This function destroys a set and the Big o is O(n)

void destroySet(SET*sp)
{
	assert(sp!=NULL);
	int i;

	for(i=0; i<sp->count; i++)
	{
		free(sp->elts[i]);
	}
	free(sp->elts);
	free(sp);
}
//This function returns a true or false if it has an element.
//the big o is O(log n) because it is a binary search.

bool hasElement(SET *sp, char *elt)
{
	int lo, hi, x;
	lo=0;
	hi=sp->count-1;
	
	int mid;

	while(lo<=hi)
	{
		
		mid=(lo+hi)/2;

		if(strcmp(elt, sp->elts[mid])==0)
			return true;
		else if(strcmp(elt, sp->elts[mid])>0)
			lo=mid+1;
		else 
			hi=mid-1;
	} 
	return false;  

}
//this function adds an element to the set
//the big O notation is O(log n)
bool addElement(SET *sp, char *elt)
{

	int i;
	bool found;
	int r=findElement(sp, elt, &found);

	if(hasElement(sp, elt)==true)
		return (false);
	
	for(i=sp->count; i>r; i--)
		sp->elts[i]=sp->elts[i-1];	

	sp->elts[r]=strdup(elt);
	sp->count++;
	return true;
}
//This function is o(log n) and it delets an element.

bool removeElement(SET *sp, char *elt)
{
	int i, r;
	bool found;
	r=findElement(sp, elt, &found);

	if(found==false)
		return false;
	else
	{
		free(sp->elts[r]);	
		for(i=r+1; i<sp->count; i++)
		{
			sp->elts[i-1]=sp->elts[i];
		}
	}
	sp->count--;
	return true; 
	
}
//this function uses a binary search implementation that returns an int.
//big O - O(logn)
int findElement(SET *sp, char *elt, bool *found)
{
	int lo, hi, mid; 
	lo=0;
	hi=sp->count-1;

	while(lo<=hi)
	{
		mid=(lo+hi)/2;

		if(strcmp(elt, sp->elts[mid])<0)
			hi=mid-1;
		else if(strcmp(elt, sp->elts[mid])>0)
			lo=mid+1;
		else
		{
			*found=true;
			return mid;
		}
	}
	*found=false;
	return lo;
}
