//============================================================================
// Name        : ex_STL1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;


template <typename T>
void sum( vector <T> );

int main()
{
	vector <int> sequence;
	bool check = true;
	int temp;
		while(check)
		{
			cout<<"Enter integer: "<<endl;
			cin>>temp;
			if (temp == 0)
			{
				check = false;
			}
			else
			{
				sequence.push_back(temp);
			}
		}
		sum(sequence);

	return 0;
}


template <typename T>
void sum(vector <T> numbers)
{
	int sum = 0;
	int counter = 0;
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		sum+= numbers[i];
		counter++;
	}
	cout<<"The sum is: "<<sum<<endl;
	cout<<"The avarage is: "<<sum/counter<<endl;
}
