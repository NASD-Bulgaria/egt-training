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
