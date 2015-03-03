/*
Karan Daryanani, S Figueira, Lab 2:15 Thursday, Lab 6, Coen 10,
*/


#include <stdio.h>

int
main (void)


{

	int roomsArray[10]={0};
	int roomsReservedCounter = 0;
	int reservationId = 200;
	int y;
	int i;
	int z;
	int x;
	int SIZE = 10; 
	

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
					if (roomsArray[i]==0)
					{
						roomsReservedCounter++;
						printf("Room Reserved\n");
						roomsArray[i] = reservationId;	
						printf("%d\n", reservationId);
						reservationId++;
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
					printf("Enter Reservation ID\n");
				
					scanf("%d", &z);
					for (i=0; i<SIZE; i++)
					{
						if (roomsArray[i]==z)
						{	
							roomsArray[i]=0;
							roomsReservedCounter--;
							printf("Reservation Cancelled\n");
						}
					}
				}
			}
	
			if (y==2)
			{
				for (i=0; i<SIZE; i++)
					{
						if (roomsArray[i]>0)
						printf("%d\n", roomsArray[i]);	
					}
					
					
			}


	}

	return 1;
}






