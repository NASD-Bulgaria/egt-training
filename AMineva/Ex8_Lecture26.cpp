//============================================================================
// Name        : Ex8_Lecture26.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	list<int>l;
	set<int>s;
	int value;

	do{
		cout<<"Enter number  or \"0\" for exit : ";
		cin>>value;
		l.push_back(value);
		s.insert(value);
	}while(value!=0);

	set<int>::const_iterator it = s.begin();
	int counter;
	while(it != s.end())
	{
		counter = count(l.begin(), l.end(), *it);
		if(counter%2 != 0) l.remove(*it);
		it++;
	}

	list<int>::const_iterator it_l = l.begin();
	while(it_l != l.end())
	{
		cout<<*it_l<<"\t";
		it_l++;
	}
	return 0;
}
