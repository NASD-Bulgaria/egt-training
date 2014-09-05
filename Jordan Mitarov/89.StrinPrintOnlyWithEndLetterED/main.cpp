#include <iostream>
#include "string.h"
using namespace std;

#define LENGTH 20

void findEndStringED();

int main()
{
	findEndStringED();

	return 0;
}

void findEndStringED()
{
	char str[5][LENGTH];

	int lengthStr;

	for(int i=0 ;i <5 ; i++)
	{
		cout<<"Enter a string: ";
		cin.getline(&str[i][0],LENGTH);
	}

	cout<<"\nThe string with end ED is: "<<endl;
	//check each string
	for (int i = 0; i < 5; i++ )
	{
		lengthStr = strlen( &str[ i ][ 0 ] );

		 // check if string ends with "ED"
		 if ( strcmp( &str[ i ][ lengthStr - 2 ], "ED" ) == 0 )
		 cout << &str[ i ][ 0 ] << '\n';
	} // end for*/

}
