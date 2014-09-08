//============================================================================
// Name        : ex_STL3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	queue <int> tempQue;
	int n;
	int temp;
	int counter = 0;

	cout<<"Enter N: "<<endl;
	cin>>n;

	tempQue.push(n);

	for (int i = 1; i < 101; ++i)
	{
		if (i ==1)
		{
			temp = tempQue.front();
			tempQue.pop();
			cout<<temp<<" ";
		}
		else
		{
			counter++;

			switch (counter)
			{
		case 1:
			cout<< (temp+1)<<" ";
			tempQue.push(temp+1);
			break;
		case 2:
			cout<<((2*temp)+1)<<" ";
			tempQue.push(2*temp + 1);
		case 3:
			cout<<(temp+2) <<" ";
			tempQue.push(temp+2);
			counter = 0;
			temp = tempQue.front();
			tempQue.pop();
			break;
			}
		}
	}

	return 0;
}
