//Karan Daryanani, S Figueira, Lab 6, 2:15 Wednesday, Coen 11,


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 20

typedef struct phone
{
	char name[M];
	char number[M];
	struct phone *next;
}PHONE;


//PHONE *head = NULL;
PHONE *tail = NULL;


PHONE *head[26];


int
main (void)	
{
	int i;
	char zed[M];	
	int y;	
	char name3[M];
	char number3[M];
	
	for(i=0; i<26; i++)
	{
		head[i]=NULL;
	}

	for( ; ; )
	{
	
		
	printf("Welcome to your Phone Book.\n Press 1 to add a contact. \n Press 2 to delete a contact. \n Press 3 to list all entries. \n Press 4 to list all entries under a certain letter. \n Press 5 to close your Phone book. \n");

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

		case 4:	letter();
			break;

		case 5: return 0;
		
		default: return 0;
	}
	}
}


int
input (char name1[M], char number2[M])
{

	int i;
	int x;
	PHONE *list, * tlist, *temp;
	tlist = (PHONE *)malloc(sizeof(PHONE));
	strcpy (tlist->name, name1);
	strcpy (tlist->number, number2);


	for(i=0; i<26; i++)
	{
		list=head[i];
	}
	
	x=tlist->name[0]-'a';
	list=head[x];

	if(head[x]==NULL)
	{
		head[x]=tlist;
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
	if (list==head[x])
	{
		tlist->next=head[x];
		head[x]=tlist;
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
	int x;

	xname=(PHONE *)malloc(sizeof(PHONE));

	printf("What name would you like to delete? \n");
	scanf("%s", xname->name);

	x=xname->name[0]-'a';
	xname=head[x];

	if(head==NULL)
	{
		printf("You have no friends. \n");
		return;
	}
	if (strcmp(head[x]->name, xname->name)==0)
	{
		head[x] = head[x]->next;
		return;
	}
	xprev=head[x];
	xnext=head[x]->next;
	
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
	int k;
	for(k=0; k<26; k++)
	{ 
		p=head[k];
		while(p!=NULL)
		{
			printf("%s, %s\n", p->name, p->number);
			p = p->next;
		}
	}
}
	


int
letter()
{
	PHONE *p;
	char y;
	int z;
	printf("What letter would you like to display?\n");
	scanf("%c", &y);
	scanf("%c", &y);
	z=y-'a';
	p=head[z];
	while(p!=NULL)
	{
		printf("%s, %s \n", p->name, p->number);
		p = p->next;
	}
}














