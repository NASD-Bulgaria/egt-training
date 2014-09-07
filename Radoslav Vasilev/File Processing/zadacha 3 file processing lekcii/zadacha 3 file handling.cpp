#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
   ofstream outFile( "datasize.dat" );

   if ( !outFile )
   {
      cerr << "file can`t be opened \"datasize.dat\"."<<endl;
      exit( 1 );
   }


   	  outFile << "Data type" << setw( 33 ) << "Size\nchar" << setw( 30 )
      << sizeof( char ) << "\nunsigned char" << setw( 21 )
      << sizeof( unsigned char ) << "\nshort int" << setw( 25 )
      << sizeof( short int ) << "\nunsigned short int" << setw( 16 )
      << sizeof( unsigned short ) << "\nint" << setw( 31 )
      << sizeof( int ) << "\nunsigned int" << setw( 22 ) << sizeof( unsigned )
      << "\nlong int" << setw( 26 ) << sizeof( long )
      << "\nunsigned long int" << setw( 17 ) << sizeof( unsigned long )
      << "\nfloat" << setw( 29 ) << sizeof( float )
      <<"\nunsigned long long int"<<setw(12)<<sizeof(unsigned long long)
      << "\ndouble" << setw( 28 ) << sizeof( double )
      << "\nlong double" << setw( 23 ) << sizeof( long double ) << endl;



}
