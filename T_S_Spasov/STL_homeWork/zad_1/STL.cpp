// Fig. 5.17: main.cpp
// Standard library list class template test program.
#include <iostream>
#include <list> // list class-template definition
#include <algorithm> // copy algorithm
#include <iterator> // ostream_iterator
using namespace std;
// prototype for function template printList
template < typename T > void printList( const std::list< T > &listRef );

int main()
{

   list< int > values;

   int input;
   do{
	   cout << "? ";
	   cin >> input;
	   values.push_back(input);
   }
   while(input);
long int sum = 0;
   for (list<int>::iterator it = values.begin(); it != values.end(); ++it)
      sum += *it;

cout << "The sum is: " << sum << endl;
cout << "Average is: " << sum/values.size();
   return 0;
} // end main

// printList function template definition; uses
// ostream_iterator and copy algorithm to output list elements
template < typename T > void printList( const std::list< T > &listRef )
{
   if ( listRef.empty() ) // list is empty
      cout << "List is empty";
   else
   {
      std::ostream_iterator< T > output( cout, " " );
      std::copy( listRef.begin(), listRef.end(), output );
   } // end else
} // end function printList
