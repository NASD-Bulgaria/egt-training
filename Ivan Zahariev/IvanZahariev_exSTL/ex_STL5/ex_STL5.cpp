//============================================================================
// Name        : ex_STL5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main()
{
	int n;
	list<int> newList;
	int temp;
	list <int> ::iterator it;

	cout<<"Enter int for N: ";
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cout<<"Enter int: ";
		cin>>temp;
		newList.push_back(temp);
	}

	newList.sort();

	for (it=newList.begin(); it!=newList.end(); ++it)
	{
		cout<< '		'<<*it;
	}

	return 0;
}
