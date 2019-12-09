// Mike Carrigan
// ECE 2620
// Lab 6 Doubly Linked Lists


#ifndef _INT_DLL_NODE_H_
#define _INT_DLL_NODE_H_
using namespace std;
#define NULL 0


class IntDLLNode
{

friend class IntDLLList;
	
public:
	IntDLLNode() 
	{
		next = prev = NULL;
	}

	IntDLLNode(int el, IntDLLNode *n = NULL, IntDLLNode *p = NULL)
	{
		info = el;
		next = n;
		prev = p;
	}

protected:
	int info;
	IntDLLNode *next, *prev;

private:

};

#endif // _INT_DLprevL_NODE_H_

