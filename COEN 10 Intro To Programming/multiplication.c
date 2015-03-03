/*
Karan Daryanani, S Figueira, Lab 2:15 Thursday, Coen 10,
*/

#include <stdio.h>

int main (void)

{
 

	srand((int)time(NULL));
		int i;
		int counter;
		counter=0;
		for (i=0; i<10; i++)
		{
			
			int num;
			int num2;
			int guess;
			num = rand ( ) % 13;
			num2 = rand ( ) % 13;
	
			printf ("%d x %d \n", num, num2);

			scanf ("%d", &guess);
			
			if (num*num2 == guess)
			{	
				printf ("Correct \n");	
				counter++;
			}

			else 
			printf ("Wrong answer \n");
	
		}
			
	printf("%d Correct Answers \n", counter);

	return 1;

}	
