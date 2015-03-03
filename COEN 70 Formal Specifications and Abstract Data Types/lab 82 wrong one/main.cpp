#include <iostream>
#include "EvalTree.h"
int main(int argc, const char * argv[])
{
    EvalTree tree;
    string somestring="1 2 + 3 *"; // Try other expressions.
    
    tree.build(somestring);
    
    cout << "\n";
    cout<<"postOrder: ";
    tree.print_postorder();//postOrder:  1 2 + 3 *
    cout << "\n";
    cout<<"preOrder: ";
    tree.print_preorder();// preOrder:  * + 1 2 3
    cout << "\n";
    cout<<"inOrder: ";
    tree.print_inorder();// inOrder:  1 + 2 * 3
    
    cout << tree.evaluate() << endl; //recursive evaluation result is : 9
    return 0;
}
