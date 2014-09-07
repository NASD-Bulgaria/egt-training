//Write a program that reads N integers from the
//console and reverses them using a stack

#include <iostream>
#include <stack> // list class-template definition
#include <algorithm> // copy algorithm
#include <iterator> // ostream_iterator
using namespace std;
#define SIZE 5
// prototype for function template printList
//template < typename T > void printList( const std::list< T > &listRef );

int main()
{

   stack< int > values;
   int number;
   for(int i = 0; i < SIZE; i++){
	   cout << "Enter number " << i +1 <<": ";
	   cin >> number;
	   values.push(number);
   }
   for(int i = 0; i < SIZE; i++){

  	   cout << values.top();
  	   values.pop();
     }

   return 0;
} // end main


//template < typename T > void printList( const std::list< T > &listRef )
//{
//   if ( listRef.empty() ) // list is empty
//      cout << "List is empty";
//   else
//   {
//      std::ostream_iterator< T > output( cout, " " );
//      std::copy( listRef.begin(), listRef.end(), output );
//   } // end else
//} // end function printList
