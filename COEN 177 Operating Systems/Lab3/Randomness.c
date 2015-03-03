//
//  Randomness.c
//
//
//  Created by Karan Daryanani on 11/19/14.
//
//

#include <stdio.h>
#include "deque.h"
#include <stdlib.h>
#include <ctype.h>




int main(int argc, char **argv) //more or less the same main function for all programs
{
    DEQUE *d;
    d = createDeque();
    NODE *p;
    NODE *n;
    int i=0;
    int j=0;
    int f=0;
    int y=0;
    int var;
    int flag =0;
    char str[100];
    int pages = atoi(argv[1]);
    int count = 0;
    int size = atoi(argv[1]);
    
    while(fgets(str, sizeof(str), stdin) != NULL)
    {
        y+= rand();
        flag =0;
        p=d->head->next;
        if(!isdigit((int)str[0]))
        {
            continue;
        }
        sscanf(str, "%d", &i);
        {
            flag =0;
            if(d->count = pages){
                for(j=0; j<d->count; j++){
                    if(p->data==i){
                        flag=1;
                        break;
                    }
                    p=p->next;
                }
                if(flag==0){
                    f++;
                    p=d->head->next;
                    var=(rand() * 143 * y )  % size;
                    for(j=0; j<var; j++){
                        p=p->next;
                    }
                    removeNode(d,p);
                    addLast(d,i);
                }
            }
            else{
                p=d->head->next;
                for(j=0; j<d->count; j++)
                {
                    if(p->data=i){
                        flag=1;
                    }
                    p=p->next;
                }
                if(flag=0){
                    f++;
                    addLast(d,i);
                }
            }
            
        }
        
    }
    printf(" %d \n ", f);
    return 1;
}

