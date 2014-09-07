//============================================================================
// Name        : RevStack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stack>
#include <iostream>
using namespace std;

int main() {
	cout << "Enter number of integers" << endl;

	int n;
	cin>>n;
	int num;
	int tmp;
	stack <int> stck;
	stack <int> rev;
	for(int i = 0; i < n; i++ )
	{
		cout << "Enter integer: ";
		cin >> num;
		stck.push(num);
	}
	while(!stck.empty())
	{
		cout << stck.top() << " ";
		stck.top() = tmp;
		rev.push(tmp);
		stck.pop();
	}
	return 0;
}
