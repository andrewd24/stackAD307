/*-----------------------------------------------------------------------------
Programmer:   Andrew Douglas

Program:      Node Based Stack - Balancing characters - program searches through
			  a hard coded file, stack.cpp, searching for unbalanced characters
			  such as parentheses, square and curly brackets, and /* checking if 
			  they are balanced in the way that text editors do.  If an open 
			  symbol is found, it is pushed on to the stack.  If a close is found,
			  if its match is at the top of the stack, the stack is popped.  If the
			  stack is not empty at the end, the unbalanced characters are reported.

Course:       CSC 307 - Data Structures using C++

Instructor:   Tom Rishel
-----------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "stack.h"


using namespace std;

int main()
{
	ifstream myFile;
	
	myFile.open("stack.cpp");

	if (!myFile.is_open())
	{
		cout << "Could not open the file.  Terminating." << endl;
		
		return 1;
	}
	
	else
	{
		stack<char> test;
		
		test.initialize();
		
		char x;
		
		while (myFile.good())
		{
			char q = ' ';
			
			myFile >> x;
			
		    if ((x == '{') || (x == '[') ||  (x == '('))
			{
				test.push(x, q);
			}
			
			else if ((x == '}' || x == ']' || x == ')'))
			{
				test.top(x);
			}
			
			else if (x == '/')
			{
				myFile >> q;
			
				if ((x == '/') && (q == '*'))
				{
					test.push(x, q);
				}
				
				else continue;
			}
			
			else if (x == '*')
			{
				myFile >> q;
				
				if ((x == '*') && (q == '/'))
				{
					test.top(q);
				}
				
				else continue;
			}
		
		}
		
		test.print();
	}
	
	myFile.close();
		
	cin.get();
	return 0;
}