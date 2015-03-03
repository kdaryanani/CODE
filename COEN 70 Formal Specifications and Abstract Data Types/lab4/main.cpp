/*
Karan Daryanani
*/

#include <iostream>
#include "list.h"
#include <string>
#include <stdlib.h>

using namespace std;


double eval(const char *rhs, List& stack);
bool check(const string rhs);


int main(void){
	string read, temp;	// create string variables
	List stack;		// build the stack
	for(int k=0; k<10; k++){ 	// 10 iterations
	getline(cin,read);		// read an input
	if (!check(read)){		// check input validity (characters)
		cout << "invalid string 2" << endl;
		return 0;
	}	
	double answer;		// a place for the answer
	int i=read.find(" ");	// find the first ' ' character
	int num = 0;
	temp=read.substr(0, read.find(" "));	// get the first number
	if (!isdigit(temp[0])){			// make sure its a number
		cout << "invalid input 1" << endl;
		return 0;
	}
	stack.push(atof(temp.c_str()));		// push the value to the stack
	i++;					// increment i to the next character in the string
	num++;					// keep size counter

	while (i<read.length() && i>0){		// while not the end of the string
		temp=read.substr(i, (read.find(" ", i)-i));	// get the next number/operand
		if(isdigit(temp[0])){ 			// if a number
			stack.push(atof(temp.c_str()));	// push to the stack
			i=read.find(" ", i)+1;		// send i to the character after the next space
			num++;				// increment size
		}
		else if (num >= 2){			// ensure that there are two numbers in the stack
			answer=eval(temp.c_str(), stack);	// evaluate the operation
			i=read.find(" ", i)+1;		// increment i
			num--;				// decrement size
		}
	}
	cout << answer << endl;
	}
	return 0;
	
}


bool check(const string rhs){
	for (int i = 0; i<rhs.length(); i++){
		if (isdigit(rhs[i])||rhs[i] == '.' || rhs[i] == '+' || rhs[i] == ' ' || rhs[i] == '-' || rhs[i] == '/' || rhs[i] == '*'	)		// ensure is digit, decimal or operator
			return true;
	}
	return false;
}

double eval(const char *rhs, List& stack){

	double answer;
	switch(rhs[0]){
		case '+':	// pop the first number, apply the operand, then do the second number
			answer=stack.pop()+stack.pop();
			break;
		case '-':
			answer=0-stack.pop()+stack.pop();
			break;
		case'/':
			answer=1/stack.pop()*stack.pop();
			break;
		case'*':
			answer=stack.pop()*stack.pop();
			break;
	}
		
	stack.push(answer);	// put the answer back on the stack
	return answer;
}
		
