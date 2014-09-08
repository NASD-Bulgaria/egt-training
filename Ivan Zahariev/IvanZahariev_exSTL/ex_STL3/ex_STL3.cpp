//============================================================================
// Name        : ex_STL3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	int check = 1;
	int num;
	stack <int> numbers;
	while(check ==1)
	{
		cout<<"Enter integers: "<<endl;
		cin>>num;

		numbers.push(num);
		cout<<"Do you want to continue? 1 for yes 0 for no"<<endl;
		cin>>check;
	}
	while(!numbers.empty())
	{
		cout<<numbers.top()<< '	';
		numbers.pop();
	}
	return 0;
}
