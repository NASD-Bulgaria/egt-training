#include <iostream>
 #include <string>
 using namespace std;

int main()
{
 string s;

 cout << "Enter a string: ";
 getline( cin, s, '\n' );


 string::reverse_iterator r = s.rbegin();


 while ( r != s.rend() )
 {

 *r = ( isupper( *r ) ? tolower( *r ): toupper( *r ) );
 cout << *( r++ );
 }

 cout << endl;
 }
