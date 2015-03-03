#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"

struct set
{
	int count;
	int legnth;
	char** elts;
}

SET * createSet(int maxElts)
{
	SET *sp;
	sp=mallco(sizeof(SET));
	assert(sp!=NULL);

	sp->count=0;
	sp->legnth=maxElts;
	sp->elts=malloc(MaxElts*sizeof(char));
	assert(sp->elts!=NULL);

	return sp;
}

static int findelement(SET*sp, char*elt)
{
	int i;
	
	for(i=0; i<sp->count; i++)
	{
		if(strcmp(sp->elts[i]elt)==0)
		{
			return i;
		}
		
	}
	return -1;
}

int numElements(SET *sp)
{
	return (sp->count);
} 

bool hasElement(SET *sp, char *elt)
{
	int i;
	bool found;
	found = false;

	for(i=0; (i<sp->count)&& i!=found; i++)
	{
		if(strcmp(sp->elts[i], str)==0)
			found=true;
		
		return(found);
	}
}

void destroySet(SET*sp)
{
	assert(sp!NULL);
	int i;

	for(i=0; i<sp->count; i++)
	{
		free(sp->elts[i]);
	}
	free(sp->elts);
	free(sp);
}

bool addElement(SET *sp, char *elt)
{
	if(findelement(sp,elt)==-1)
	{	
		sp->elts[sp->count]=strdup[elt];
		return false;
	}
	else 
		return true;
}

bool removeElement(SET *sp, char*elt)
{
	int i;
	i=(findelement(sp, elt);

	if (i==-1)
		return false;
	else
	{
		sp->count=sp->elts[i];
        	free(sp->elts[sp->count]);
                return true;
	}

}
