#include "LinkedList.h"
//LinkedList.c
LinkedList::LinkedList() {
	HEAD = TAIL = PREV = NULL;
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
	cout<<endl;
}
//Append: Add a node to the very end
void LinkedList::appendToLinkedList(int val) {
	struct node* ptr;
	ptr = new struct node;
	ptr->value = val;
	ptr->NEXT = NULL;
	//The below condition will hit when you try to append in the empty linked list
	if(HEAD == NULL) {
		HEAD = TAIL = ptr;
		ptr->PREV = NULL;
		++lengthOfList;
	}
	else {
		TAIL->NEXT = ptr;
		ptr->PREV = TAIL;
		TAIL = ptr;
		++lengthOfList;
	}
}
//Prepend: Add the node at the start
void LinkedList::prependToLinkList(int val) {
	struct node* ptr;
	ptr = new struct node;
	ptr->value = val;
	//The below condition will hit when you the linked list is empty
	if(HEAD == NULL) {
		HEAD = TAIL = ptr;
		ptr->NEXT = NULL;
		++lengthOfList;
	}
	else {
		ptr->NEXT = HEAD;
		HEAD->PREV = ptr;
		HEAD = ptr;
		++lengthOfList;
	}
	ptr->PREV = NULL;
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
	ptrNew->PREV = prev;
	prev->NEXT = ptrNew;
	ptr->PREV = ptrNew;
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
		HEAD->PREV = NULL;
		delete ptr;
		--lengthOfList;
		goto exit;
	}
	for(i=1; i<location; i++) {
		prev = ptr;
		ptr = ptr->NEXT;
	}
	prev->NEXT = ptr->NEXT;
	ptr->NEXT->PREV = prev;
	delete ptr;
	if(location == lengthOfList) {
		TAIL = prev;
		TAIL->NEXT = NULL;
	}
	--lengthOfList;
exit: if(lengthOfList == 0) {
	      HEAD = TAIL = PREV = NULL;
      }
}
//Print the length of the LinkedList
int LinkedList::getLengthOfLinkedList() {
	return lengthOfList;
}
//Reverse: Reverse the linked list
void LinkedList::reverseTheLinkedList() {
	struct node *traversePtr = HEAD, *swapPtr = NULL, *holdPtr = NULL;
	if(HEAD == NULL) {
		cout<<"The list is empty, hence no need of reversing"<<endl;
		return;
	}
	while(traversePtr) {
		holdPtr = traversePtr;
		traversePtr = traversePtr->NEXT;
		swapPtr = holdPtr->NEXT;
		holdPtr->NEXT = holdPtr->PREV;
		holdPtr->PREV = swapPtr;
	}
	swapPtr = HEAD;
	HEAD = TAIL;
	TAIL = swapPtr;
	showTheLinkedList();
}
//Print the list in reverse order
void LinkedList::printReverse() {
	struct node* ptr;
	if(TAIL == NULL) {
		cout<<"There are no contents to show"<<endl;
		return;
	}
	ptr = TAIL;
	cout<<"The contents of the LinkedList are: ";
	while(ptr) {
		cout<<ptr->value<<" ";
		ptr = ptr->PREV;
	}
	cout<<endl;
}
//Destructor
LinkedList::~LinkedList() {
	if(HEAD == NULL) {
		return;
	}
	while(HEAD->NEXT) {
		struct node* ptr;
		ptr = HEAD;
		HEAD = HEAD->NEXT;
		delete ptr;
	}
	delete HEAD;
	cout<<"The object has been destructed"<<endl;
}
