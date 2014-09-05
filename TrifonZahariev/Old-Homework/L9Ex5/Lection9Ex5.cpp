//============================================================================
// Name        : Lection9Ex5.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

int main() {

	const int SIZE = 5;
	unsigned int value[SIZE] = {2,4,6,8,10};

	unsigned int *vPtr;

	vPtr = value;
	vPtr = &value[0];

	cout << "Array value printed with:\n\nArray subscript notation\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "value[" << i << "] = " << value[ i ] << '\n';
	}

	cout << "\nPointer/offset notation\n";
	for ( int offset1 = 0; offset1 < SIZE; offset1++ )
		 cout << "*(vPtr + " << offset1 << ") = "
		 << *( vPtr + offset1 ) << '\n';

	cout << "\nPointer/offset notation with the array name as the pointer.\n";

	for (int offset2 = 0; offset2 < SIZE; offset2++)
	{
		cout << "*(value + " << offset2 << ") = "
				 << *( value + offset2 ) << '\n';
	}

	cout << "\nPointer subscript notation\n";
	for (int j = 0; j < SIZE; j++)
	{
		cout << "vPtr[" << j << "] = " << vPtr[ j ] << '\n';
	}

	cout << "\nArray subscript notation:\n";
	cout << "value[4] = " << value[4];

	cout << "\n\nPointer/offset notation with the array name as the pointer:\n";
	cout << "*(value + 4) = " << *(value + 4);

	cout << "\n\nPointer subscript notation:\n";
	cout << "vPtr[4] = " << vPtr[4];

	cout << "\n\nPointer/offset notation:\n";
	cout << "*(vPtr + 4) = " << *(vPtr + 4);


	return 0;
}
