#include <iostream>
using namespace std;

#ifndef STAQUE
#define STAQUE

class Staque
{
public:
	Staque();
	void insert(const int value);
	void removeFront();
	void removeBack();
	void display(ostream &out);
	bool checkSame(int val);
private:
	class Node
	{
	public:
		int data;
		Node *next;
		Node(int data, Node *next = 0)
			:data(data), next(next)
		{}
	};
	Node *myFront;
};
ostream &operator<<(ostream &out, Staque &list);
#endif
