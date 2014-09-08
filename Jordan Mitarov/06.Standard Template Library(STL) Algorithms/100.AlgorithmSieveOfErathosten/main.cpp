// Fig. 5.26: main.cpp                                
// Using a bitset to demonstrate the Sieve of Eratosthenes.

/*1. Modify Fig. 5.26 (Lecture 5), the Sieve of
Eratosthenes, so that, if the number the user inputs
into the program is not prime, the program
displays the prime factors of the number.
Remember that a prime number's factors are only
1 and the prime number itself. Every nonprime
number has a unique prime factorization. For
example, the factors of 54 are 2, 3, 3 and 3. When
these values are multiplied together, the result is 54.
For the number 54, the prime factors output should
be 2 and 3.*/
#include <iostream>
#include <iomanip>
#include <cmath> 
#include <bitset> // bitset class definition
using namespace std;

int main()
{
   const int SIZE = 1024;
   int value;
   std::bitset< SIZE > sieve; // create bitset of 1024 bits
   sieve.flip(); // flip all bits in bitset sieve
   sieve.reset( 0 ); // reset first bit (number 0)         
   sieve.reset( 1 ); // reset second bit (number 1)        

   // perform Sieve of Eratosthenes
   int finalBit = sqrt( static_cast< double > ( sieve.size() ) ) + 1;

   // determine all prime numbers from 2 to 1024
   for ( int i = 2; i < finalBit; i++ )
   {
      if ( sieve.test( i ) ) // bit i is on
      {
         for ( int j = 2 * i; j < SIZE; j += i ) 
            sieve.reset( j ); // set bit j off
      } // end if
   } // end for

   cout << "The prime numbers in the range 2 to 1023 are:\n";

   // display prime numbers in range 2-1023
   for ( int k = 2, counter = 1; k < SIZE; k++ )
   {
      if ( sieve.test( k ) ) // bit k is on
      {
         cout << setw( 5 ) << k;

         if ( counter++ % 12 == 0 ) // counter is a multiple of 12
            cout << '\n';
      } // end if          
   } // end for    
   
   cout << endl;

   // get value from user 
   cout << "\nEnter a value from 2 to 1023 (-1 to end): ";
   cin >> value;

   // determine whether user input is prime
   while ( value != -1 ) 
   {
	   if(value < 1)
	   {
		   value *= -1;
	   }

      if ( sieve[ value ] ) // prime number
         cout << value << " is a prime number\n";
      else // not a prime number
         cout << value << " is not a prime number\n"<<"prime factors(s): ";
      
      bool print = true;

      for(int f = 2; f< SIZE; )
      {
    	  if ( sieve.test( f ) && value % f == 0 )
    	 {
			 if ( print )
			 cout << f << ' '; // output factor

			  value /= f; // modify value

			 if ( value <= 1 ) // time to stop
				 break;

				 print = false;
    	 } // end if
    	 else
    	 {
			 ++f; // move to next prime
			 print = true;
    	 } // end else
      }

      cout << "\nEnter a value from 2 to 1023 (-1 to end): ";
      cin >> value;
   } // end while

   return 0;
} // end main

