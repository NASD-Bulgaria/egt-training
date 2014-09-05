/*
 * TestClass.h
 *
 *  Created on: 2.09.2014 ã.
 *      Author: Admin
 */

#ifndef TESTCLASS_H_
#define TESTCLASS_H_

using namespace std;

class TestClass {
public:
	TestClass();
	virtual ~TestClass();
	int getValue() const;
	void setValue(int value);

private:
	int value;
};

#endif /* TESTCLASS_H_ */
