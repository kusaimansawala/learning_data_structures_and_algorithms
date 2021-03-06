//LinkedList.h
#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *NEXT;
};

class LinkedList {
	private:
		struct node *HEAD, *TAIL;
		unsigned int lengthOfList = 0; 
	public:
		//Constructor
		LinkedList();
		//Show the contents of the LinkedList
		void showTheLinkedList(); 
		//Append: Add a node to the very end
		void appendToLinkedList(int val);
		//Prepend: Add the node at the start
		void prependToLinkList(int val);
		//Insert: Insert at the given location in the LinkedList
		void insertToLinkedList(unsigned int index, int val);
		//Remove: remove the node from the specified index in the LinkedList
		void removeFromLinkedList(unsigned int index);
		//Print the length of the LinkedList
		int getLengthOfLinkedList();
		//Destructor
		~LinkedList();
};
