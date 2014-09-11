//============================================================================
// Name        : Ex5_Lecture26.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	list<int> l;
	int value;
	do{
		cout<<"Enter integer number ending of zero or \"0\" for exit : ";
		cin>>value;
		if(value%10==0) l.push_back(value);
	}while(value != 0);

	l.sort();

	list<int>::const_iterator it = l.begin();

	while(it!=l.end())
	{
		cout<<*it<<endl;;
		it++;
	}
	return 0;
}
