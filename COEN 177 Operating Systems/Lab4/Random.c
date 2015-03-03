#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void printNext100(int, int);

int main(void)
{
    srandom(time(NULL));
    int r = random();
    
    int rangeMin=0;
    int rangeMax=10;
    int max=1000000;
    int modValue =1;
    int counter =0;
    int increment = 100;
    
    while(counter<10000)
    {
        printNext100(rangeMin, rangeMax);
        counter+=1;
        rangeMin+=10;
        rangeMax+=10;
    }
    
    
}

void printNext100(int newMin, int newMax){
    
    int value;
    int i=0;
    for (i=0; i<100; i++)
    {
        int check = newMax-newMin;
        if(check<0) check+=10;
        long r = random();
        value = ((r*143) %(check)) + newMin;
        printf("%d \n", value); 	
    }
    
    
}
