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

using namespace std;

void findCountOfInts(istream_iterator<int> &);

int main()
{
	cout << "Enter a sequence of integers(enter 0 to stop): ";
	istream_iterator<int> inputInt(cin);

	findCountOfInts(inputInt);


	return 0;
}

void findCountOfInts(istream_iterator<int> &input)
{
	multimap<int, int> mmii;

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
		cout<<it -> first<<' '<<it -> second<<endl;
		++it;
	}

	map<int, int> result;

	map<int, int>::iterator resIt;

	for(it = mmii.begin(); it != mmii.end(); ++it)
	{
		int key = it->first;
		int value = it->second;

		result.insert(make_pair(key, value));

	}

	cout <<"The result is!"<<endl;

	for(resIt = result.begin(); resIt != result.end(); ++resIt)
	{
		int key = resIt->first;
		int value = resIt->second;

		cout<<key<<" "<< value<<endl;

	}
}






