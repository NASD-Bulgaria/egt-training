// Fig. 11.6: Array.h
// Array class for storing arrays of integers.
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <algorithm>
#include <vector>
using std::ostream;
using std::istream;
using std::sort;
using std::find;
using std::vector;

class Array {
	friend ostream &operator<<(ostream &, const Array &);
	friend istream &operator>>(istream &, Array &);
public:
	Array(int = 2, int = 2); // default constructor
	Array(const Array &); // copy constructor
	~Array(); // destructor
	int getRows() const; // return size
	int getCols() const;
	const Array &operator=(const Array &); // assignment operator
	bool operator==(const Array &) const; // equality operator

	// inequality operator; returns opposite of == operator
	bool operator!=(const Array &right) const {
		return !(*this == right); // invokes Array::operator==
	} // end function operator!=

	// subscript operator for non-const objects returns modifiable lvalue
	int &operator()(int, int);

	// subscript operator for const objects returns rvalue
	int operator()(int, int) const;
	int operator()(int) const;
private:
	int rowsCount;
	int colsCount; // pointer-based array size
	int **ptr; // pointer to first element of pointer-based array
	static bool sortPredicate(int, int);
};
// end class Array

#endif

