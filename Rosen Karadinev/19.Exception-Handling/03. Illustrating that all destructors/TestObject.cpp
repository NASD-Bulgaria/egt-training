#include "TestObject.h"
#include <iostream>
using namespace std;

// constructor takes int parameter
TestObject::TestObject(int val) : value(val)
{
	cout << "TestObject " << value << " constructor\n";
}

//destructor
TestObject::~TestObject()
{
	cout << "TestObject " << value << " destructor\n";
}

