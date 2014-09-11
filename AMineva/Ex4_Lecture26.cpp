//============================================================================
// Name        : Ex4_Lecture26.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int n = 2;
	q.push(n);
	for(int i=0; i<100; i++)
	{
		q.push(q.front()+1);
		q.push(2*q.front()+1);
		q.push(q.front()+2);
		cout<<q.front()<<"\t";
		q.pop();
	}
	return 0;
}
