/*
Karan Daryanani, S Figueira, Lab 2:15 Thursday, Lab 9, Coen 10,
*/


#include <stdio.h>
#include <string.h>

int roomsReservedCounter = 0;

#define M 10
#define N 20

char *p;
char names[M][N];
char *p=names[0];

int reserve (void)
{
	int counter=0;
	int i;
	char name[20];
	int size =10;
	int n;	
	
			if (roomsReservedCounter==size)
				printf("Hotel is fully booked\n");
			else
			{

				printf("Please enter your name \n");
				scanf("%s", name);			
				
				for(i=0; i<size; i++)
				{
					if(strcmp(p, name)==0)
					{
						printf("Reservations already taken \n");	
						return;
					}
				}	
				
				printf("How many rooms would you like? \n");			
				scanf("%d", &n);
				
				if((10-roomsReservedCounter)<=n)	
					printf("We can only reserve some rooms");
				
				for(i=0; i<size; i++, p+=20)
				if(strcmp(p,"\0")==0)	
				
				{	
					for(i=0; i<n; i++)
					{
						roomsReservedCounter++;
						strcpy(p, name);
						break;							
					}
				}
				printf("%d Rooms Reserved for: %s \n", n, name);
			}								
			if(strcmp(p, name)==0)
				printf("Reservation already taken \n");
					
}		
			




int
cancel (void)
{
	int i;
	char z[20];
				if (roomsReservedCounter==0)
					printf("Hotel is Empty \n");
				else
				{ 
					printf("Enter Reservation Name: \n");
				
				
					scanf("%s", z);
					int flag=0;
					for (i=0; i<M; i++, p+=20)
					{
						if (strcmp(p, z)==0)
						{	
							strcpy(p,"\0");
							roomsReservedCounter--;
							break;
							flag=1;
						}
						
					}
					printf("Reservation(s) Cancelled \n");

					if (flag==0)
						printf("No Such Reservation");
				}	
}

int 
list (void)
{
	int i;

				for (i=0; i<M; i++, p+=20)
					{
						if (strcmp(p, "\0")!=0)
						{
							printf("%s\n", p);	
						}
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
                case 0: reserve();
                        break;
                case 1: cancel();
                        break;
                case 2: list();
			break;
                default: return 0;
        }
	}

}




