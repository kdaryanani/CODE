//Karan Daryanani, Coen12, Lab 4 DEQUE.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "deque.h"
#define NODE struct node
#define DEQUE struct deque


//This function Creates a Deque and returns a pointer to itself. O(1)
DEQUE *createDeque(void){
        DEQUE *dp=malloc(sizeof(DEQUE)); //allocating memory for the deque
        assert(dp!=NULL); //ensuring data was allocated

        dp->count=0;
        dp->head=malloc(sizeof(NODE));
        assert(dp->head!=NULL);
        dp->head->prev=dp->head;
        dp->head->next=dp->head;
        return dp; //returing pointer to the new deque
}
//This function Destroys a deque. O(n) (has to traverse whole deque)
void destroyDeque(DEQUE *dp){
        assert(dp!=NULL);
        NODE *delNo, *tempNo=dp->head->next; //assining pointers to Nodes for removal

        while(tempNo!=dp->head){
                delNo=tempNo;
                tempNo=delNo->next;
                free(delNo); //deleting node 
        }
        free(dp->head);
        free(dp); //deleting deque.
}
//This function returns the number of nodes in the deque. O(1)
int numItems(DEQUE *dp){
        assert(dp!=NULL);
        return dp->count;// returning counter
}
//This function adds a node to the beginning of a deque. O(1)
void addFirst(DEQUE *dp, int x){
        assert(dp!=NULL); // ensurning that the Deque exists in almost every function.
        NODE *NewNo=malloc(sizeof(NODE));//allocating memory for new node.
        assert(NewNo!=NULL);

        NewNo->data=x;// extracting data.
        NewNo->used=1;
        dp->head->next->prev=NewNo;
        NewNo->next=dp->head->next; //shifting pointers and pointing to new node
        NewNo->prev=dp->head;
        dp->head->next=NewNo;
        dp->count++; // incrementing counter
}
//This function adds a node to the end of a deque  O(1)
void addLast(DEQUE *dp, int x){
        assert(dp!=NULL);
        NODE *NewNo=malloc(sizeof(NODE)); //allocating memory for new node
        assert(NewNo!=NULL); //ensuring memory was allocated

        NewNo->data=x;// extracting data
        NewNo->used=1;
        dp->head->prev->next=NewNo;
        NewNo->prev=dp->head->prev; // shifting pointer and adding new node
        NewNo->next=dp->head;
        dp->head->prev=NewNo;
        dp->count++; // incrementing counter
}
//This function removes the first node in the deque and returns the data from the node. O(1)
int removeFirst(DEQUE *dp){
        assert(dp!=NULL||dp->count!=0); //ensuring deque exists and is filled
        NODE *DelNo=dp->head->next;
        int ndata=dp->head->next->data;// extracting data 

        DelNo->next->prev=dp->head; //shifting pointers 
        dp->head->next=DelNo->next;
        free(DelNo); //deleting node
        dp->count--;//decrementing counter
        return ndata; //returning deleted data
}
//This function removes the last node in the deque and returns the data it is deleting. O(1)
int removeLast(DEQUE *dp){
        assert(dp!=NULL||dp->count!=0);//ensuring deque exists and is filled
        NODE *DelNo=dp->head->prev; 
        int ndata=dp->head->prev->data; //extracting data

        DelNo->prev->next=dp->head;
        dp->head->prev=DelNo->prev;//shifting pointers to remove node
        free(DelNo);//deleting node
        dp->count--;//decrementing counter
        return ndata;//returning deleted data.
}
//THis function simply removes the node pointed to. O(1)

void removeNode (DEQUE *dp, NODE *p)
{
        assert(p != NULL);
        NODE *q;
        q=p;
        p->prev->next=p->next;
        p->next->prev=p->prev;
    
        dp->count--;
        free(q);
        return;
}
//This function simply gets the data from the first node.
int getFirst(DEQUE *dp){
        assert(dp!=NULL||dp->count!=0);
        return dp->head->next->data;//returning data
}
//This function simply gets the data from the last node. 
int getLast(DEQUE *dp){
        assert(dp!=NULL||dp->count!=0);
        return dp->head->prev->data;//returning data
}
