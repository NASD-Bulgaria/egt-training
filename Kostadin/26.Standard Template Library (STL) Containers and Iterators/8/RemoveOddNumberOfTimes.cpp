//============================================================================
// Name        : RemoveOddNumberOfTimes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
int main() {
	vector <int> nums;
	vector <int> res;
	int num;
	int count;
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
		count = 0;
		for(int j = 0; j < nums.size(); j++)
		{
			if(nums[j] == nums[i])
			{
				count++;
			}
		}
		if(count % 2 == 0)
		{
			res.push_back(nums[i]);
		}
	}

	for(int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;

	for(int i = 0 ; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}
