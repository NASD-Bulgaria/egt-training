//============================================================================
// Name        : core1-STL-4ta-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<queue>

using namespace std;

int main() {
	queue < int > values;
		int number;

		cout << "Enter number: ";
		cin >> number;
		values.push(number);

		for(int i = 0; i < 100; ++i)
		{
			values.push( values.front() + 1 );
			values.push( 2*values.front() + 1 );
			values.push( values.front() + 2 );
			cout << values.front()<<' ';
			values.pop();
		}
	return 0;
}
