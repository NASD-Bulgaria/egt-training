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
#include <list>

using namespace std;

void removeNegative(istream_iterator<int> &);


int main()
{
	cout<<"Enter a sequence(end with 0): ";
	istream_iterator<int> inputInt(cin);

	removeNegative(inputInt);


	return 0;
}

void removeNegative(istream_iterator<int> &input)
{
	list<int> seq;

	while (*input != 0)
	{
		seq.push_back(*input);
		++input;
	}

	list<int>::iterator it;

	for(it = seq.begin(); it != seq.end(); ++it)
	{
		if(*it < 0)
		{
			seq.remove(*it);
			it = seq.begin();
		}
	}

	for(it = seq.begin(); it != seq.end(); ++it)
	{
		cout << *it<<", ";
	}
}
