// Exercise 15.11 Solution: Ex15_11.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
   string input; // string to hold input string
   int stringLength; // variable used to hold length of string

   // ask user for string and store in character array
   cout << "Enter a string: ";
   cin >> input;

   stringLength = input.length(); // get length of string

   // display length of string
   cout << "the length of the string is " << stringLength << endl;

   // print string using twice the length as field with
   cout << setw( 2 * stringLength ) << input << endl;
} // end main

