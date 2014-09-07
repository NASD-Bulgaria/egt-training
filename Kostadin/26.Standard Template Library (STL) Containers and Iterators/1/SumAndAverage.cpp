//============================================================================
// Name        : SumAndAverage.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main() {
	cout << "Enter an integer: ";
	list <int> numbers;
	std::istream_iterator< int > inputInt( cin );
	list<int>::iterator i;
	int number = 0;
	do{
		number = *inputInt;
		numbers.push_back(number);
		inputInt++;
	}while(*inputInt != 0);

	int sum = 0;
	for(i = numbers.begin(); i != numbers.end(); i++)
	{
		sum = sum + *i;
	}

	cout << "The sum is: "<< sum<< endl;
	cout << "The average is " << sum / (numbers.size() - 1) << endl;
	return 0;
}
