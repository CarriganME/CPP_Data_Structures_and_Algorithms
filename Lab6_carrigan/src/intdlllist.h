// Mike Carrigan
// ECE 2620
// Lab 6 Doubly Linked Lists

#ifndef _INT_DLL_LIST_H_
#define _INT_DLL_LIST_H_
#include "intdllnode.h"
using namespace std;


class IntDLLList
{
	
private:
	IntDLLNode *head, *tail;
	
protected:	

public:
	IntDLLList(){head = tail = NULL;}
	~IntDLLList();
	int isEmpty(){return (head == NULL);}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int) const;
	void addSorted(int i);
	void printlist();


	
};

#endif // _INT_DLL_LIST_H_

