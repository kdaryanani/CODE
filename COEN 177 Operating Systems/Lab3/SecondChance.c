//
//  SecondChance.c
//  
//
//  Created by Karan Daryanani on 11/19/14.
//
//

#include <stdio.h>
#include "deque.h"
#include <stdlib.h>
#include <ctype.h>


typedef struct node NODE;


int main(int argc, char **argv) //more or less the same main function for all programs
{
    DEQUE *d;
    d = createDeque();
    NODE *p;
    int i=0;
    int j=0;
    int var;
    int flag =0;
    char str[100];
    int pages = atoi(argv[1]); 
    int count = 0;
    int size = atoi(argv[1]);
    
    while(fgets(str, sizeof(str), stdin) != NULL)
    {
        if(!isdigit((int)str[0]))
        {
            continue;
        }
        sscanf(str, "%d", &i);
        {
            if(d->count = pages){
                flag =0;
                for(j=0; j<d->count; j++){
                    if(p->data==i){
                        flag=1;
                        p->used=1;
                        break;
                    }
                    p=p->next;
                }
                if(flag==0){
                    while(1){
                        if((p->used)==0){
                            removeFirst(d);
                            addLast(d,i);
                            break;
                        }
                        else{
                            p->used=0;
                            p->prev->next=p->next;
                            p->next->prev=p->prev;
                            d->head->next->prev->next=p;
                            p->prev=d->head->next->prev;
                            p->next=d->head->next;
                            d->head->next->prev=p;
                            p=p->next;
                        }
                    }
                }
            }
            else if(d->count==0){
                addLast(d,i);
            }//keeping track of all cases
            else{
                flag =0;
                for(j=0; j<d->count; j++){
                    if(p->data = i){
                        flag=1;
                        p->used =1;
                    }
                    p=p->next;
                }
                if(flag==0){
                    addLast(d,i);
                }
            }
                
        }
        
        return 1;
    }
}

