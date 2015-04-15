/*-----------------------------------------------------------------------------
Class:        Template class stack.h

Functions:    
			  Constructor
			  initialize
			  push
			  top
			  pop
			  print
			  destructor
-----------------------------------------------------------------------------*/
#ifndef STACK_H
#define STACK_H
using namespace std;
#include <cstdlib>
#include <iostream>

template <class tType>
class stack
{
public:
	
	stack();
	
	void initialize();
	
	void push(tType x, tType q);
	
	int top(tType x);
	
	void pop();
	
	void print();
	
	~stack();

private:
	struct stackNode
	{
		
		tType sym;
		
		tType sym2;
		
		stackNode * link;
	};
	
	stackNode * head;
	
	stackNode * current;
};


template <class tType>
stack<tType>::stack()
{
	//empty constructor	
}
/*-----------------------------------------------------------------------------
Function:     initialize

Inputs:       none

Acts as constructor in place of the do nothing constructor.  Initializes head
and current to null.
-----------------------------------------------------------------------------*/
template <class tType>
void stack<tType>:: initialize()
{
	head = NULL;
	
	current = NULL; 
}

/*-----------------------------------------------------------------------------
Function:     Push

inputs:       two template objects, x and q

creates a new node at the top of the stack for the opening character(s)
-----------------------------------------------------------------------------*/
template <class tType>
void stack<tType>::push(tType x, tType q)
{
	
	stackNode * n = new stackNode;
	
	n->sym = x;
	
	n->sym2 = q;
	
	n->link = head;
    
	head = n;
}

/*-----------------------------------------------------------------------------
Function: Top

inputs:   Template object x

Checks the top of the stack against the current char to see it pop needs to be
called.
-----------------------------------------------------------------------------*/
template <class tType>
int stack<tType>::top(tType x)
{
	if (head == NULL) 
	{
		 return 0;
	}
	
	else
	{
		char z = head->sym;
		
		if ((z == '(') && (x == ')'))
		{
			pop();
		}
		
		else if ((z == '{' && x == '}'))
		{
			pop();
		}
		
		else if ((z == '[') && (x == ']'))
		{
			pop();
		}
		
		else if ((z == '/') && (x == '/'))
		{
			pop();
		}
		
		else return 0;
	}
}

/*-----------------------------------------------------------------------------
Function:     Pop

inputs:       None

Deletes the node at the top of the stack when its match has been found in the
top function.
-----------------------------------------------------------------------------*/
template <class tType>
void stack<tType>::pop()
{
	
	stackNode * temp = new stackNode;
	
	temp = head;
	
	head = head->link;
	
	delete temp;
	
	
}

/*-----------------------------------------------------------------------------
Function:     Print

Inputs:       None

Reports which characters in the file were unbalanced or if the stack is empty 
that the list was completely balanced.
-----------------------------------------------------------------------------*/
template <class tType>
void stack<tType>::print()
{
	if (head == NULL)
	{
		cout << "The list is completely balanced." << endl;
	}
	else
	{	
		cout << "The following right symbols are unbalanced: " << endl;
		
		current = head;
		
		while (current != NULL)
		{	
				cout << current->sym << current->sym2 << endl;
				current = current->link;
		}
	}
}

/*-----------------------------------------------------------------------------
Function:     Destructor

Inputs:       none

Deletes what ever is left over on the stack.
-----------------------------------------------------------------------------*/
template <class tType>
stack<tType>::~stack()
{
	current = head;
	
	stackNode * temp = new stackNode;
	
	while (current != NULL)
	{
		
		temp = current;
		
		current = current->link;
		
		delete temp;
	}
	head = NULL;
}
#endif 
