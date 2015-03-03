// Karan Daryanani Lab 1 Part 2, M 5-8PM


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


int main(void)
{

	string i;
	int j;
	int x=0;

	cout << "Please enter your string and we will calculate your Alphanumeric Characters \n";
	getline (cin, i);

	for(j=0; j<i.length(); j++)
	{
		if (i[j] != ' ')
		{
			x++;
		}
	
	}

	cout << i << " " << "has "  << x << " Alphanumeric Characters. \n";

	return 0;

}


