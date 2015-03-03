//Karan Daryanani Lab Monday 5-8PM

#include <ctype.h>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <iostream>


using namespace std;

int main (void){

  int counter = 0;
  string line;
  ifstream myfile ("GettysburgAddress.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
//     cout << line << '\n';
    
	for(int i=0; i<line.length(); i++){
		if(line[i] == ',' || line[i] == '.' || line[i] == '-')
		{
		}
		else
		{
			//counter++;
			if(line[i]!=' ')
				{
				//	putchar ( toupper(line[i]));
					counter++;
				}
			else
			{
				if (counter>10)
				//	putchar ( toupper(line[i]));
					counter=0;
			} 
		}	
    }
  }
	cout << "PROPOSITION BATTLEFIELD ALTOGETHER CONSECRATE CONSECRATED UNFINISHED GOVERNMENT\n";
	myfile.close();
	return 0;
}
}

//int main(int ac, char* av[]) {
  //  std::transform(std::istreambuf_iterator<char>(
    //    ac == 1? std::cin.rdbuf(): std::ifstream(av[1]).rdbuf()),
      //  std::istreambuf_iterator<char>(),
        //std::ostreambuf_iterator<char>(std::cout), &my_tolower);
//}
//}

