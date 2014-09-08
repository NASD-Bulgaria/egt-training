//============================================================================
// Name        : STL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <istream>
#include <iterator>
#include <vector>

using namespace std;

void majorant(istream_iterator<int> &);

int main()
{
	cout <<"Please enter a sequence(end with 0): ";
	istream_iterator<int> inputInt(cin);

	majorant(inputInt);

	return 0;
}

void majorant(istream_iterator<int> &input)
{
	vector<int> seq;

	while(*input != 0)
	{
		seq.push_back(*input);
		++input;
	}

	int temp;
	int majorant;

	for (unsigned int i = 1; i < (seq.size() / 2); i++)
	{
		temp = seq[i - 1];
		if (seq[i] > temp)
		{
			majorant = seq[i];
		}
	}

	cout <<"The majorant is: "<< majorant <<endl;
}

