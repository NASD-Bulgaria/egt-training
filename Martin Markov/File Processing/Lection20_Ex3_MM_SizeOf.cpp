//============================================================================
// Name        : Lection20_Ex3_MM_SizeOf.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
Lec20.Ex3:
Write a program that uses the sizeof operator to
determine the sizes in bytes of the various data types
on your computer system. Write the results to the
file datasize.dat, so that you may print the results
later. The results should be displayed in two-column
format with the type name in the left column and
the size of the type in right column.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{

   ofstream outFile( "datasize.dat" );

   if ( !outFile )
   {
      cerr << "File not found\n";
      exit( 1 );
   }

   outFile << "Data type" << setw( 24 ) << "Size\nchar" << setw( 21 )
      << sizeof( char ) << "\nunsigned char" << setw( 12 )
      << sizeof( unsigned char ) << "\nshort int" << setw( 16 )
      << sizeof( short int ) << "\nunsigned short int" << setw( 7 )
      << sizeof( unsigned short ) << "\nint" << setw( 22 )
      << sizeof( int ) << '\n';


   outFile << "unsigned int" << setw( 13 ) << sizeof( unsigned )
      << "\nlong int" << setw( 17 ) << sizeof( long )
      << "\nunsigned long int" << setw( 8 ) << sizeof( unsigned long )
      << "\nfloat" << setw( 20 ) << sizeof( float )
      << "\ndouble" << setw( 19 ) << sizeof( double )
      << "\nlong double" << setw( 14 ) << sizeof( long double ) << endl;
    /*
   FILE:datasize.dat

   Data type               Size
   char                    1
   unsigned char           1
   short int               2
   unsigned short int      2
   int                     4
   unsigned int            4
   long int                4
   unsigned long int       4
   float                   4
   double                  8
   long double            12
   */

}
