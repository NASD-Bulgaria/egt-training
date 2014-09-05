#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::exit;

#include "DoubleSubscriptedArray.h"

// default constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(
	int rowSizeEntered, int columnSizeEntered)
{
	//validate row nad column size
	rowSize = (rowSizeEntered > 0 ? rowSizeEntered : 3);
	columnSize = (columnSizeEntered > 0 ? columnSizeEntered : 3);

	ptr = new int[rowSize * columnSize]; //create space for array

	for(int loop = 0; loop < rowSize * columnSize; loop++)
	{
		ptr[loop] = 0; // set pointer-based array element
	}
}

// copy constructor for class DoubleSubscriptedArray:
// must recieve a reference to prevent infinite recursion
DoubleSubscriptedArray::DoubleSubscriptedArray(
	const DoubleSubscriptedArray &arrayToCopy)
	: rowSize(arrayToCopy.rowSize), columnSize(arrayToCopy.columnSize)
{
	ptr = new int[rowSize * columnSize]; // create space for array

	for(int loop = 0; loop < rowSize * columnSize; loop++)
	{
		ptr[loop] = arrayToCopy.ptr[loop]; // copy into object
	}
}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
	delete [] ptr;
}

int DoubleSubscriptedArray::getRowSize() const
{
	return rowSize;
}

int DoubleSubscriptedArray::getColumnSize() const
{
	return columnSize;
}

//overload assignment operator;
//const return avoids: (a1 = a2) = a3
const DoubleSubscriptedArray &DoubleSubscriptedArray::operator=(
	const DoubleSubscriptedArray &right)
{
	if(&right != this) // avoid self-assignment
	{
		//for arrays of different sizes, deallocate original
		//left-side array, then allocate new left-side array
		if(rowSize * columnSize != right.rowSize * right.columnSize)
		{
			delete [] ptr; //release space
			rowSize = right.rowSize; // resize this object
			columnSize = right.columnSize;
			ptr = new int[rowSize * columnSize]; // create space for copy
		}

		for(int loop = 0; loop < rowSize * columnSize; loop++)
		{
			ptr[loop] = right.ptr[loop]; // copy into object
		}
	}

	return *this;
}

// determine if two DoubleSubscriptedArrays are equal and
// return true, otherwise return false
bool DoubleSubscriptedArray::operator==(
	const DoubleSubscriptedArray &right) const
{
	if (rowSize * columnSize != right.rowSize * right.columnSize)
	{
		return false; // arrays of different number of elemnts
	}

	for(int loop = 0; loop < rowSize * columnSize; loop++)
	{
		if(ptr[loop] != right.ptr[loop])
		{
			return false; // DoubleSubscriptedArray contents are not equal
		}
	}

	return true; // DoubleSubscriptedArrays are equal
}

// overloaded subscript operator for non-const DoubleSubscriptedArrays;
// reference return creates a modifiable lvalue
int &DoubleSubscriptedArray::operator()(
	int rowSubscript, int columnSubscript)
{
	//check for subscript out-of-range error
	if((rowSubscript < 0 || rowSubscript >= rowSize) ||
	  (columnSubscript <0 || columnSubscript >= columnSize))
	{
		cerr << "\nError: One or both subscripts out of range" << endl;
		exit(1); //terminate program
	}

	//reference return
	return ptr[(rowSubscript * columnSize) + columnSubscript];
}

// overloaded subscript operator for const DoubleSubscriptedArrays
// const reference return creates an rvalue
int DoubleSubscriptedArray::operator()(
	int rowSubscript, int columnSubscript) const
{
	//check subscript out-of-range error
	if((rowSubscript < 0 || rowSubscript >= rowSize) ||
	  ( columnSubscript < 0 || columnSubscript >= columnSize))
	{
		cerr << "\nError: One or both subscripts out of range" << endl;
		exit(1);
	}

	//return copy of this element
	return ptr[(rowSubscript * columnSize) + columnSubscript];
}

// overloaded input operator for class DoubleSubscriptedArray;
// inputs values for entire DoubleSubscriptedArray
istream &operator >> (istream &input, DoubleSubscriptedArray &a)
{
	for(int loop = 0; loop < a.rowSize * a.columnSize; loop++)
	{
		input >> a.ptr[loop];
	}

	return input; // enables cin >> x >> y;
}

//overloaded output operator for class DoubleSubscriptedArray
ostream &operator<<(ostream &output, const DoubleSubscriptedArray &a)
{
	for( int loop = 0; loop < a.rowSize; loop++)
	{
		for(int loop2 = 0; loop2 < a.columnSize; loop2++)
		{
			output << a.ptr[(loop * a.columnSize) + loop2] << ' ';
		}

		output << endl;
	}

	return output; // enable cout << x << y;
}


