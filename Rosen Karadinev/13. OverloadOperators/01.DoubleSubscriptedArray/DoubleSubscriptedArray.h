#ifndef DOUBLESUBSCRIPTEDARRAY_H_
#define DOUBLESUBSCRIPTEDARRAY_H_

#include <iostream>
using std::ostream;
using std::istream;

class DoubleSubscriptedArray
{
	friend ostream &operator<<(ostream &, const DoubleSubscriptedArray &);
	friend istream &operator>>(istream &, DoubleSubscriptedArray &);

public:
	DoubleSubscriptedArray(int = 3, int = 3); // default constructor

	//copy constructor
	DoubleSubscriptedArray(const DoubleSubscriptedArray &);

	~DoubleSubscriptedArray(); // destructor

	int getRowSize() const; // return number of rows
	int getColumnSize() const; // return number of columns

	const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &); // assigment operator

	//quality operator
	bool operator==(const DoubleSubscriptedArray &) const;

	// inequality operator: returns opposite of == operator
	bool operator!=(const DoubleSubscriptedArray &right) const
	{
		return !(*this == right);
	}

	int &operator()(int, int);

	int operator()(int, int) const;

private:
	int rowSize; // number of rows
	int columnSize; // number of columns
	int *ptr; // pointer to first element of pointer-based array
};

#endif /* DOUBLESUBSCRIPTEDARRAY_H_ */
