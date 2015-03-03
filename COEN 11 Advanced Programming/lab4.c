// Karan Daryanani, S Figueira, Lab 4, 2:15 Wednesday, COEN 11, 
#include <stdio.h>
#include <string.h>
#define M 10

typedef union
{
	char school[M];
	float salary;
	int retirement;
} STATUS;

typedef struct
{
	char name[M];
	int age;
	STATUS u;
} PEOPLE;


int gcounter=0;
PEOPLE array[M];

int
main(void)
{
	int y;
	int age3;
	char name4[20];
	char name3[20];
	
	for( ; ; )
	{
	
	printf("Welcome to your People List.\n Press 1 to input a person. \n Press 2 to delete a person. \n Press 3 to list all entries. \n Press 4 to close. \n");

	scanf("%d", &y);
	
	switch(y)
	{
		
		case 1:
			{
				printf("Please enter the name. \n");
				scanf("%s", name3);
				
				printf("Please enter their age. \n");
				scanf("%d", &age3);
				 
				input(name3, age3);
				break;
			}


		case 2:
			{
				printf("Who would you like to delete? \n");
				scanf("%s", name4);
			
				delete(name4);
				break;
			}

		case 3:
			{
				show();
				break;
			}
			
		case 4:	return 0;
			
	}
	}

}

int
input(char * name3, int age3)
{
	
	int i;
	char school3[20];
	float salary3;
	int year3;


	strcpy(array[gcounter].name, name3);
	array[gcounter].age=age3;

	if(age3<=21)
	{	
		printf("Please enter the name of your School \n");
		scanf("%s", school3);
	
		strcpy(array[gcounter].u.school, school3);
		gcounter++;
	}
	
	else if(21<age3 && age3<65)
	{
		printf("Please enter your salary per month. \n");
		scanf("%f", &salary3);
		
		array[gcounter].u.salary = salary3;
		gcounter++;
		
	}
	
	else if(age3>=65)
	{
		printf("Please enter your year of retirement. \n");
		scanf("%d", &year3);

		array[gcounter].u.retirement=year3;
		gcounter++;
	}
	return;
}


int 
delete(char * name4)
{
	int i;
	
	for(i=0; i<M; i++)
	{
		if (strcmp(array[i].name, name4)==0)
		{
			array[i]=array[gcounter-1];
		}
	}	
	gcounter--;
	return;
}

int
show(void)
{
	int i;

	
	for(i=0; i<gcounter; i++)
	{
		printf("\nName: %s \nAge:  %d \n", array[i].name, array[i].age);
	
		if(array[i].age<=21)
		{
       		        printf("Under 21, School Name: %s\n", array[i].u.school);
       		}

		else if(21<array[i].age && array[i].age<65)
       		{
         	       printf("Between 21 & 65. Salary: %f \n", array[i].u.salary);
        
       		}

		else if(array[i].age>=65)
       		{
                	printf("Over 65. Year of Retirement: %d. \n",array[i].u.retirement );
		}
        	
	        
	}

}


















				

