/*
 * ComposedTestClass.h
 *
 *  Created on: Aug 26, 2014
 *      Author: NandM
 */

#ifndef COMPOSEDTESTCLASS_H_
#define COMPOSEDTESTCLASS_H_

#include "TestClass.h"
#include <stdexcept>

using namespace std;

class ComposedTestClass {
public:
	ComposedTestClass();
	~ComposedTestClass();
private:
	TestClass a;
};

#endif /* COMPOSEDTESTCLASS_H_ */
