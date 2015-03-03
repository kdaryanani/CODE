/*
    Karan Daryanani
    Lab 8
*/

#include <iostream>
#include <cctype>

using namespace std;

//class interface to hold an integer or an operator
class EvalTree{
public:
    void build(string &expression);
    int evaluate();
    void print_preorder();
    void print_inorder();
    void print_postorder();
    EvalTree();
    ~EvalTree();
    int operand;
    char operate;
    
private:
    EvalTree *left;
    EvalTree *right;
};

//constructor function
EvalTree::EvalTree(){
    operand = 0;
    operate = 0;
    left = right = NULL;
} 

//destructor function
EvalTree::~EvalTree(){
    delete left;
    delete right;
}

//the function to build the tree
void EvalTree::build(string &expression){ //maybe return type EvalTree&
    //if the character that is being looked at is a space
    if (isspace(expression[expression.length()-1])){
        expression.erase(expression.length()-1, 1);
    }

    //if the character is a digit
    if(isdigit(expression[expression.length()-1])){
        operand = expression[expression.length()-1] - '0';
        expression.erase(expression.length()-1, 1);
        return;
    }

    //if the character is an operator
    else
        operate = expression[expression.length()-1];

    //creating the children of the operator
    left = new EvalTree;
    right = new EvalTree;

    expression.erase(expression.length()-1, 1);
    left->build(expression);
    right->build(expression);
}

//the function to evaluate the expression that the tree holds
int EvalTree::evaluate(){
    if(left==NULL || right==NULL)
        return operand;
    
    if(operate == '+')
        return (left->evaluate()+right->evaluate());
    if(operate == '-')
        return (left->evaluate()-right->evaluate());
    if(operate == '*')
        return (left->evaluate()*right->evaluate());
    else 
        return (left->evaluate()/right->evaluate());
}
    
//function to print out the tree in postorder form
void EvalTree::print_postorder(){
    if(left==NULL || right==NULL){
        cout<< operand << " ";
        return;
    }
    left->print_postorder();
    right->print_postorder();
    cout << operate << " ";
    
}

//function to print out the tree in preorder form
void EvalTree::print_preorder(){
    if(left==NULL || right==NULL){
        cout<< operand << " ";
        return;
    }
    cout << operate << " ";
    left->print_preorder();
    right->print_preorder();
    
    
}

//function to print out the tree in inorder form
void EvalTree::print_inorder(){
    if(left==NULL || right==NULL){
        cout<< operand << " ";
        return;
    }
    left->print_inorder();
    cout << operate << " ";
    right->print_inorder();
    
}