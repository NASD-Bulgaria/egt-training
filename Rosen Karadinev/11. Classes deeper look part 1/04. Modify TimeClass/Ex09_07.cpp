// Exercise 9.7: Ex09_07.cpp
#include <iostream> 
#include "Time.h" // include definition of class Time
using namespace std;

const int MAX_TICKS = 30;

int main()
{
   Time t; // instantiate object t of class Time

   t.setTime( 23, 59, 57 ); // set time

   // output Time object t's values 
   for ( int ticks = 1; ticks < MAX_TICKS; ++ticks ) 
   {
      t.printStandard(); // invokes function printStandard
      cout << endl;
      t.tick(); // invokes function tick
   } // end for
} // end main



