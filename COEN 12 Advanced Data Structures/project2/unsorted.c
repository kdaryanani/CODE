#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"

struct set //declaring the set in which we will access the elements. 
{
	int count;
	int legnth;
	char** elts;
};
// Big O notation of this funciton is 0(1)
SET* createSet(int maxElts) //this function creates the set if there isnt already one existing.
{
	SET *sp;
	sp=malloc(sizeof(SET));
	assert(sp!=NULL);

	sp->count=0; //initialzing the counter to 0 because there are no elements yet. 
	sp->legnth=maxElts;
	sp->elts=malloc(maxElts*sizeof(char*));
	assert(sp->elts!=NULL); // checking to make sure data was allocated. 

	return sp;
}

//The findElement function searches for an element and returns an int which is used as the address in other functions. 
//Big O notation of this function is 0(n)
static int findelement(SET*sp, char*elt)
{
	int i;
	
	for(i=0; i<sp->count; i++)
	{
		if(strcmp(sp->elts[i], elt)==0)
		{
			return i;
		}
		
	}
	return -1;
}
//The big O notation of this function is O(1)
//This functions returns the number of elements in the set. 

int numElements(SET *sp)
{
	return (sp->count);
} 
//this function seartches the SET and returns a bool true or false if the element is there.
//THe big O for this functino is o(n).

bool hasElement(SET *sp, char *elt)
{
	int i;
	bool found;
	found = false;

	for(i=0; (i<sp->count) && found!=true; i++)
	{
		if(strcmp(sp->elts[i], elt)==0)
			found=true;
	}	
	return(found);
}
//this function deletes a set using a for loop.
//THe big O notation for this function is o(n)

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



//this function adds an element to the SET and returns a true or false if it was added or not
// the big O for this function is o(n) because it executes once because it calls has element.

bool addElement(SET *sp, char *elt)
{
	int z;
	if(hasElement(sp,elt)==true)
	{	
		return (false);
	}
	else
	{
		z=sp->count;
                sp->elts[z]=strdup(elt);
                sp->count++;
		return true;
	}
}
// the function removes a single element and returns a true or false based on if anything changed.
//the big O is o(n) because it calls find element. 

bool removeElement(SET *sp, char*elt)
{
	int i;
	i=findelement(sp, elt);

	if (i==-1)
		return false;
	else
	{
		free(sp->elts[i]);
		sp->elts[i]=sp->elts[sp->count-1];
		sp->count--;
                return true;
	}

}
