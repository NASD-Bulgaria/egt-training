//============================================================================
// Name        : TestList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Fig. 3.5: main.cpp
// List class test program.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "List.h"

// display program instructions to user
void instructions()
{
   cout << "Enter one of the following:\n"
      << "  1 to insert at beginning of list\n"
      << "  2 to insert at end of list\n"
      << "  3 to delete from beginning of list\n"
      << "  4 to delete from end of list\n"
      << "  5 to end list processing\n";
} // end function instructions

// function to test a List
template< typename T >
void testList( List< T > &listObject, const string &typeName )
{
   cout << "Testing a List of " << typeName << " values\n";
   instructions(); // display instructions

   int choice; // store user choice
   T value; // store input value

   do // perform user-selected actions
   {
      cout << "? ";
      cin >> choice;

      switch ( choice )
      {
         case 1: // insert at beginning
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtFront( value );
            listObject.print();
            break;
         case 2: // insert at end
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtBack( value );
            listObject.print();
            break;
         case 3: // remove from beginning
            if ( listObject.removeFromFront( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 4: // remove from end
            if ( listObject.removeFromBack( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
      } // end switch
   } while ( choice != 5 ); // end do...while

   cout << "End list test\n\n";
} // end function testList




int main()
{
   // test List of int values
   List< int > integerList1;
   testList( integerList1, "integer1" );

   // test List of double values
   List< int > integerList2;
   testList( integerList2, "integer2" );

   //   remove from back
   integerList1.getFromBack();
   cout << "List1 after get from back: " << endl;
   integerList1.print();

   //   remove from back
   integerList2.getFromFront();
   cout << "List2 after get from front: " << endl;
   integerList2.print();

   //   EX.1
   while(integerList2.isEmpty() != true){
	   integerList1.insertAtBack(integerList2.getFromFront());
   }

   cout << "Concatenates two linked list: " << endl;
   integerList1.print();



   return 0;
} // end main


