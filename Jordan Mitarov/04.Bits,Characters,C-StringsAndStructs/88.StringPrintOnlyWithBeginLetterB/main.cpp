#include <iostream>
#include "string.h"
using namespace std;

#define LENGTH 20

void findBeginStringb();

int main()
{
	findBeginStringb();

	return 0;
}



void findBeginStringb()
{
	 char str[5][LENGTH];

	for(int i=0 ;i <5 ; i++)
	{
		cout<<"Enter a string: ";
		cin.getline(&str[i][0],LENGTH);
	}

	cout<<"\nThe string with begin b is: "<<endl;
	// check each string
	for (int i = 0; i < 5; i++ )
	{
		 // check if string begins with "b"
		 if (str[ i ][ 0 ] == 'b')

		 cout << &str[ i ][ 0 ]<< '\n';
	} // end for
}
