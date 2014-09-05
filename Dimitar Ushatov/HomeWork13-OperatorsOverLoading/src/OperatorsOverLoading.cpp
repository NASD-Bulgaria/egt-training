// Fig. 11.8: main.cpp
// Array class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Array.h"
#include "BigInteger.h"

void testArrayClass();

int main() {
//	testArrayClass();
	BigInteger a("99");
	BigInteger b("1");
	BigInteger c = a + b;
	short * ptr = c.getPointer();
	for (int var = 0; var < c.getSize(); ++var) {
		cout<<ptr[var];
	}
	cout<<endl;
	return 0;
} // end main

void testArrayClass() {
	Array integers1(3, 3); // seven-element Array
	Array integers2; // 10-element Array by default

	// print integers1 size and contents
	cout << "Number Of Rows in Array integers1 is " << integers1.getRows()
			<< "\nNumber Of Cols in Array integers1 is " << integers1.getCols()
			<< "\nArray after initialization:\n" << integers1;

	// print integers2 size and contents
	cout << "Number Of Rows in Array integers2 is " << integers2.getRows()
			<< "\nNumber Of Cols in Array integers2 is " << integers2.getCols()
			<< "\nArray after initialization:\n" << integers2;

	// input and print integers1 and integers2
	cout << "\nEnter 13 integers:" << endl;
	cin >> integers1 >> integers2;

	cout << "\nAfter input, the Arrays contain:\n" << "integers1:\n"
			<< integers1 << "integers2:\n" << integers2;

	// use overloaded inequality (!=) operator
	cout << "\nEvaluating: integers1 != integers2" << endl;

	if (integers1 != integers2)
		cout << "integers1 and integers2 are not equal" << endl;

	// create Array integers3 using integers1 as an
	// initializer; print size and contents
	Array integers3(integers1); // invokes copy constructor

	cout << "Number Of Rows in Array integers3 is " << integers3.getRows()
			<< "\nNumber Of Cols in Array integers3 is " << integers3.getCols()
			<< "\nArray after initialization:\n" << integers3;

	// use overloaded assignment (=) operator
	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2; // note target Array is smaller

	cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;

	// use overloaded equality (==) operator
	cout << "\nEvaluating: integers1 == integers2" << endl;

	if (integers1 == integers2)
		cout << "integers1 and integers2 are equal" << endl;

	// use overloaded subscript operator to create rvalue
	cout << "\nintegers1(1, 1) is " << integers1(1, 1);

	// use overloaded subscript operator to create lvalue
	cout << "\n\nAssigning 1000 to integers1(1, 1)" << endl;
	integers1(1, 1) = 1000;
	cout << "integers1:\n" << integers1;

	// attempt to use out-of-range subscript
	//   cout << "\nAttempt to assign 1000 to integers1(10, 10)" << endl;
	//   integers1(10, 10) = 1000; // ERROR: out of range

	cout << "\nThe 1st largest element in integers1 (integers(1)) is:" << endl
			<< integers1(1) << endl;

	cout << "\nThe 2nd largest element in integers1 (integers(2)) is:" << endl
			<< integers1(2) << endl;

	cout << "\nThe 3th largest element in integers1 (integers(3)) is:" << endl
			<< integers1(3) << endl;
}

