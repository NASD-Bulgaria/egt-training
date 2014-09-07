//============================================================================
// Name        : QueueSeq.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue <int> que;
	queue <int> res;

	int n;
	cout << "Enter a number: ";
	cin >> n;
	int res1 = n;
	int res2;
	int res3;
	int res4;
	int count = 1;;
	que.push(res1);
	res.push(res1);
	while(count < 100)
	{
		res2 = que.front() + 1;
		que.push(res2);
		res.push(res2);
		count++;
		res3 = que.front() * 2 + 1;
		que.push(res3);
		res.push(res3);
		count++;
		res4 = que.front() + 2;
		que.push(res4);
		res.push(res4);
		count++;
		que.pop();
	}

	while (!res.empty())
	{
		cout << res.front() << " ";
		res.pop();
	}
	return 0;
}
