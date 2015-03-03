/*
Karan Daryanani
2:15 Thursday

File: table.c
Description: This file contains the functions for implementing different features on a SET. 

*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"
#include <stdio.h>
#define EMPTY 0
#define FILLED 1
#define DELETED 2

//declares the structure globally
struct set
{
	int count;
	int legnth;
	char **elts;
	char *flags;
};

/*O(m)
This function creates a set and Allocates memory for it. It creates two sets, one for elts and one for flags */
SET* createSet(int maxElts)
{
	int i;
	SET *sp;

	sp=malloc(sizeof(SET)); // allocates memory for the set

	sp->count=0;

	sp->legnth=maxElts;

	sp->elts=malloc(sizeof(char *)*maxElts); // allocates memory for strings and checks location

	assert(sp->elts!=NULL);

	sp->flags=malloc(sizeof(char)*maxElts);

	assert(sp->flags!=NULL);

	for(i=0; i<maxElts; i++)
	{
		sp->flags[i]=EMPTY; // iniatiates every spot in the array to empty in terms of flags.
	}

	return sp;
}

//This returns the number of elements in the array. it can be used to calculate load factors.
//the big O is O(1)
int numElements(SET *sp)
{
	return (sp->count); // returns counter
} 


//This function destroys a set and the Big o is O(m)

void destroySet(SET*sp)
{
	assert(sp!=NULL);
	int i;

	for(i=0; i<sp->legnth; i++)
	{
		if(sp->flags[i]==FILLED)
		{
			free(sp->elts[i]); //frees all spots that are filled.
		}
	}
	free(sp->elts);
	free(sp->flags);
	free(sp);
}	

//O(n), this is the hash function used to find the index of the elt.
unsigned hashString(char *s)
{
	assert(s!=NULL);
	unsigned hash = 0;

	while (*s != '\0')
		hash = 31 * hash + *s ++; //produces hash values

	return hash;
}

//O(m), finds if a set contains an element and keeps track using index and true/false
int findElement(SET *sp, char *elt, bool *found)
{
        assert(sp->elts!=NULL);
        int location=hashString(elt)%(sp->legnth); //initializes location using hash value
        int i=0;
	int hash=0;
	int flag2=0;
	
        while(sp->flags[(location+i)%(sp->legnth)]!=EMPTY) //looking through each spot until it hits an empty one
        {
                if(sp->flags[(location+i%sp->legnth)]==FILLED)// case one spot filled
                {
                        if(strcmp(sp->elts[location+i%sp->legnth], elt)==0)
                        {
                                *found=true;
                                return (location+i % sp->legnth);
                        }
			i++;
                }
                else if(sp->flags[(location+i)%(sp->legnth)]==DELETED && flag2==0) // case 2 spot deleted and was filled
		{
        		hash=(location+i)%(sp->legnth);
			flag2=1;
			i++;
		}
		else
			i++;
        }
	*found=false;
	
	if(flag2==1)
	{
		return hash;
	}
	else
		return (location+i)%(sp->legnth);

}


//This function returns a true or false if it has an element.
//the big o is O(m)

bool hasElement(SET *sp, char *elt)
{
	assert(sp!=NULL||elt!=NULL);
	bool found;

	findElement(sp, elt, &found); //calls the findelement function and returns a true or false

	if (found==true)
		return true;
	else
		return false;
}

	
//this function adds an element to the set
//the big O notation is O(m)
bool addElement(SET *sp, char *elt)
{
	assert(sp!=NULL || elt!=NULL); 
	bool found;
	int location=findElement(sp, elt, &found); //recieves location from findelement function

	if(found==true)
		return (false); //if found, then item already added and remains unchanged
	else if(sp->flags[location]==EMPTY || sp->flags[location]==DELETED)
	{
		if(sp->count<sp->legnth)
		{
			sp->elts[location]=strdup(elt);
			assert(elt!=NULL);
			sp->count++;
			sp->flags[location]=FILLED;
		}
	}
	return true; // array changed

}
//This function is o(n) and it delets an element.

bool removeElement(SET *sp, char *elt)
{
	assert(sp!=NULL || elt!=NULL);
	int r;
	bool found;
	r=findElement(sp, elt, &found); //recieves location from findelement function

	if(found==false)
		return false; //set remains unchanged
	sp->flags[r] = DELETED; //changing the flag to deleted to keep track of the spot(index)
	free(sp->elts[r]);	
	
	sp->count--;
	return true; //set changed
	
}
