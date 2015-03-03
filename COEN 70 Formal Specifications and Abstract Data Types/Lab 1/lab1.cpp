//Karan Daryanani  Lab 1, Monday 5-8PM


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main (void)
{
	int i=0;
	int j=0;
	int x;

	char board[12][12];

	int cnt = 0;
	while (cnt<7)
	{
		if( (cnt == 0) || (cnt ==2) || (cnt==4) ||(cnt==6) )
			cout << "+---+---+---+\n";
	 	else if (cnt==1)
			cout << "| X |   |   |\n"; 
		else if (cnt==3)
			cout << "|   | X |   |\n";
		else if (cnt==5)
			cout << "|   |   | 0 |\n";
		cnt++;
	}

	return 0;
}

	
