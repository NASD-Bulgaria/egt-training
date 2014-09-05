//============================================================================
// Name        : Exxception-Ex5.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "TestClass.h"

int main() {

	TestClass test1();

	try {

	} catch (exception e) {
		cout << e.what();
	}

	return 0;
}
