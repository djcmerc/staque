#include <iostream>
using namespace std;

#include "staque.h"

// Default Constructor
Staque::Staque()
	:myFront(0)
{}

// Inserts user input one by one into staque
void Staque::insert(const int value)
{
	// Inserts odd numbers into staque
	if (value % 2 == 1)
	{
		Node *newPtr = new Node(value, 0), *currPtr = myFront, *nextPtr;

		if (myFront == 0)
		{
			myFront = newPtr;
		}
		else
		{
			while (currPtr != 0)
			{
				nextPtr = currPtr->next;
				if (currPtr->next == 0)
				{
					currPtr->next = newPtr;
					newPtr->next = 0;
				}
				currPtr = nextPtr;
			}
		}
	}
	// Inserts even numbers into staque
	else
		myFront = new Node(value, myFront);
}

// Removes even numbers from staque
void Staque::removeFront()
{
	Node *currPtr = myFront, *nextPtr;

	nextPtr = currPtr->next;
	delete currPtr;
	myFront = nextPtr;
}

// Removes odd numbers from staque
void Staque::removeBack()
{
	Node *currPtr = myFront, *nextPtr;
	
	// Checks if only one node remaining
	if (currPtr->next == 0)
	{
		delete currPtr;
		myFront = 0;
	}
	else
		while (currPtr->next != 0)
		{
			nextPtr = currPtr->next;
			if (nextPtr->next == 0)
			{
				currPtr->next = 0;
				delete nextPtr;
			}
			else
				currPtr = nextPtr;
		}
}

// Displays the staque
void Staque::display(ostream &out)
{
	Node *ptr = myFront;

	if (myFront == 0)
		out << "The staque is empty.";
	else
		while (ptr != 0)
		{
			out << ptr->data << " ";
			ptr = ptr->next;
		}
}

// Checks for repeated inputs 
bool Staque::checkSame(int val)
{
	Node *ptr = myFront;

	while (ptr != 0)
	{
		if (val == ptr->data)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

// Overloads << to display staque in lieu of calling display function
ostream &operator<<(ostream &out, Staque &list)
{
	list.display(out);
	return out;
}
