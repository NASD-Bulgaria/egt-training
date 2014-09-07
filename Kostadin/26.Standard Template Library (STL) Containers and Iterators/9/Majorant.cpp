//============================================================================
// Name        : Majorant.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, int> mp;
	map<int, int>::iterator it;

	int arr[] = {2, 2, 3, 3, 2, 3, 4, 3, 3};
	for(int i = 0; i < 9; i++)
	{
		it = mp.find(arr[i]);
		if(it == mp.end())
		{
			mp.insert(pair<int, int>(arr[i], 1));
		}
		else
		{
			int count = it->second;
			count++;
			it->second = count;
		}
	}
	int maxCount = mp.begin()->second;
	int num;
	for(it = mp.begin(); it != mp.end(); it++)
	{
		if(it->second > maxCount)
		{
			maxCount = it->second;
			num = it->first;
		}
	}
	cout << num << endl;
	return 0;
}
