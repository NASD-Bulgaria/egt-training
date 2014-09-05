// Exercise 11.9 Solution: Hugeint.h
// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
   friend ostream &operator<<( ostream &, const HugeInt & );
public:
   static const int digits = 30; // maximum digits in a HugeInt

   HugeInt( long = 0 ); // conversion/default constructor
   HugeInt( const string & ); // conversion constructor

   // addition operator; HugeInt + HugeInt
   HugeInt operator+( const HugeInt & ) const;

   // addition operator; HugeInt + int
   HugeInt operator+( int ) const; 

   // addition operator; 
   // HugeInt + string that represents large integer value
   HugeInt operator+( const string & ) const;

   bool operator==( const HugeInt & ) const; // equality operator
   bool operator!=( const HugeInt & ) const; // inequality operator
   bool operator<( const HugeInt & ) const; // less than operator

   // less than or equal to operator
   bool operator<=( const HugeInt & ) const; 
   bool operator>( const HugeInt & ) const; // greater than operator

   // greater than or equal to operator
   bool operator>=( const HugeInt & ) const;
   HugeInt operator-( const HugeInt & ) const; // subtraction operator
   HugeInt operator*( const HugeInt & ) const; // multiply two HugeInts
   HugeInt operator/( const HugeInt & ) const; // divide two HugeInts

   int getLength() const;
private:
   short integer[ digits ];
}; // end class HugeInt

#endif
