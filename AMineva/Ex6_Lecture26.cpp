//============================================================================
// Name        : Ex6_Lecture26.cpp
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
	list<int>l;
	int value;
	do{
		cout<<"Enter positive number or \"0\" for exit : ";
		cin>>value;
		l.push_back(value);
	}while(value!=0);

	l.sort();

	list<int>::const_iterator it = l.begin();
	int count = 1;
	value = *it;
	it++;
	while(it!=l.end())
	{
		if(value!=*it)
		{
			cout<<"Value : "<<value<<" - "<<count<<endl;
			count = 1;
			value = *it;
		}
		else count++;
		it++;
	}
	it--;

	if(value==*it)cout<<"Value : "<<value<<" - "<<count<<endl;
	return 0;
}
