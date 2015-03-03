//
//  sort.c
//  
//
//  Created by Karan Daryanani on 1/25/15.
//
//

#include <stdio.h>
#include "stdlib.h"

//Globals Declared before funcitions in Pascal

#define HIGH 8
typedef int * numbers; //Initialize an array of numbers
numbers x; //creating an instance of numbers, called a



void readarray(void) {
    
    int i; //initialize int
    
    for (i = 0; i < HIGH; i++) {//Traverse from 0->High-1
        scanf("%d", &x[i]); //Read from keyboard the int and save it in the num array
    }
}

void writearray(void) {
    
    int i; //initilize I
    
    for (i = 0; i < HIGH; i++){ //Traverse from 0->High-1
        
        printf("%d ", x[i]); //print out all of the array
    
    }
    
    printf("\n"); // print a new line from writeln in Pascal
}

void exchange(int * a, int * b) { //Create the Exchange function using passed by reference values
    
    int t;
    
    t = *a;
    
    *a = *b;
    
    *b = t;
}

int partition(numbers x, int y, int z){
    
    int i, j, k; //Initialize variables to use
    
    k = x[y];
    
    i = y;
    
    j = z;
    
    while (i < j){
        while (x[j] > k)
            --j;
        
        while (x[i] < k)
            ++i;
        
        if (i < j)
            exchange(&x[i], &x[j]); //Call exchange function by refernce to swap elements
    }
    
    return j; //Partition j returns the int j
}

void quicksort(numbers x, int m, int n) { //Main method
    
    int i;
    
    if (n > m) {
        i = partition(x, m, n);
        
        quicksort(x, m, i); //Recursion! L
        
        quicksort(x, i+1, n);//Recursion! R
    }
}

int main() {

    x = malloc(sizeof(int) * HIGH); //Allocate memory
    
    readarray(); //call the Read array function which takes no paramaters
    
    quicksort(x, 0, HIGH-1); // Call a recursive version of quicksort
    
    writearray(); //Write to the new array by calling
    
    free(x); //Deallocate memory
    
    return 0;
}