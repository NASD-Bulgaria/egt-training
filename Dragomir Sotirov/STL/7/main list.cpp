#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	list<int> numbers;
	int number = 1;
	cout << "Zero-(0) Terminates." << endl;

	while (number != 0)
	{
		cout <<"Enter a value: ";
		cin >> number;
		numbers.push_back(number);
	}

	cout << "The list before removing numbers: " << endl;

	list<int> removed = numbers;

	for (list<int>::iterator i = numbers.begin() ; i != numbers.end() ; i ++)
	{
		cout << *i << " ";
		if(*i < 0)
		{
			removed.remove(*i);
		}
	}

	cout << "The list after removing is: " << endl;

	for (list<int>::iterator i = removed.begin() ; i != removed.end() ; i ++)
	{
		cout << *i << " " ;
	}

	return 0;
}
