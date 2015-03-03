//Karan Daryanani, S Figueira, Lab 2, 2:15 Wednesday, Coen 11,


#include <stdio.h>
#include <string.h>
#define M 20
#define N 10

char name[N][M];
char number[N][M];

typedef struct phone
{
	char name[M];
	char number[M];
}PHONE;

PHONE phonebook[N];

int gcounter=0;
int flag2=0;

int
main (void)	
{
	char zed[M];	
	int i;
	int k;
	int y;	
	char name3[M];
	char number3[M];

//	for (i=0; i<N; i++)
//	{
//		phone.string[i][0];
//	}
//	
//	for(k=0; k<N; k++)
//	{
//		phone.number[k][0];
//	}
	
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
				printf("Please enter the name you wish to delete\n");
				scanf("%s", zed);

				delete(zed);
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
duplicate (char *name1)
{
	int i;
	PHONE *p_A=phonebook;	

	for(i=0; i<N; i++, p_A++)
	{
		if (strcmp(phonebook->name, name1)==0)
		{
			flag2=1;
			printf("Name Already Taken");
		}
	}

}

int
input (char * name1, char * number2)
{

	duplicate(name1);
	PHONE *p_B=phonebook+gcounter;
	
	if (gcounter !=N && flag2 !=1)
	{
		if(name[gcounter][0]=='\0')
		{
			strcpy(p_B->name, name1);
		}
		
		if(number[gcounter][0]=='\0')
		{
			strcpy(p_B->number, number2);
		}
		gcounter++;
		flag2=0;
	}
	
	return;
}

int
delete(char * zed)
{
	int i;
	int k;
	int flag=0;
	PHONE *p_C=phonebook, *p_D=(phonebook+(gcounter-1));
	
	for (i=0; i<N; i++, p_C++)
	{
		if (strcmp(zed, p_C->name)==0)
		{
			flag=1;
			strcpy(p_C->name,p_D->name);
			strcpy(p_C->number, p_D->number);
			gcounter--;
		}
	}
	
}



int
show(void)
{
	int i;
	PHONE *p_E=phonebook;	

	if(gcounter==0)
		printf("Phonebook Empty.\n");

	for(i=0; i<gcounter; i++, *p_E++)
	{
		printf("Name:  %s  Number:  %s\n", p_E->name, p_E->number);
	}

}































