/* 
Karan Daryanani, S FIgueira, Lab 2:15 Wednesday, Lab 1, Coen 11
*/

#include <stdio.h>
#include <stdlib.h>

int counter=0;
int main (void)

{
	srand((int)time(NULL));
		int i;
		int divisor;
		int quotient;
		for(i=0; i<10; i++)
		{
			divisor = rand ( ) % 12 + 1;
			quotient = rand ( ) % 13;
			int dividend;
			division(quotient,divisor);
		}
		printf("%d Correct Answers \n", counter);
}
int division(int quotient, int divisor)

{
	int temp;
	int dividend = (divisor*quotient);
	printf("What is %d divided by %d \n", dividend, divisor);

	scanf("%d", &temp);

	if( quotient == temp)
	{
		counter++;
		printf("Correct \n");
		return 1;
	
	}

	else
	{
		printf("Wrong Answer, correct answer is %d \n", quotient);
		return 0;
	}
	
}



