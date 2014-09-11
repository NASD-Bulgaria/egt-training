//============================================================================
// Name        : Ex2_Lecture26.cpp
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

	int count = 1;
	int maxCount = 1;
	int maxValue = *it;
	value = *it;
	it++;
	while(it!=l.end())
	{
		if(*it!=value)
		{
			if(maxCount<count)
			{
				maxCount=count;
				maxValue=value;
			}
			value = *it;
			count = 1;
		}
		else count++;
		it++;
	}

	if(maxCount<count)
	{
		maxCount=count;
		maxValue=value;
	}

	cout<<"Value : "<<maxValue<<endl;
	cout<<"Count : "<<maxCount<<endl;
	return 0;
}
