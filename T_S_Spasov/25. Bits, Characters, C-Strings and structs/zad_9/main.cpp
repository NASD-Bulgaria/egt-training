// Fig. 4.11: main.cpp
// Using the bitwise shift operators.
#include <iostream>

#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>
#define LENGTH 25
using namespace std;

int main() {

	char array[ 5 ][ LENGTH ];
	int i;

	for ( i = 0; i < 5; i++ )
	{
	cout << "Enter string: ";
	cin.getline( &array[ i ][ 0 ], LENGTH );
	}
	cout << endl;

	cout << "The strings with 'b' : ";
	for ( i = 0; i < 5; i++ )
	if ( array[ i ][ 0 ] == 'b' )
	cout << &array[ i ][ 0 ] << endl;
	return 0;

	return 0;
} // end main

