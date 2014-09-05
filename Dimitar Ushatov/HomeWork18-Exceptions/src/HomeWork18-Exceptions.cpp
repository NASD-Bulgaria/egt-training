//============================================================================
// Name        : HomeWork18-Exceptions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include "ComposedTestClass.h"
using namespace std;
void solveTaskOne() {
	int code = 0;
	try {
		if (code == 0) {
			throw 0;
		} else {
			throw 0;
		}
	} catch (int e) {
		cout << "The trowed value was int!" << endl;
	} catch (double e) {
		cout << "The trowed value was double!" << endl;
	}
}

void solveTaskThree() {
	try {
		try {
			ComposedTestClass a;

			throw exception();

		} catch (exception &e) {
			cout << "Exception retrowing" << endl;
			throw e;
		}
	} catch (exception e) {
		cout << e.what() << endl;
	}
}

int main() {
//	solveTaskThree();
	cout << oct << 8 << endl;
	return 0;
}
