//Karan Daryanani, Coen12


/*
 * File:	deque.h
 *
 * Description:	This file contains the public function declarations for a
 *		deque abstract data type for integers.  A deque is a
 *		doubly-ended queue, in which items can only be added to or
 *		removed from the front or rear of the list.
 */

# ifndef DEQUE_H
# define DEQUE_H

//Defining the structure to hold the data
struct node{
    struct node *prev, *next;
    int data, used;// initialzing data, used reperesentds diffferent things in each alogrythm. In used it takes the value of the flag, and the data represents the counter. These change per algorythm */
};
//defining the Deque
struct deque{
    int count;
    struct node *head;
};

typedef struct deque DEQUE;

typedef struct node NODE;

extern DEQUE *createDeque(void);

extern void destroyDeque(DEQUE *dp);

extern int numItems(DEQUE *dp);

extern void addFirst(DEQUE *dp, int x);

extern void addLast(DEQUE *dp, int x);

extern int removeFirst(DEQUE *dp);

extern int removeLast(DEQUE *dp);

extern void removeNode(DEQUE *dp, NODE *p);

extern int getFirst(DEQUE *dp);

extern int getLast(DEQUE *dp);

# endif /* DEQUE_H */
