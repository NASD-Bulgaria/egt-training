//============================================================================
// Name        : CountNumbers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
using namespace std;


int main() {
	multiset<int> set1;
	multiset<int>::iterator i;
	int num;
	int first;
	int second;
	int count = 1;

	do
	{
		cout<<"Enter a number: ";
		cin>>num;
		if(num == -1)
		{
			break;
		}
		set1.insert(num);
	}while(true);


	i = set1.begin();
	while(i != set1.end())
	{
		first = *i;
		i++;
		second = *i;
		if(first == second)
		{
			count++;
		}
		else
		{
			cout << first << " is " << count <<" times"<<endl;
			count = 1;
		}
	}
	return 0;
}
