//Karan Daryanani, Thursday 2:15 Lab

//including libraries

#include <stdio.h>
#define MAX_WORD_LENGTH 30

int main(int argc,char *argv[])
{
	int counter=0; //setting count equal to 0
	char fpread[MAX_WORD_LENGTH];

	FILE *fp;

	if(argc!=2) // checking arguments
	{
		printf("Error\n");
		return;
	}

	fp=fopen(argv[1], "r"); //opening file

	if(fp==NULL) // checking if error with file
	{
		printf("Error with file.\n");
		return 0;
	}

	else
	{
		while(fscanf(fp, "%s", fpread)>0)
		{
			counter++; // counting amount of words through a while loop
		}
	
		printf("%d total words\n", counter); // displaying final word count after loop
	}

	fclose(fp); // closing file
	return 0;
}

