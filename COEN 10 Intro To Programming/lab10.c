/*
 Karan Daryanani, S Figueira, Lab 2:15 Thursday, Lab 10, Coen 10,
 */


#include <stdio.h>
#include <string.h>

int roomsReservedCounter = 0;

#define M 10
#define N 20

char *p;
char names[M][N];

int 
reserve (int n, char * name)
{
	int counter=0;
	int i;
	int size =10;
	p=names[0];
	
	if (roomsReservedCounter==size)
		printf("Hotel is fully booked\n");
	else
	{
		
		
		for(i=0; i<size; i++)
		{
			if(strcmp(p, name)==0)
			{
				printf("Reservations already taken \n");
				return;
			}
			p+=20;
		}

		
		if((10-roomsReservedCounter)<=n)
			printf("We can only reserve some rooms");
		p=names[0];
		int filled=0;
		for(i=0; i<size; i++, p+=20){
			if((strcmp(p,"\0")==0) && (filled<n))
			{
					roomsReservedCounter++;
					strcpy(p, name);
					filled++;
			}
		}
		printf("Rooms Reserved for: %s \n", name);
			
	}
	if(strcmp(p, name)==0)
		printf("Reservation already taken \n");
	
}

int
cancel (char * z)
{
	int i;
	p=names[0];
	int flag=0;
	int counter=0;

	if (roomsReservedCounter==0)
		printf("Hotel is Empty \n");
	else
	{
		
		for (i=0; i<M; i++, p+=20)
		{
			if (strcmp(p, z)==0)
			{
				strcpy(p,"\0");
				roomsReservedCounter--;
				flag=1;
				counter++;
			}
			
		}
		printf("Reservation(s) Cancelled \n");
		
		if (flag==0)
			printf("No Such Reservation \n");

		for(i=0; i<M; i++)
		{
			if(strcmp(names[i], "\0")==0)
				break;
		}
		

		int temp = i + counter;

		while(temp < 10)
		{
			strcpy(names[i], names[i+counter]);	
			strcpy(names[i+counter], "\0");
			i++;
			temp++;
		}
	}
}

int
list (void)
{
	int i;
	p=names[0];

	if (roomsReservedCounter==0)
		printf("Hotel is empty \n");
	else
	
	for (i=0; i<M; i++, p+=20)
	{
		printf("%s\n", p);
 	}
	
}


int main (void)
{
	
	char z[20];
	int x;
	int y;
	char name[20];
	int SIZE = 10;
	int i;
 	int n;

	for (i=0;i<M; i++)
	{
		strcpy(names[i],"\0");
	}
	
	
	
	for ( ; ; )
	{
		
        printf("0 to reserve a room, 1 to cancel a reservation, 2 to list all reservations \n");
		
        scanf("%d", &y);
	
        switch(y)
        {
			case 0:
				{
					printf("Please Enter Your Name \n");
					scanf("%s", name);
					
					printf("How Many Rooms Would You Like? \n");
					scanf("%d", &n);	

					reserve(n, name);
					break;
				}
			case 1:
				{

					printf("Enter Reservation Name \n");
					scanf("%s", z);
	
					cancel(z);
					break;

				}
			case 2: list();
				break;
			default: return 0;
        }
	}
	
}



