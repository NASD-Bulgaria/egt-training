//============================================================================
// Name        : Exeption-Integer.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
using std::cout;
using std::endl;

#include "Integer.h"

// Integer default constructor
Integer::Integer(int i) :
		value(i) {
	cout << "Constructor for Integer " << value << endl;
} // end Integer constructor

// Integer destructor
Integer::~Integer() {
	cout << "Destructor for Integer " << value << endl;
} // end Integer destructor
set Integer value;
void Integer::setInteger(int i) {
	value = i;
} // end function setInteger

// return Integer value
int Integer::getInteger() const {
	return value;
} // end function getInteger
