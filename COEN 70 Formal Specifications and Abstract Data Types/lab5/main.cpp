#include "orderedlist.h"
int main()
{
    
    cout<< "List Test\n\n";
    List x;
    
    x.insert(5);
    x.insert(4);
    x.insert(3);
    x.insert(2);
    x.insert(7);
    x.insert(1);
    x.insert(10);

    cout << "x: " << x << endl;
    x.replace(3,78);
    cout << "Replace test x: " << x << endl; // Should replace element at 6th position.
    
    /*----------------------------------------------------------------------*/
    cout<< "\n\n OrderedList Test\n\n";
    
    OrderedList myList;
    
	myList.insert(5);
	myList.insert(4);
	myList.insert(3);
	myList.insert(2);
    myList.insert(7);
    myList.insert(1);
    myList.insert(10);
    // 1, 2, 3, 4, 5, 7, 10,
   
	cout << "myList: " << myList << endl;
    myList.replace(6,78);
    cout << "Replace test myList: " << myList << endl; // 1, 2, 3, 4, 5, 7, 78
}
