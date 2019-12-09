//Mike Carrigan
// ECE 2620
// Lab 6 Doubly Linked Lists
#include "intdlllist.h"
#include <iostream>
#include <fstream>
using namespace std;

const int EMPTY_LIST = 1;

IntDLLList::~IntDLLList() 
{
	for (IntDLLNode *p; !isEmpty(); )
	{
		p = head -> next;
		delete head;
		head = p;
	} 
}

void IntDLLList::addToHead(int el)
{
	head = new IntDLLNode(el,head);
	if (tail == NULL)
	{
	tail = head;
	}
}

void IntDLLList::addToTail(int el)
{
	if (tail != NULL)
	{ 
		tail = new IntDLLNode(el, NULL, tail);
		tail -> prev -> next = tail;
	}
	else
	{
		head = tail = new IntDLLNode(el);
	}
}

int IntDLLList::deleteFromHead()
{
	if(!isEmpty())
	{
		int el = head -> info;
		IntDLLNode *tmp = head;
		if (head == tail)
		{
			head = tail = NULL;
		}
		else 
		{
			head = head -> next;
		}
		delete tmp;
		return (el);
	}
	else
		try
	{
		throw(EMPTY_LIST);
	}
	catch (int el)
	{
		cout << "exception occurred" << endl;
	}
}



int IntDLLList::deleteFromTail()
{
	if(head!=NULL)
	{
		int el = tail -> info;
		if (head == tail)
		{
			delete tail;
			head = tail = NULL;
		}
		else
		{
			tail = tail-> prev;
			delete tail->next;
			tail->next = NULL;
		}
	return (el);
	}
else try
	{
		throw(EMPTY_LIST);
	}
	catch (int el)
	{
		cout << "exception occurred" << endl;
	}
}


void IntDLLList::deleteNode(int el)
{
	if (head != NULL)
	{
		if (head == tail && el == head -> info)
		{
			delete head;
			head = tail = NULL;
		}
	}
	else
	{ 
		if (el == head -> info)
		{
			IntDLLNode *tmp = head;
			head = head -> next;
			delete tmp;

		}
		else 
		{ 
			IntDLLNode *pred, *tmp;
			for(pred = head, tmp = head -> next; tmp != NULL && tmp -> info != el; pred = pred-> next, tmp = tmp -> next);
			if (tmp != NULL)
			{ 
				pred -> next = tmp -> next;
			}
			if (tmp == tail)
			{
				tail = pred;
			}
			delete tmp;
		}
	}
}

bool IntDLLList::isInList(int el) const 
{
	IntDLLNode *tmp;
	for (tmp = head; tmp != NULL && tmp -> info != el; tmp = tmp -> next);
	return (tmp!= NULL);
}

void IntDLLList::addSorted(int i)
{
	IntDLLNode *tmp; 
	IntDLLNode *input;
	input = new IntDLLNode;
	input->info = i;
	
    /* Special case for the head end */
    if (head == NULL || head->info >= i) 
    { 
    	tmp = head;
		head = input;
		input->next = tmp;
		//tmp->prev=head;
    } 
	else if(head == tail){
		if(i<=head->info){
			tmp = head;
			head = input;
			input->next = tmp;
			//tmp->prev=head;
		}
		else{
			head->next = input;
			input->prev = head;
		}
	}
    else
    {  
        tmp = head; 
        while (tmp->next!=NULL && (tmp->next)->info < input->info) 
        { 
            tmp = tmp->next; 
        } 
        input->next = tmp->next; 
        tmp->next = input; 
    } 
}

void IntDLLList::printlist()
{
	IntDLLNode *tmp;
	for(tmp = head; tmp!=NULL; tmp = tmp->next){
		cout<< tmp->info <<endl;
	}
	
}