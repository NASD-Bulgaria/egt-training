/*
 * ComposedTestClass.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: NandM
 */

#include "ComposedTestClass.h"

ComposedTestClass::ComposedTestClass() {
	cout << "Trowing exception in ComposedTestClass"<<endl;
	throw exception();
}

ComposedTestClass::~ComposedTestClass() {
	cout << "Destructor called on ComposedTestClass"<<endl;
}

