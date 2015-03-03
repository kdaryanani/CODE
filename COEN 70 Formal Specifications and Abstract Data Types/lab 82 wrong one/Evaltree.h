#include <iostream>
#include <cctype>

using namespace std;

class EvalTree{
public:
    void build(string &expression);
    int evaluate();
    void print_preorder();
    void print_inorder();
    void print_postorder();

    int operand;
    char operate;
    
private:
    EvalTree *left;
    EvalTree *right;
};


 void EvalTree::build(string &expression){ //maybe return type EvalTree&
    //if(expression.empty()) return NULL;
    
    string::iterator it=expression.end();
    if(isdigit(*it)){
        operand = *it;
        return;
    }
    else
        operate = *it;
    
    *this->left = EvalTree left;
    *this->right = EvalTree right;
    
     expression.erase(it);
     left->build(expression);
     right->build(expression);
}

int EvalTree::evaluate(){
    if(left==NULL || right==NULL)
        return operand;
    
    if(operate == '+')
        return (left->evaluate()+right->evaluate());
    if(operate == '-')
        return (left->evaluate()-right->evaluate());
    if(operate == '*')
        return (left->evaluate()*right->evaluate());
    if(operate == '/')
        return (left->evaluate()/right->evaluate());
}
    

void EvalTree::print_postorder(){
    if(left==NULL || right==NULL){
        cout<< operand << " ";
        return;
    }
    left->print_postorder();
    right->print_postorder();
    cout << operate << " ";
    
}
void EvalTree::print_preorder(){
    if(left==NULL || right==NULL){
        cout<< operand << " ";
        return;
    }
    cout << operate << " ";
    left->print_preorder();
    right->print_preorder();
    
    
}
void EvalTree::print_inorder(){
    if(left==NULL || right==NULL){
        cout<< operand << " ";
        return;
    }
    left->print_inorder();
    cout << operate << " ";
    right->print_inorder();
    
}