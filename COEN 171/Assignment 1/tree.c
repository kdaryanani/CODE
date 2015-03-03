//
//  tree.c
//  
//
//  Created by Karan Daryanani on 1/26/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node { //Creating the struct node and creating a typedef for easier access
    int  data;
    struct node *low;
    struct node *high;
}NODE;

NODE* insert(NODE *p, int element)
{
    if (p == NULL) //Needs to be created
    {
        p = (NODE*)malloc(sizeof(NODE)); //Allocate memory
        p->low = NULL; //Initial cases
        p->high = NULL;
        p->data = element; //Set element
    }
    else if (p->data < element) // Keep going
        p->high = insert(p->high, element);
    else if (p -> data > element) // Keep going other direction
        p->low = insert(p->low, element);
    return p;
}

bool contains(NODE *p, int element)
{
    if (p == NULL)
        return 0; //Null node not there
    if (p->data == element)
        return 1; //Found element
    if (p->data < element)
        return contains(p->high, element); //Not high enough, keep checking next element
    return contains(p->low, element);
}

int main ()
{
    NODE *p; //Initialize node pointer *p
    p = NULL;
    int value;
    
    scanf("%d",&value);
    
    while (value!=-1) //Exit case
    {
        p = insert(p, value);
        scanf("%d", &value);
    }
    scanf("%d", &value);
    while (value != -1)
    {
        if (contains(p, value))
            printf("Yout elmement has been found in the tree\n");
        else
            printf("Your element does not exist in the tree\n");
        scanf("%d", &value);
    }
    return 0;
}
