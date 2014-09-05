#include <iostream>
#include <string>
#include "Array.h"
using namespace std;

int main()
{

	Array<int, 5> intArray; //create intArray object

	// initialize intArray with user input values
	cout << "Enter " << intArray.getSize() << " integer values:\n";
	intArray.inputArray();

	//output intArray
	cout << "\nThe values in intArray are:\n";
	intArray.outputArray();

	Array<string, 7> stringArray; // create stringArray

	// initialize stringArray with user input values
	cout << "\nEnter " << stringArray.getSize()
    	<< " one-word string values:\n";
	stringArray.inputArray();

	// output stringArray
	cout << "\nThe values in the stringArray are:\n";
	stringArray.outputArray();

	return 0;
}
