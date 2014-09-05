// Fig. 3.14: main.cpp
// Template Stack class test program.
#include <iostream>
#include <string>
using namespace std;

#include "Stack.h" // Stack class definition

int main()
{
	Stack< char > stack; // create Stack of ints
	string str;
	char temp;

	cout << "Enter string at char Stack" << endl;
	getline(cin, str);

	for (size_t i = 0; i < str.length(); ++i) {
		temp = str[i];
		stack.push(temp);
	}

	//Ex.5
	stack.printStack();

	//EX.6
	cout << "String is palindrom -> " << boolalpha << stack.palindrome() << endl;

	stack.printStack();

	return 0;
} // end main

