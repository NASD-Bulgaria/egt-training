//23. Write a program that removes from a given sequence all
//numbers which are power of 2.

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

int main() 
{

	vector<int> result;
	list<int> listIntegers;
	listIntegers.push_back(1);
	listIntegers.push_back(2);
	listIntegers.push_back(3);
	listIntegers.push_back(15);
	listIntegers.push_back(8);
	listIntegers.push_back(1024);
	listIntegers.push_back(256);
	listIntegers.push_back(111);
	listIntegers.push_back(112);

	int temp;
	int rest;
	list<int>::iterator iter;
	for(iter = listIntegers.begin(); iter != listIntegers.end(); iter++)
	{
		temp = *iter;
		while(temp > 2)
		{
			rest = temp%2;
			temp /= 2;
			if(rest != 0)
			{
				result.push_back(*iter);
				break;
			}
		}
	}
	for(unsigned i = 0; i < result.size();i++)
	{
		cout<<result[i]<<" ";
	}

	return 0;
}
