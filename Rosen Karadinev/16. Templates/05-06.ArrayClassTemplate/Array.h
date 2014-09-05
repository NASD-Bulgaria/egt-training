#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <assert.h>
using namespace std;

template<typename elementType, int numberOfElements>
class Array
{
public:
	Array(); // default constructor
	~Array(); // destructor

	int getSize() const; // return size

	bool operator==(const Array &) const;  //compare equal
	bool operator!=(const Array &) const; // compare !equal

	elementType &operator[](int); //subscript operator
	static int getArrayCount(); // return count of arrays instantiated

	void inputArray(); // input the array elements
	void outputArray() const; // output the array elements

private:
	elementType elements[numberOfElements]; // array of elements
	static int arrayCount; // # of Arrays instantiated
};


template <typename elementType, int numberOfElements >
int Array<elementType, numberOfElements> :: arrayCount = 0; // no objects

//default constructor for class Array
template<typename elementType, int numberOfElements>
Array<elementType, numberOfElements>::Array()
{
	arrayCount++; // count one more object

	for(int i = 0; i < numberOfElements; i++)
	{
		elements[i] = elementType();
	}
}

//destructor for class Array
template<typename elementType, int numberOfElements>
Array<elementType, numberOfElements> ::~Array()
{
	arrayCount--;
}

template<typename elementType, int numberOfElements>
int Array<elementType, numberOfElements>::getSize() const
{
	return numberOfElements;
}

template<class elementType, int numberOfElements>
bool Array<elementType, numberOfElements>::
	operator==(const Array &right) const
{
	for(int i = 0; i < numberOfElements; i++)
	{
		if(elements[i] != right.elements[i])
		{
			return false;
		}
	}

	return true; // arrays are equal
}

//overload subscript operator
template <typename elementType, int numberOfElements>
elementType &Array<elementType, numberOfElements> ::
	operator[](int subscript)
{
	//check for subscript
	assert( 0 <= subscript && subscript < numberOfElements );
	return elements[subscript]; // reference return creates lvalue
}

// return the number of Array objects instantiated
template <typename elementType, int numberOfElements>
int Array<elementType, numberOfElements>::getArrayCount()
{
	return arrayCount;
}

//input values for entire array
template <typename elementType, int numberOfElements>
void Array<elementType, numberOfElements>::inputArray()
{
	//get values of array from user
	for(int i = 0; i < numberOfElements; i++)
	{
		cin >> elements[i];
	}
}

//Output the Array values
template <typename elementType, int numberOfElements>
void Array<elementType, numberOfElements>::outputArray() const
{
	int i;

	for(i = 0; i < numberOfElements; i++)
	{
		cout << elements[i] << ' ';

		if((i + 1) % 10 == 0)
		{
			cout << '\n';
		}
	}

	if(i % 10 != 0)
	{
		cout << '\n';
	}
}

#endif
