#include <iostream>
using namespace std;

#include "staque.h"

int main()
{
	Staque list;
	int num, even, odd;

	cout << "Staque" << endl << endl;
	cout << "Enter the following numbers in any desired sequence. Even numbers will be inserted to the front of the list and odd numbers will be placed in the back."
		<< endl << endl << "1, 2, 3, 4, 6, 8, 9" << endl << endl;

	// Prompts the user to input numbers from the given list and inserts the input into the staque
	for (int i = 0; i < 7; i++)
	{
		do
		{
			cout << "Enter the number to be inserted: ";
			cin >> num;
			// Checks for any input outside the given numbers
			if (num <= 0 || num == 5 || num == 7 || num > 9)
			{
				cout << "Please enter a valid number from the given list." << endl;
			}
			// Checks for repeated inputs
			else if (list.checkSame(num))
				cout << "Number already inserted. Please enter an unused number from the given list." << endl;
		} while (num <= 0 || num == 5 || num == 7 || num > 9 || list.checkSame(num));
		list.insert(num);
	}
	// Displays the sorted staque
	cout << endl << "List: " << list << endl << endl;

	// Prompts user to delete any number of evens and odds
	cout << "Now enter the number of even integers and odd integers to remove." << endl;
	cout << "Even(s): ";
	do
	{
		cin >> even;
		// Checks if input is negative or exceeds number of evens
		if (even < 0 || even > 4)
			cout << "Please enter a valid number for the number of evens you would like to delete: ";
	} while (even < 0 || even > 4);
	
	cout << "Odd(s): ";
	do
	{
		cin >> odd;
		// Checks if input is negative or exceeds number of odds
		if (odd < 0 || odd > 3)
			cout << "Please enter a valid number for the number of odds you would like to delete: ";
	} while (odd < 0 || odd > 3);
	
	// Deletes odds and evens based on user input
	for (int i = 0; i < even; i++)
	{
		list.removeFront();
	}
	for (int i = 0; i < odd; i++)
	{
		list.removeBack();
	}
	// Displays updated staque
	cout << endl << "New List: " << list << endl << endl;

	return 0;
}
