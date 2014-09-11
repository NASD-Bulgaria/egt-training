//============================================================================
// Name        : Ex3_Lecture26.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n;
	cout << "Enter n : ";
	cin>>n;

	stack<int> s;
	int value;
	for(int i=0; i<n; i++)
	{
		cout << "Enter value : ";
		cin>>value;
		s.push(value);
	}

	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}
