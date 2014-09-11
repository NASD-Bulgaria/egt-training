//============================================================================
// Name        : Ex9_Lecture26.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <map>
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
	int half = (int)l.size()/2-1;
	while(it != s.end())
	{
		counter = count(l.begin(), l.end(), *it);
		if(counter>half) cout<<*it<<endl;
		it++;
	}

	return 0;
}
