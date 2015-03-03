/*
Karan Daryanani
Lab 4 1/27/14
Monday 5PM Lab
*/

#include <iostream>
#include <cassert>

using namespace std;

class List{
public:
  List();
  ~List();
  List(const List&);
  double pop();
  const List& operator=(const List&);
  friend ostream& operator<<(ostream&, const List&);
  void push(const double&);
private:
   class node{
    public:
      node(double, node*);
      double data;
      node *next;
  };
  node *list;
  int size;
  node *cursor;
};


double List::pop(){
  assert(size>0);
  double tmp;
  if(size>1){
    cursor=list->next->next;
    tmp=list->next->data;
    delete list->next;
    list->next=cursor;
    size--;
}
  else if(size==1){
    tmp=list->next->data;
    delete list->next;
    list->next=NULL;
    size--;
  }
  return tmp;
}

List::node::node(double a, node* n){
  data = a;
  next = n;
}

List::List(){
  size = 0;
  list = cursor = new node(0, NULL);
}


List::~List(){
  node *tmp = list;
  while (tmp->next!=NULL){
    list = list->next;
    delete tmp;
    tmp = list;
  }
  delete list;
}


List::List(const List& rhs){
  node *tmp = rhs.list->next;
  this->list = new node(0, NULL);
  while(tmp->next!=NULL){
    push(tmp->data);
    tmp = tmp->next;
    }
  push(tmp->data);
}

const List& List::operator=(const List & rhs){
   this->size = rhs.size;
   this->list = rhs.list;
   return *this;
}

ostream& operator<<(ostream& out, const List& rhs){  
  List::node *tmp = rhs.list->next;
  while (tmp!=NULL){
    out<< tmp->data <<", ";
    tmp = tmp->next;
  }
  return out;
}

void List::push(const double& x){
  node *tmp = new node(x, NULL);
  cursor = list;
  tmp->next=cursor->next;
  cursor->next=tmp;
  size++;
}

