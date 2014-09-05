//============================================================================
// Name        : Lections_26_ex7_MM.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// 7. Write a program that removes from a given
//sequence all negative numbers.

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

using namespace std;

template <class T>
void print(T& c){
   for( typename T::iterator i = c.begin(); i != c.end(); i++ ){
      std::cout << *i << endl;
   }
}

int main( )
{
   const float a[] = { 1, -2.3, 4.5, -6.7, 8.9, 10.2};
   vector<float> data( a,a + sizeof( a ) / sizeof( a[0] ) );

   cout << "DATA VECTOR HAS " << data.size() << " ELEMENTS\n";
   print( data  );
   list<float> l( data.begin(), data.end() );
   cout << "\nSize of list before calling remove_if: "<< l.size() << endl;
   l.remove_if( bind2nd( less<float>(), 0 ) );
   cout << "Size of list after calling remove_if: " << l.size() << endl;
   print( l );
}
/*
 * Console
DATA VECTOR HAS 6 ELEMENTS
1
-2.3
4.5
-6.7
8.9
10.2

Size of list before calling remove_if: 6
Size of list after calling remove_if: 4
1
4.5
8.9
10.2
 */
