/*
Karan Daryanani
Lab 3 1/20/14
Monday 5PM Lab
*/

#include <iostream>

using namespace std;

class List{
public:
  List();
  ~List();
  List(const List&);
  const List& operator=(const List&);
  friend ostream& operator<<(ostream&, const List&);
  void insert(const int&);
private:
   class node{
    public:
      node(int, node*);
      int data;
      node *next;
  };
  node *list;
  int size;
  node *cursor;
};

List::node::node(int a, node* n){
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
    insert(tmp->data);
    tmp = tmp->next;
    }
  insert(tmp->data);
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

void List::insert(const int& x){
  node *tmp = new node(x, NULL);
  cursor = list;
  while (cursor->next!=NULL){
    cursor = cursor->next;
  }
  cursor->next=tmp;
  cursor = tmp;
  size++;
}

