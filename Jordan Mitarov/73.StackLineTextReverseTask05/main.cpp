/*Write a program that inputs a line of text and uses
a stack object to print the line reversed.*/


#include <iostream>
#include <string>
using namespace std;


#include "Stackcomposition.h"  // Stack class definition

int main()
{
   Stack< char > charStack; // create Stack of ints
   char c;
   cout << "processing an char Stack" << endl;

   cout<<"Enter a string: ";

   while((c=static_cast<char>( cin.get() ) )!= '\n')
   {
	   charStack.push(c);
   }

   cout<<"The string in reverse: ";

   while(!charStack.isStackEmpty())
   {
	   charStack.pop(c);
	   cout<<c<<' ';
   }
   cout<<endl;
   return 0;
} // end main

