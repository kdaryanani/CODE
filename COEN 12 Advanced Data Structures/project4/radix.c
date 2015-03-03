//Karan Daryanani, Lab 4 COEN 12
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include"deque.h"
#define R 10 //initializing r=10 as the assignment said to. 

int main()
{ 

	struct deque *list = createDeque();// This initialized the Deque using the list.
	
	int i;
	int j = 0;
	int sort = 0; 
	int new;
	int loc;
	int div = 1; 
	int max = 0;
	//Initializing my variables.
	assert(list != NULL);

	printf("Enter values that are positive integers and hit enter..\n When you finish entering, submit a negative value. \n");
	
	while(scanf("%d", &new) != EOF) //This loop scans in int's and adds them to the list	
	{
		if(new < 0)
			break;
		if(new > max)	 
			max = new;
		addLast(list, new);	 
	}
	
	struct deque *radix[R];	 
	int Val = numItems(list);
	int iterations = floor(log(max + 1)/(log(R))) + 1;// This initializes the iterations to the algorythm incorperating the floor function.
	
	for(i = 0; i < R; i++)	 
	{
		radix[i] = createDeque();
	}
	
	for(i = 0; i < iterations; i++)	 
	{ 
		j = 0;
		while(j < Val)	 
		{
			sort = (removeFirst(list)); // THis is where the soritng begins
			loc = (sort/div) % 10;	 
			addLast(radix[loc], sort);//Adding to end.
			j++;
		}
		
		for(j = 0; j < R; j++)	 
		{
			while(numItems(radix[j]) > 0)	 
			{
				sort = removeFirst(radix[j]);	
				addLast(list, sort);	 
			}
		}
		
		div = div * 10;
	}
	for (i = 0; i < Val; i++)
	{
		sort = removeFirst(list);	 
		printf("%d ", sort);	 //Printing out Sorted Values.
	}
	
	destroyDeque(list);	 
	
	for(i = 0; i < R; i++)
		destroyDeque(radix[i]);	 
	return 0; //Deleting the deque after values have been printed in sorted order. 
}
