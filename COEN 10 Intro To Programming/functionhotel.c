/*
Karan Daryanani, S Figueira, Lab 2:15 Thursday, Lab 8, Coen 10,
*/


#include <stdio.h>
#include <string.h>

int roomsReservedCounter = 0;

#define M 10
#define N 20

char names[M][N];

int reserve (void)
{
	
	int i;
	char name[20];
	int size =10;
	
			if (roomsReservedCounter==size)
				printf("Hotel is fully booked\n");
			else
			{

				printf("Please enter your name \n");
				scanf("%s", name);

				
				for(i=0; i<size; i++)
				{
					if(strcmp(names[i], name)==0)
					{
						printf("Reservation already taken \n");	
						return;
					}
				}	
	
	
				for(i=0; i<size; i++)
				{
					//reserve the room
	
					if (strcmp(names[i],"\0")==0)
					{
						roomsReservedCounter++;
						strcpy(names[i], name);
						printf("Room Reserved for: %s \n", name);
						break;
					}
	
					else if(strcmp(names[i], name)==0)
						printf("Reservation already taken \n");
				}
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

int 
list (void)
{
	int i;

				for (i=0; i<M; i++)
					{
						if (strcmp(names[i], "\0")!=0)
						{
							printf("%s\n", names[i]);	
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




