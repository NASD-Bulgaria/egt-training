//Write a program that reads a sequence of integers ending
//with 0 and sorts them in an increasing order. Use linked
//list.

#include <iostream>
#include <list> // list class-template definition
#include <algorithm> // copy algorithm
#include <iterator> // ostream_iterator
using namespace std;
// prototype for function template printList


int main()
{

   list< int > values;

   int input;
   do{
	   cout << "? ";
	   cin >> input;
	   if(input == 0)
		   break;
	   values.push_back(input);
   }
   while(input);
   for (list<int>::iterator it = values.begin(); it != values.end(); ++it)
	   cout << *it <<' ';
   cout << endl;
   values.sort();
   for (list<int>::iterator it = values.begin(); it != values.end(); ++it)
	   cout << *it <<' ';


   return 0;
} // end main

// printList function template definition; uses
// ostream_iterator and copy algorithm to output list elements
