//============================================================================
// Name        : ShortestSeq.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;
stack<int> stck;
int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	int m;
	do
	{
		cout << "Enter m: ";
		cin >> m;
	}while(m <= n);

	int tmp = m;
	stck.push(tmp);
	while(tmp / 2 >= n)
	{
		if(tmp % 2 == 0)
		{
			tmp /= 2;
			stck.push(tmp);
		}
		else
		{
			tmp -= 1;
			stck.push(tmp);
			tmp /= 2;
			stck.push(tmp);
		}
	}

	while(tmp - 2 >= n)
	{
		tmp -= 2;
		stck.push(tmp);
	}

	while(tmp - 1 >= n)
	{
		tmp -= 1;
		stck.push(tmp);
	}

	while(!stck.empty())
	{
		cout << stck.top() << " ";
		stck.pop();
	}
	return 0;
}
