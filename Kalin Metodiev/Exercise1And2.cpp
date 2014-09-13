///*
// * Exercise1.cpp
// *
// *  Created on: 9.09.2014 г.
// *      Author: стаса
// */
//
//#include <iostream>
//#include <iomanip>
//#include <cmath>
//#include <bitset>
//#include<vector>
//#include<set>
//
//using namespace std;
//
//int main()
//{
//	const int SIZE = 1024;
//
//
//	   std::bitset< SIZE > sieve;
//	   sieve.flip();
//	   sieve.reset( 0 );
//	   sieve.reset( 1 );
//
//
//	   int finalBit = sqrt( static_cast< double > ( sieve.size() ) ) + 1;
//
//	   for ( int i = 2; i < finalBit; i++ )
//	   {
//	      if ( sieve.test( i ) )
//	      {
//	         for ( int j = 2 * i; j < SIZE; j += i )
//	            sieve.reset( j );
//	      }
//	   }
//
//
//
//	   vector<int> primeNumbers;
//
//	   for (int k = 2; k < SIZE; k++ )
//	   {
//
//	      if ( sieve.test( k ) )
//	      {
//
//	         primeNumbers.push_back(k);
//
//	      }
//	     }
//
//	     set<int> uniqueNumbers;
//
//	     int n;
//	     cout << "Enter a number: ";
//	     cin >> n;
//
//
//	     int n2 = n;
//	     int counter = 0;
//
//	     if(n < 0)
//	     {
//	  	   n = -n;
//	     }
//
//	     cout << n << " = " ;
//
//	     while(n != 1)
//	     {
//	  	   if(n % primeNumbers[counter] == 0)
//	  	   {
//	  		   cout << primeNumbers[counter];
//	  		   n = n / primeNumbers[counter];
//	  		   uniqueNumbers.insert(primeNumbers[counter]);
//
//			   if(n != 1)
//			   {
//				   cout << " * ";
//			   }
//		   }
//		   else
//		   {
//			   counter ++;
//		   }
//	   }
//
//	   cout << endl;
//	   cout << n2 << " = ";
//	   for(set<int>::iterator it = uniqueNumbers.begin(); it != uniqueNumbers.end(); it++)
//	   {
//		   cout << *it << " ";
//	   }
//
//
//	   return 0;
//	}
//
