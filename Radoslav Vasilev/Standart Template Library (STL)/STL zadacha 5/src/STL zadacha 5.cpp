//============================================================================
// Name        : STL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	list <int> numbers;
	bool check =true;
	int num;
	list<int>::iterator it;
	while(check )
	{
		cout << "Please enter a intiger"<<endl;
		cin >>num;

		numbers.push_back(num);
		cout<<" do you want to continue 1- yes/0 no"<<endl;
		cin>>check;
	}

	numbers.sort();
	for (it=numbers.begin(); it!=numbers.end(); ++it)
	{
	    cout << ' ' << *it;

	}
	return 0;
}
