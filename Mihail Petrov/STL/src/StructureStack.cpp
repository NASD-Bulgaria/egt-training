//============================================================================
// Name        : StructureStack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> integers;
	int N;
	cout<<"Enter N!"<<endl;
	cin>>N;
	int number;
	while(N >0)
	{
		cout<<"Please enter a integer!!"<<endl;
		cin>>number;
		integers.push(number);
		N--;
	}
	while(!integers.empty())
	{
		cout<<integers.top()<<" ";
		integers.pop();
	}
	return 0;
}
