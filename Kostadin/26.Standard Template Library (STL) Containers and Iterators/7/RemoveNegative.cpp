//============================================================================
// Name        : RemoveNegative.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;
	vector <int> nums;
	vector <int> res;
	do
	{
		cout<<"Enter a number: ";
		cin>>num;
		if(num == 0)
		{
			break;
		}
		nums.push_back(num);
	}while(true);
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] > 0)
		{
			res.push_back(nums[i]);
		}
	}
	for(int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}
