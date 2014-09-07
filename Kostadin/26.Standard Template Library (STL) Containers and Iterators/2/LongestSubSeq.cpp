//============================================================================
// Name        : LongestSubSeq.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	list <int> lst;
	int num;
	do
	{
		cout << "Enter a number: ";
		cin>>num;
		if(num == 0)
		{
			break;
		}
		lst.push_back(num);
	}while(true);

	list <int>::iterator i;
	int count = 1;
	int maxCount = 1;
	int longestNum;
	i = lst.begin();
	while(i!= lst.end())
	{
		int first = *i;
		i++;
		int second = *i;
		if(first == second)
		{
			count++;
			if(count > maxCount)
			{
				maxCount = count;
				longestNum = first;
			}
		}
		else
		{
			count = 1;
		}
	}
	cout <<"The number is " << longestNum << " and the count of the number is " << maxCount << endl;


	return 0;
}
