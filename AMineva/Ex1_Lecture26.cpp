//============================================================================
// Name        : Ex1_Lecture26.cpp
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
		cout<<"Enter positive integer number or \"0\" for exit : ";
		cin>>value;
		if(value>0) l.push_back(value);
	}while(value != 0);

	list<int>::const_iterator it = l.begin();

	int sum = 0;
	while(it!=l.end())
	{
		sum+=*it;
		it++;
	}

	cout<<"Sum is : "<<sum<<endl;
	cout<<"Average is : "<<(double)sum/l.size()<<endl;

	return 0;
}
