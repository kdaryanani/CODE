//Karan Daryanani, COEN12, Lab 6 Deque.cpp
# include <stdio.h>
# include <stdlib.h>
# include <cassert>
# include "deque.h"

//Defining the structure to hold the data
struct node {
    int data;
    struct node *next;
    struct node *prev;
};


//This function cunstructs the new deque O(1) 
Deque::Deque()
{
    head = new node; //allocates memort for the deque

    count = 0;//assigning initial count to 0 because of 0 elts
    head = new struct node;//allocating and creating new struct node
    assert(head != NULL);

    head->next = head;//pointing pointers to itself because of only elt
    head->prev =head;

}

//This function acts as a destructor for the deque. O(n)
Deque::~Deque()
{
    struct node *np, *next; //assingning temp pointers to the node
    np = head;

    do {
	next = np->next;
	free(np);//deleting elts and freeing pointer
	np = next;
    } while (np != head);

}

//This function adds x as the first item in the deque O(1)
void Deque::addFirst(int x)
{
    struct node *np, *sentinel;


    np = new struct node;//allocating memory to new node
    assert(np != NULL); //asserting not null
    np->data = x; //assinging data to temp node

    count ++; incremeting counter
    sentinel = head;

    np->prev = sentinel; //using sentinel node to add new node
    np->next = sentinel->next;

    sentinel->next->prev = np;
    sentinel->next = np;
}

//This function adds x as the last item in the deque O(1)
void Deque::addLast(int x)
{
    struct node *np, *sentinel;


    np = new struct node; //allocating memory to new node
    assert(np != NULL);
    np->data = x;//assinging data to node

    sentinel = head;
    count ++;//incrementing counter because adding new elt

    np->prev = sentinel->prev;
    np->next = sentinel; //pointing pointers to new node

    sentinel->prev->next = np;
    sentinel->prev = np;
}

//This function removes the first node from the deque and retunrs its data O(1)
int Deque::removeFirst()
{
    int x;
    struct node *np, *sentinel;


    assert(count > 0);//assuring that there are elts
    sentinel = head;
    count --;//decrementing counter because removing elt

    np = sentinel->next;
    sentinel->next = np->next;
    np->next->prev = sentinel;

    x = np->data; //retrieving data
    free(np); //deleting node and freeing pointer
    return x;//returning data
}

//This fucntion removes the last node from the deque and returns its data O(1)
int Deque::removeLast()
{
    int x;
    struct node *np, *sentinel;


    assert(count > 0);//ensuring the deque is not empty
    sentinel =head;
    count --;//decrementing counter because removing elt

    np = sentinel->prev;
    sentinel->prev = np->prev;
    np->prev->next = sentinel;

    x = np->data; //assinging data
    free(np);//deleting node and freeing pointer
    return x;//returning data
}

//This function returns the data from the first node in the deque. O(1)
int Deque::getFirst()
{
    assert(count > 0);
    return head->next->data; //returning data
}

//THis function returns the data from the last  node in the deque O(1)
int Deque::getLast()
{
    assert(count > 0); 
    return head->prev->data; //returning data
}

//This function returns the size of the deque O(1)
int Deque::size()
{
    return count; //returning size
}
