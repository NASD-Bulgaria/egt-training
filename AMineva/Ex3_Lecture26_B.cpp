//============================================================================
// Name        : Ex3_Lecture26_B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

bool isPowerOf_2(int x)
{
	if (x<=0)  return 0;
	return !(x & (x-1));
}

int main()
{
	list<int>l;
	int value;
	do{
		cout<<"Enter number or \"0\" for exit : ";
		cin>>value;
		l.push_back(value);
	}while(value != 0);

	l.remove_if(isPowerOf_2);

	list<int>::const_iterator it = l.begin();
	while(it != l.end())
	{
		cout<<*it<<"\t";
		it++;
	}

	return 0;
}
