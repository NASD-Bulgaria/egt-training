//============================================================================
// Name        : Ex1_Lecture26_B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int value;
	do{
		cout<<"Enter positive integer number or \"0\" for exit : ";
		cin>>value;
		if(value>0) v.push_back(value);
	}while(value != 0);

	int count = 1;
	int maxCount = 1;
	int index = 0;
	for(int i=0; i<v.size()-1; i++)
	{
		if(v[i]>v[i+1])
		{
			if(maxCount<count)
			{
				maxCount=count;
				index=i-count+1;
			}
			count = 1;
		}
		else count++;
	}

	if(maxCount<count)
	{
		maxCount=count;
		index=v.size()-count+1;
	}

	for(int i=index; i<index+maxCount; i++)
	{
		cout<<v[i]<<"\t";
	}

	return 0;
}
