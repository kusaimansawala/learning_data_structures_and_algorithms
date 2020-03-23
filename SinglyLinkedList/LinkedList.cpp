#include "LinkedList.h"
//LinkedList.c
LinkedList::LinkedList() {
	HEAD = TAIL= NULL;
	lengthOfList = 0;
	cout<<"The object is been instanciated"<<endl;
}
//Show the contents of the LinkedList
void LinkedList::showTheLinkedList() {
	struct node* ptr;
	if(HEAD == NULL) {
		cout<<"There are no contents to show"<<endl;
		return;
	}
	ptr = HEAD;
	cout<<"The contents of the LinkedList are: ";
	while(ptr) {
		cout<<ptr->value<<" ";
		ptr = ptr->NEXT;
	}
}
//Append: Add a node to the very end
void LinkedList::appendToLinkedList(int val) {
	struct node* ptr;
	ptr = new struct node;
	ptr->value = val;
	ptr->NEXT = NULL;
	if(HEAD == NULL) {
		HEAD = TAIL = ptr;
		++lengthOfList;
	}
	else {
		TAIL->NEXT = ptr;
		TAIL = ptr;
		++lengthOfList;
	}
}
//Prepend: Add the node at the start
void LinkedList::prependToLinkList(int val) {
	struct node* ptr;
	ptr = new struct node;
	ptr->value = val;
	if(HEAD == NULL) {
		HEAD = TAIL = ptr;
		ptr->NEXT = NULL;
		++lengthOfList;
	}
	else {
		ptr->NEXT = HEAD;
		HEAD = ptr;
		++lengthOfList;
	}
}
//Insert: Insert at the given location in the LinkedList
void LinkedList::insertToLinkedList(unsigned int index, int val) {
	int location = index + 1, i;
	struct node* ptr = HEAD, *prev = NULL, *ptrNew;
	if(location > lengthOfList) {
		cout<<"Such index value does not exists"<<endl;
		return;
	}
	else if((location == lengthOfList) || (HEAD == NULL)) {
		appendToLinkedList(val);
		return;
	}
	else if(location == 1) {
		prependToLinkList(val);
		return;
	}
	for(i=1; i<location; i++) {
		prev = ptr;
		ptr = ptr->NEXT;
	}
	ptrNew = new struct node;
	ptrNew->value = val;
	ptrNew->NEXT = ptr;
	prev->NEXT = ptrNew;
	++lengthOfList;
}
//Remove: remove the node from the specified index in the LinkedList
void LinkedList::removeFromLinkedList(unsigned int index) {
	unsigned int location = index + 1, i;
	struct node *ptr = HEAD, *prev = NULL;
	if(location > lengthOfList) {
		cout<<"Such an index does not exists"<<endl;
		return;
	}
	if(location == 1) {
		HEAD = ptr->NEXT;
		delete ptr;
		--lengthOfList;
		goto exit;
	}
	for(i=1; i<location; i++) {
		prev = ptr;
		ptr = ptr->NEXT;
	}
	prev->NEXT = ptr->NEXT;
	delete ptr;
	if(location == lengthOfList) {
		TAIL = prev;
		TAIL->NEXT = NULL;
	}
	--lengthOfList;
exit: if(lengthOfList == 0) {
	      HEAD = TAIL = NULL;
      }
}
//Print the length of the LinkedList
int LinkedList::getLengthOfLinkedList() {
	return lengthOfList;
}
//Destructor
LinkedList::~LinkedList() {
	if(HEAD == NULL) {
		return;
	}
	while(HEAD) {
		struct node* ptr;
		ptr = HEAD;
		HEAD = HEAD->NEXT;
		delete ptr;
	}
	cout<<"The object has been destructed"<<endl;
}

