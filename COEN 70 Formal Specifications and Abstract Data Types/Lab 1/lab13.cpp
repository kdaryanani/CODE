// Karan Daryanani Lab 1 part 3, M 5-8PM

#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

int main () 
{
  string line;
  char c;
  locale loc;
  ifstream myfile ("GettysburgAddress.txt");
  if (myfile.is_open())
  {
   // while ( getline (myfile,line) )
    //{
//	cout << line << '\n';
 //   }
//  }
	int cnt =0;
	do{
		c=getc(myfile
	}
	while (getchar (myfile, c))
	{
	if	if cnt==0
		{
			cout << c;
			putchar( toupper(c));
		}
	}
} 
//	int i=0;
//	int j=0;
	
//	for (i=0; i<line.length(); i++)
//	{
//		cout << line[i];
		putchar (toupper(line[i]));
//	}


	myfile.close();
	return 0;

}
