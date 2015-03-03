

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(void)
{
struct object {
     string* s;
};
object A, B;
A.s = new string;
*A.s = "Hello World"; // A has "Hello World"
B = A; // B has "Hello World"
cout << *B.s << endl;
*A.s = "Goodbye"; // A has "Goodbye"
//*B.s = "Hello World"; // B has "hello world"
cout << *A.s << endl;

return 0;
}
