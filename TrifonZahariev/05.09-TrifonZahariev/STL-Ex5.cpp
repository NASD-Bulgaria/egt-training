//============================================================================
// Name        : STL-Ex5.cpp
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

template<typename T>
void print(const list<T> &integersRef);

int main() {

	cout << "Enter integers: ";
	list<int> integers;

	istream_iterator<int> inputInt(cin);

	int number;
	number = *inputInt;
	while (number != 0) {
		integers.push_back(number);
		++inputInt;
		number = *inputInt;
	}
	cout << "Entered elements are: " << endl;

	integers.sort();

	print(integers);


	return 0;
}

template<typename T>
void print(const list<T> &integersRef) {
	if (integersRef.empty()) // list is empty
		cout << "List is empty";
	else {
		ostream_iterator<T> output(cout, " ");
		copy(integersRef.begin(), integersRef.end(), output);

	}

}
