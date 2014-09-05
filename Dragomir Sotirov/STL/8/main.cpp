#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> numbers;

	numbers.push_back(4);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(5);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(2);

	int counter = 0;
	list<int> newList = numbers;

	cout << "Old list: ";

	for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		for(list<int>::iterator jt = numbers.begin(); jt != numbers.end(); jt++)
		{
			if(*it == *jt)
			{
				counter++;
			}
		}

		if(counter % 2 != 0)
		{
			newList.remove(*it);
		}
		cout << *it << " ";
		counter = 0;
	}

	cout << "\nThe new list: ";

	for(list<int>::iterator it = newList.begin(); it != newList.end(); it++)
	{
		cout << *it << " ";
	}

	return 0;
}
