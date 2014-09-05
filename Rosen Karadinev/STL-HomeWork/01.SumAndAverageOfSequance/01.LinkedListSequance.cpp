//Write a program that reads from the console a
//sequence of positive integer numbers. The
//sequence ends when the number 0 is entered.
//Calculate and print the sum and average of the
//elements of the sequence. Use linked list.

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	list<int> myList;
	int number;

	int sum = 0;
	float average = 0;

	cout << "Enter a positive integer: ";
	cin >> number;

	while(number != 0)
	{

		myList.push_back(number);
		cout << "Enter a positive integer: ";
		cin >> number;
	}



	for(list<int>::iterator i = myList.begin(); i != myList.end(); i++)
	{
		sum += *i;
	}

	average = (float)sum / myList.size();

	cout << "The sum is " << sum << endl;
	cout << "The average is " << average << endl;

	return 0;
}
