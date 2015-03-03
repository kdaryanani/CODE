//Karan Daryanani, Coen12,


//This header file initializes the deque along with its functions. 
class Deque{
	int count;
	class node *head;

	
public:

	Deque();

	~Deque();

	int size();

	void addFirst(int x);

	void addLast(int x);

	int removeFirst();

	int removeLast();

	int getFirst();

	int getLast();

};	
