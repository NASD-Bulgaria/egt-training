/*
 * Main.cpp
 *
 *  Created on: 26.08.2014 ã.
 *      Author: Admin
 */
#include <iostream>
 using std::cout;
 using std::endl;

#include <memory>
 using std::auto_ptr; // auto_ptr class definition

 #include "Integer.h"

 // use auto_ptr to manipulate Integer object
 int main(){
 cout << "Creating an auto_ptr object that points to an Integer\n";

 // "aim" auto_ptr at Integer object
 auto_ptr< Integer > ptrToInteger( new Integer( 7 ) );

 cout << "\nUsing the auto_ptr to manipulate the Integer\n";
 ptrToInteger->setInteger( 99 ); // use auto_ptr to set Integer value

 // use auto_ptr to get Integer value
 cout << "Integer after setInteger: " << ( *ptrToInteger ).getInteger();
 return 0;
 } // end main



