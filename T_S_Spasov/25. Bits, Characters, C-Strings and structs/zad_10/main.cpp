// Fig. 4.11: main.cpp
// Using the bitwise shift operators.
#include <iostream>
#include <cstring>
#include <cstdlib>
#define LENGTH 25

using namespace std;

int main() {

	char array[ 5 ][ LENGTH ];


	for (int i = 0; i < 5; i++ )
	{
	cout << "Enter string: ";
	cin.getline( &array[ i ][ 0 ], LENGTH );
	}
	cout << endl;

	cout << "The strings with 'b' : ";
	for (int  i = 0; i < 5; i++ ){

		int lngt = strlen( &array[ i ][ 0 ] );

		if ( strcmp( &array[ i ][ lngt - 2 ], "ED" ) == 0 )
		cout << &array[ i ][ 0 ] << '\n';

	}
	return 0;

} // end main

