//============================================================================
// Name        : STL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <list>

using namespace std;

void removeOddCount(istream_iterator<int> &);

int main()
{
	cout <<"Enter a sequence(end with 0): ";
	istream_iterator<int> inputInt(cin);

	removeOddCount(inputInt);

	return 0;
}

void removeOddCount(istream_iterator<int> &input)
{
	multimap<int, int> mmii;
	list<int> result;

	multimap<int, int>::iterator it;

	while(*input != 0)
	{
		mmii.insert(make_pair(*input, 0));
		input++;
	}

	it = mmii.begin();

	while (it != mmii.end())
	{
		it-> second = mmii.count((*it).first);
		++it;
	}

	for(it = mmii.begin(); it != mmii.end(); ++it)
	{
		if((*it).second % 2 == 0)
		{
			result.push_back((*it).first);
		}
	}

	list<int>::iterator listIt;

	for (listIt = result.begin(); listIt != result.end(); ++listIt)
	{
		cout << *listIt<<", ";
	}
}
