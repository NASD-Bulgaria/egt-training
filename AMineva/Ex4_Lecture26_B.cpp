//============================================================================
// Name        : Ex4_Lecture26_B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> l;
	int value;
	do{
		cout<<"Enter number or \"0\" for exit : ";
		cin>>value;
		if(value>0) l.push_back(value);
	}while(value != 0);

	l.sort();
	list<int>::const_iterator it = l.begin();
	int count = 1;
	int n = 3;
	int tempValue = *it;
	it++;
	while(it!=l.end())
	{
		if(*it!=tempValue)
		{
			if(n==count) l.remove(tempValue);
			tempValue = *it;
			count = 1;
		}
		else count++;
		it++;
	}

	if(n==count) l.remove(tempValue);

	list<int>::const_iterator itL = l.begin();
	while(itL != l.end())
	{
		cout<<*itL<<"\t";
		itL++;
	}

	return 0;
}
