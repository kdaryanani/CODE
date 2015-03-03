/*
Karan Daryanani, S Figueira, Lab 2:15 Thursday, Lab 6, Coen 10,
*/


#include <stdio.h>
#include <string.h>

int
main (void)

#define M 10
#define N 20



{

	char names[M][N];
	int roomsReservedCounter = 0;
	int y;
	int i;
	char z[20];
	int x;
	char name[20];
	int SIZE = 10; 
	


	for (i=0;i<M; i++)
	{
		strcpy(names[i],"\0");
	}

		
printf("0 to reserve a room, 1 to cancel a reservation, 2 to list all reservations");

	for ( ; ; )
	{
		scanf("%d", &y);

			if (y==0)
			{
				if (roomsReservedCounter==SIZE)
					printf("Hotel is fully booked\n");
			 	for (i=0; i<SIZE; i++)
				{	
					if (strcmp(names[i],"\0")==0)
					{
						printf("Please enter your name \n");
						scanf("%s", name);
						roomsReservedCounter++;
						strcpy(names[i], name);	
						printf("Room reserved for:%s \n", name);
						break;
					}
				}
			}
		
			if (y==1)
			{
				if (roomsReservedCounter==0)
					printf("Hotel is Empty");
				else
				{ 
					printf("Enter Reservation Name: \n");
				
				
					scanf("%s", z);
					int flag=0;
					for (i=0; i<M; i++)
					{
						if (strcmp(names[i], z)==0)
						{	
							strcpy(names[i],"\0");
							roomsReservedCounter--;
							printf("Reservation Cancelled\n");
							flag=1;
						}
						
					}
					if (flag==0)
						printf("No Such Reservation");
				}	
			}
	
			if (y==2)
			{
				for (i=0; i<M; i++)
					{
						if (strcmp(names[i], "\0")!=0)
						{
							printf("%s\n", names[i]);	
						}
					}
					
					
			}


	}

	return 1;
}






