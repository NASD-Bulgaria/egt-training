// Fig. 4.11: main.cpp
// Using the bitwise shift operators.
#include <iostream>

#include <iomanip>
#include <cctype>
using namespace std;

int main() {

	char testCh;
	cout << "Input char: ";
	cin >> testCh;

	cout << "isalpha: ";
	if (isalpha(testCh)) {
		cout << "True";
	} else {
		cout << "False";
	}
	cout << endl;

	cout << "isalnum: ";
	if (isalnum(testCh)) {
		cout << "True";
	} else {
		cout << "False";
	}
	cout << endl;

	cout << "isblank: ";
	if (isblank(testCh)) {
		cout << "True";
	} else {
		cout << "False";
	}
	cout << endl;


	cout << "iscntrl: ";
	if (iscntrl(testCh)) {
		cout << "True";
	} else {
		cout << "False";
	}
	cout << endl;


	cout << "isdigit: ";
	if (isdigit(testCh)) {
		cout << "True";
	} else {
		cout << "False";
	}
	cout << endl;


	cout << "isgraph: ";
	if (isgraph(testCh)) {
		cout << "True";
	} else {
		cout << "False";
	}
	cout << endl;



	return 0;
} // end main

