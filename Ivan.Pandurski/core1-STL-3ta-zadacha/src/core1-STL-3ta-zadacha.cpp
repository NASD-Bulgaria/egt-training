//============================================================================
// Name        : core1-STL-3ta-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	cout<<"How much integers u want to enter ";
	cin>>n;
	int  arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	stack<int> stackInt;
	for(int i=0;i<n;i++)
	{
		stackInt.push(arr[i]);
	}

		while(!stackInt.empty())
		{
		cout << stackInt.top() << ' ';
		stackInt.pop();
		}

	return 0;
}
