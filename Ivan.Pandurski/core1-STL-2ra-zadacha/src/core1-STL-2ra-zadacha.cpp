//============================================================================
// Name        : core1-STL-2ra-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<set>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
int longestSequence(vector<int> vec);

int main() {

	const int SIZE=10;
	int a[ SIZE ] = { 7, 22, 9, 22, 22, 22, 100, 22, 85, 13 };
	vector<int> integers;
	for(int i=0;i<10;i++)
		integers.push_back(a[i]);
	cout<<"The longest sequence is "<<longestSequence(integers);

	return 0;
}

int longestSequence(vector<int> vec)
{
	vector<int>::iterator p;
	int currentNumber = vec[0], currentMax = 1, longestMax = 1;
	for(p=vec.begin();p!=vec.end();p++)

	    {

	        if(*p == currentNumber)

	            currentMax++;


	        else

	        {

	            currentNumber = *p;

	            if(currentMax > longestMax)

	                longestMax = currentMax;


	           currentMax = 1;
		        }

	    }

	    return longestMax;

}
