//============================================================================
// Name        : core1-STL-1va-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<iterator>
using namespace std;

int main() {
	int integer;
	int sum=0;
	double avrg=0.0;
	double count=0;
	vector<int> integers;

	cout<<"Enter integers ";
	while(integer!=0)
	{

		cin>>integer;

		integers.push_back(integer);
		count++;

	}
	vector<int>::const_iterator p;
	for(p=integers.begin();p!=integers.end();p++)
	{

		sum+=*p;

	}
	avrg=sum/(count-1);
	cout<<"The sum is "<<sum<<endl;
	cout<<"The average is "<<avrg<<endl;

	return 0;
}
