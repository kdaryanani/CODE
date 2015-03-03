#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define L 100

int
main(int argc, char *argv[])
{
	
	int fR;
	int command;
	int i;
	
	char fpreadtext[L];
	char fpwritetext[L];
	char key=atoi(argv[1]);


	if (argc!=4)
	{
		printf("Error\n");
		return 0;
	}
	
	FILE *fpread=fopen(argv[2], "rb"), *fpwrite=fopen(argv[3], "wb");

	if(fpread==NULL||fpread==NULL)
	{
		printf("Error with one or more files. \n");
		return 0;
	}
	
	while (1)
	{
		printf("Please choose from the following options.\n  1 to ENCRYPT\n  2 to DECRYPT\n  3 to QUIT\n");
		scanf("%d", &command);
		
		switch(command)
		{
			case 1:
				while((fR=fread(fpreadtext, sizeof(char), 100, fpread))!=0)
				{
					for(i=0;i<fR;i++)
						fpwritetext[i]=fpreadtext[i]^key;
					fwrite(fpwritetext, sizeof(char), fR, fpwrite);
				}
				break;
		
			case 2:
				while((fR=fread(fpreadtext, sizeof(char), 100, fpread))!=0)
				{
					for(i=0;i<fR;i++)
						fpwritetext[i]=fpreadtext[i]^key;
					fwrite(fpwritetext, sizeof(char), fR, fpwrite);
				}
				break;
			case 3:
			
				printf("Quitting\n");
				fclose(fpread);
				fclose(fpwrite);
				return 0;

			default:
				printf("This is not an option");
				fclose(fpread);
				fclose(fpwrite);
				return 0;
		}
	}
}







