/*
Karan Daryanani
Lab 5 2/3/14
Monday 5PM Lab
*/

#include <iostream>

using namespace std;

class List{//Defining the class implementation
public:
  List();//constructor
  ~List();//destructor default
  List(const List&);
  const List& operator=(const List&);
  friend ostream& operator<<(ostream&, const List&);
  void insert(const int&);
  void replace(const int&, const int&);
protected://changed from private to protected so everyone can access function(derivcative
   class node{//defining the node for the linked list
    public:
      node(int, node*);
      int data;
      node *next;
  };
  node *list;
  int size;
  node *cursor;
};

class OrderedList:public List{//Derived class and added new replace and insert
public:
  void replace(const int&, const int&);
  void insert(const int&);
};

  
List::node::node(int a, node* n){//list constructors below
  data = a;
  next = n;
}

List::List(){
  size = 0;
  list = cursor = new node(0, NULL);
}


List::~List(){//destructor
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
  this->list = new node(0, NULL);//this constructor takes different arguments
  while(tmp->next!=NULL){
    insert(tmp->data);
    tmp = tmp->next;
    }
  insert(tmp->data);
}

void OrderedList::replace(const int& x, const int& y){
   node *tmp=list;
   cursor=list;//setting the cursor to the front of list
   int i=0;
   if(size<x || x<=0) return; //making sure valid statement
   while (cursor->next!=NULL){
	if(i==x-1) break;	//break when the spot is found. 
	cursor=cursor->next; //implementation is for the element after, the -1 fixes that
	i++;
   }
   tmp=cursor->next;
   cursor->next=cursor->next->next;
   delete tmp;//deletes the node
   insert(y);//inserts new node
}

void List::replace(const int& x, const int& y){//replace function for the actual list(unordered
  cursor=list;
  int i=0;
  if (size<x || x<=0){
      cout <<"break here" <<endl;
      return;
  }
  while(cursor->next!=NULL){ // the loop to find index then replace data
    if(i==x){
	cursor->data=y;
	return;
    }
    cursor=cursor->next;
    i++;
  }
}

const List& List::operator=(const List & rhs){
   this->size = rhs.size;
   this->list = rhs.list; // operator= as defined in class
   return *this;
}

ostream& operator<<(ostream& out, const List& rhs){  //output stream 
  List::node *tmp = rhs.list->next;
  while (tmp!=NULL){
    out<< tmp->data <<", ";
    tmp = tmp->next;
  }
  return out;
}

void OrderedList::insert(const int& x){
  node *tmp = new node(x, NULL);
  cursor = list;
  while (cursor->next!=NULL && cursor->next->data<x){
    cursor = cursor->next;
  } // ordered list with sorting insert. Based on index value
  tmp->next=cursor->next;
  cursor->next=tmp;
  cursor = tmp;
  size++;
}

void List::insert(const int& x){ //altered list fucntino
  node *tmp = new node(x, NULL);
  cursor = list;
  while (cursor->next!=NULL){
    cursor = cursor->next;
  }
  cursor->next=tmp;
  cursor = tmp;
  size++;
}
