//============================================================================
// Name        : ListSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

int main() {
	list <int> lst;
	list <int>::iterator p;
	int num;

	do
	{
		cout<<"Enter a number: ";
		cin>>num;
		if((num < 10)&&(num % 10 != 0))
		{
			break;
		}
		lst.push_back(num);
	}while(true);

	lst.sort();
	p = lst.begin();
	while(p != lst.end())
	{
		cout << *p << " ";
		p++;
	}


	return 0;
}
