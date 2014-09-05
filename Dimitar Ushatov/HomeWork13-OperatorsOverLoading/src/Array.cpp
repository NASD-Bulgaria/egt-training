// Fig 11.7: Array.cpp
// Member-function definitions for class Array
#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib> // exit function prototypeusing std::exit;
#include "Array.h" // Array class definition// default constructor for class Array (default size 10)
Array::Array(int rowsCount, int colsCount) {
	this->rowsCount = (rowsCount > 0 ? rowsCount : 2); // validate arraySize
	this->colsCount = (colsCount > 0 ? colsCount : 2);
	ptr = new int*[this->rowsCount]; // create space for pointer-based array
	for (int i = 0; i < this->rowsCount; i++) {
		ptr[i] = new int[this->colsCount]; // set pointer-based array element
		for (int g = 0; g < colsCount; ++g) {
			ptr[i][g] = 0;
		}
	}
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
Array::Array(const Array &arrayToCopy) :
		rowsCount(arrayToCopy.rowsCount), colsCount(arrayToCopy.colsCount) {
	ptr = new int*[rowsCount]; // create space for pointer-based array

	for (int i = 0; i < this->rowsCount; i++) {
		ptr[i] = new int[this->colsCount]; // set pointer-based array element
		for (int g = 0; g < colsCount; ++g) {
			ptr[i][g] = arrayToCopy.ptr[i][g];
		}
	}
} // end Array copy constructor

// destructor for class Array
Array::~Array() {
	for (int i = 0; i < this->rowsCount; i++) {
		delete[] ptr[i];
	}
	delete[] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
int Array::getRows() const {
	return this->rowsCount; // number of elements in Array
} // end function getSize

int Array::getCols() const {
	return this->colsCount; // number of elements in Array
}
// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const Array &Array::operator=(const Array &right) {
	if (&right != this) {
		if (rowsCount != right.rowsCount || colsCount != right.colsCount) {
			for (int i = 0; i < this->rowsCount; i++) {
				delete[] ptr[i];
			}
			delete[] ptr;
			rowsCount = right.rowsCount;
			colsCount = right.colsCount;
			ptr = new int*[rowsCount];
			for (int i = 0; i < this->rowsCount; i++) {
				ptr[i] = new int[this->colsCount];
			}
		}

		for (int i = 0; i < this->rowsCount; i++) {
			ptr[i] = new int[this->colsCount];
			for (int g = 0; g < colsCount; ++g) {
				ptr[i][g] = right.ptr[i][g];
			}
		}
	}

	return *this;
}


bool Array::operator==(const Array &right) const {
	if (rowsCount != right.rowsCount || colsCount != right.colsCount)
		return false;

	for (int i = 0; i < rowsCount; i++){
		for (int g = 0; g < colsCount; ++g) {
			if (ptr[i][g] != right.ptr[i][g]) {
				return false;
			}
		}
	}
	return true;
}

int &Array::operator()(int subscriptRow, int subscriptCol) {
	if (subscriptRow < 0 || subscriptRow >= rowsCount) {
		cerr << "\nError: SubscriptRow " << subscriptRow << " out of range" << endl;
		exit(1);
	}

	if (subscriptCol < 0 || subscriptRow >= colsCount) {
		cerr << "\nError: SubscriptCol " << subscriptCol << " out of range" << endl;
		exit(1);
	}

	return ptr[subscriptRow][subscriptCol];
}

int Array::operator()(int subscriptRow, int subscriptCol) const {
	if (subscriptRow < 0 || subscriptRow >= rowsCount) {
		cerr << "\nError: SubscriptRow " << subscriptRow << " out of range" << endl;
		exit(1);
	}

	if (subscriptCol < 0 || subscriptRow >= colsCount) {
		cerr << "\nError: SubscriptCol " << subscriptCol << " out of range" << endl;
		exit(1);
	}

	return ptr[subscriptRow][subscriptCol];
}

istream &operator>>(istream &input, Array &a) {
	for (int i = 0; i < a.rowsCount; i++){
		for (int g = 0; g < a.colsCount; ++g) {
			input >> a.ptr[i][g];
		}
	}
	return input;
}


ostream &operator<<(ostream &output, const Array &a) {

	for (int i = 0; i < a.rowsCount; i++){
		for (int g = 0; g < a.colsCount; ++g) {
			output << setw(5) << a.ptr[i][g];
		}

		output << endl;
	}

	return output;
}

bool Array::sortPredicate(int first, int second){
	return first > second;
}

int Array::operator ()(int maxElement) const {
	vector<int> helper;
	for (int i = 0; i < this->rowsCount; ++i) {
		for (int g = 0; g < this->colsCount; ++g) {
			if (find(helper.begin(), helper.end(), ptr[i][g]) == helper.end()) {
				helper.push_back(ptr[i][g]);
			}
		}
	}
	if (maxElement > (int)helper.size() || maxElement <= 0) {
		cerr << "MaxElement must be larger then 0 and less then the count of unique elements in Array";
		exit(1);
	}
	sort(helper.begin(), helper.end(), sortPredicate);
	return helper[maxElement - 1];
}
