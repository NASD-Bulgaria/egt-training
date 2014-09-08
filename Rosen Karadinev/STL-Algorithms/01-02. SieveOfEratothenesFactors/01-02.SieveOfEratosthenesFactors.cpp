//Modify Fig. 5.26 (Lecture 5), the Sieve of
//Eratosthenes, so that, if the number the user inputs
//into the program is not prime, the program
//displays the prime factors of the number.
//Remember that a prime number's factors are only
//1 and the prime number itself. Every nonprime
//number has a unique prime factorization. For
//example, the factors of 54 are 2, 3, 3 and 3. When
//these values are multiplied together, the result is 54.
//For the number 54, the prime factors output should
//be 2 and 3.

#include <iomanip>
using std::setw;
#include <iostream>
#include <cmath>
using std::sqrt; // sqrt prototype
#include <bitset> // bitset class definition
#include <vector>
#include <set>

using namespace std;

int main()
{
   const int SIZE = 1024;


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
      }
   }



   vector<int> primeNumbers;

   for (int k = 2; k < SIZE; k++ )
   {

      if ( sieve.test( k ) ) // bit k is on
      {

         primeNumbers.push_back(k);


      }
   }

   set<int> uniqueNumbers;

   int n;
   cout << "Enter a number: ";
   cin >> n;


   int n2 = n;
   int counter = 0;

   if(n < 0)
   {
	   n = -n;
   }

   cout << n << " = " ;

   while(n != 1)
   {
	   if(n % primeNumbers[counter] == 0)
	   {
		   cout << primeNumbers[counter];
		   n = n / primeNumbers[counter];
		   uniqueNumbers.insert(primeNumbers[counter]);


		   if(n != 1)
		   {
			   cout << " * ";
		   }
	   }
	   else
	   {
		   counter ++;
	   }
   }

   cout << endl;
   cout << n2 << " = ";
   for(set<int>::iterator it = uniqueNumbers.begin(); it != uniqueNumbers.end(); it++)
   {
	   cout << *it << " ";
   }


   return 0;
} // end main

