//============================================================================
// Name        : STL-Ex1.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <numeric>
#include<list>
#include <exception>
using namespace std;

#include <iterator>

int main() {

	cout << "Enter integers: ";
	list<int> Integers;

	istream_iterator<int> inputInt(cin);

	int number;
	number = *inputInt;
	while (number != 0) {
		Integers.push_back(number);
		++inputInt;
		number = *inputInt;
	}

	int sum = accumulate(Integers.begin(), Integers.end(), number);
	cout << "The sum is: "<<sum << endl;
	int average = sum / Integers.size();
	cout << "The average is: "<< average<<endl;
	ostream_iterator<int> outputInt(cout, " ");
	copy(Integers.begin(), Integers.end(), outputInt);

	return 0;
}
