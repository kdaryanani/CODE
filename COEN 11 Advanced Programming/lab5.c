//Karan Daryanani, S Figueira, Lab 5, 2:15 Wednesday, Coen 11,


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 50

typedef struct phone
{
	char name[M];
	char number[M];
	struct phone *next;
}PHONE;

PHONE *head = NULL;
PHONE *tail = NULL;


int
main (void)	
{
	char zed[M];	
	int y;	
	char name3[M];
	char number3[M];
	
	for( ; ; )
	{
	
		
	printf("Welcome to your Phone Book.\n Press 1 to add a contact. \n Press 2 to delete a contact. \n Press 3 to list all entries. \n Press 4 to close your Phone book. \n");

	scanf("%d", &y);

	switch(y)
	{

		case 1:
			{
				printf("Please enter the name \n");
				scanf("%s", name3);

				printf("Please enter the number\n");
				scanf("%s", number3);

				input(name3, number3);
				break;
			}
		
		case 2:
			{

				delete();
				break;
			}

		case 3:	show();
			break;

		case 4: return 0;
		
		default: return 0;
	}
	}
}


int
input (char name1[M], char number2[M])
{

	PHONE *list, * tlist, *temp;
	list = head;
	tlist = (PHONE *)malloc(sizeof(PHONE));
	strcpy (tlist->name, name1);
	strcpy (tlist->number, number2);

	if(head==NULL)
	{
		head=tlist;
		return;
	}
	while (list!=NULL)
	{
		if (strcmp(tlist->name, list->name)==0)
		{
			printf("No Duplicates Allowed\n");
			return;
		}

		else if (strcmp(tlist->name, list->name)<0)
			break;
		temp=list;
		list=list->next;
	}
	if (list==head)
	{
		tlist->next=head;
		head=tlist;
	}
	else if(list==NULL)
	{
		temp->next=tlist;
		tlist->next=NULL;
		tail=tlist;
	}
	else
	{
		temp->next=tlist;
		tlist->next=list;
	}
}
	


int
delete()
{
	PHONE *xprev;
	PHONE *xnext;
	PHONE *xname;
	
	xname=(PHONE *)malloc(sizeof(PHONE));

	printf("What name would you like to delete? \n");
	scanf("%s", xname->name);

	if(head==NULL)
	{
		printf("You have no friends. \n");
		return;
	}
	if (strcmp(head->name, xname->name)==0)
	{
		head = head->next;
		return;
	}
	xprev=head;
	xnext=head->next;
	
	while(xnext!=NULL)
	{
		if(strcmp(xnext->name, xname->name)==0)
		{
			xprev->next=xnext->next;
			return;
		}
		xprev=xnext;
		xnext=xnext->next;
	}

	if(xnext == NULL)
		printf("No Such name found!\n");
}


int
show()
{
	PHONE *p;	

	if(head==NULL)
	{
		printf("You have no friends. \n");
		return;
	}
	p=head;
	
	do
	{
		printf("%s, %s\n", p->name, p->number);
		p = p->next;
	}while(p!=NULL);
}
	



















