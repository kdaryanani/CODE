
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

void main(void)
{
	pid_t ID1; //This initalizies each PID and labels them with the convetion ID then number
	pid_t ID2;
	pid_t ID3;
	pid_t ID4;
	pid_t ID5;
	pid_t ID6;
	pid_t ID7;

	ID1 = fork(); //This fork creates the two process, resulting in the parent and child whos value is set to 0 while the new process is given an id (pid)
	if (ID1==0)
	{
		printf("ID1: %d \n" , ID1); //This prints the ID of the first process, but it may be confused by the buffer. 
		ID2 = fork(); //The process is repeated until we create all 7 processes. 
		if(ID2==0){
			printf("ID2: %d \n" , getpid());
			ID3 = fork(); 
			if(ID3==0){
				printf("ID3: %d \n" , getpid()); //Fork and repeat. 
				ID4=fork();
				if(ID4==0){
					printf("ID4: %d \n" , getpid());
					ID5=fork();
					if(ID5==0){
						printf("ID5: %d \n" , getpid());
						ID6=fork();
						if(ID6==0){
							printf("ID6: %d \n" , getpid());
							ID7=fork();
							if(ID7==0){
								printf("ID7: %d \n" , getpid());
							}
						}
					}
				}
			}
		}
	}
				
}											
												

