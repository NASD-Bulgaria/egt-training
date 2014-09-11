//============================================================================
// Name        : Ex7_Lecture26.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

bool positive(int n)
{
	return n<0;
}

int main()
{
	list<int>l;

	int value;
	do{
		cout<<"Enter number or \"0\" for exit : ";
		cin>>value;
		l.push_back(value);
	}while(value!=0);

	l.remove_if(positive);

	list<int>::const_iterator it = l.begin();
	while(it != l.end())
	{
		cout<<*it<<"\t";
		it++;
	}
	return 0;
}
