//============================================================================
// Name        : STL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
struct num
{
	int sum;
	int count;
};
using namespace std;
int averageN(num);
template <typename T>
num sumOf(vector<T>);
int main()
{
	vector <int> data;
	bool check = true;
	int temp;
	while(check)
	{
		cout<<"Please enter number"<<endl;
		cin>>temp;
		if(temp == 0 )
		{
			check = false;
		}
		else
		{
			data.push_back(temp);
		}

	}
	int sum;
	sum = sumOf(data).sum;
	cout <<"Sum of elements is : "<< sum<<endl;
	cout<<"Average is : "<< averageN(sumOf(data))<<endl;

	return 0;
}
template <typename T>
num sumOf(vector<T> numbers)
{
	num sum;
	sum.count=0;
	sum.sum=0;
	for(size_t i = 0 ;i < numbers.size();i++)
	{
		sum.sum+=numbers[i];
		sum.count+=i;
	}
	return sum;

}
int averageN(num number)
{
	int result=0;
	result = number.sum/number.count;
	return result;
}
