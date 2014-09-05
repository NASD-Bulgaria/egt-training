/*Write a program that uses a stack object to
determine if a string is a palindrome. The program
should ignore spaces and punctuation.*/

#include <iostream>
using namespace std;

#include "Stackcomposition.h"  // Stack class definition

void isPolyndrome(Stack<char> &);

int main()
{
   Stack< char > charStack; // create Stack of ints
   cout << "processing an integer Stack" << endl;

   isPolyndrome(charStack);

   return 0;
} // end main

void isPolyndrome(Stack<char> &polStack)
{
   char c;
   char stringOne[70];
   char stringTwo[70];
   int i=0;

   cout<<"Enter a string: ";

   while((c=static_cast<char>(cin.get()))!='\n')
   {
	   if(isalpha(c))
	   {
		   stringOne[i++] = c;
		   polStack.push(c);
	   }
   }

   stringOne[i] = '\0';
   i = 0;

   while(!polStack.isStackEmpty())
   {
	   polStack.pop(stringTwo[i++]);
   }

   stringTwo[i] = '\0';

   if(strcmp(stringOne,stringTwo) == 0)
   {
	   cout<<"The string is palyndrome "<<endl;
   }
   else
   {
	   cout<<"The string is not palyndrome"<<endl;
   }
 }
