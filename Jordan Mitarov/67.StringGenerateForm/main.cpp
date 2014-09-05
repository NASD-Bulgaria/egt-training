#include <iostream>
 #include <string>
 using namespace std;

int main()
 {
 string alpha = "abcdefghijklmnopqrstuvwxyz{";
 string::const_iterator x = alpha.begin();
 string::const_iterator x2;

	 for ( int p = 1; p <= 14; p++ )
	 {
		  int w; // index variable
		  int count = 0; // set to 0 each iteration

		  // output spaces
		  for ( int k = 13; k >= p; k-- )
			  cout << ' ';

		   x2 = x; // set starting point

		  // output first half of characters
		  for ( int c = 1; c <= p; ++c )
		  {
			  cout << *x2;
			  ++x2; // move forward one letter
			  ++count; // keep count of iterations
		  } // end for

		  // output back half of characters
		  for ( w = 1, x2 -= 2; w < count; w++ )
		  {
			  cout << *x2;
			 --x2; // move backward one letter
		  } // end for

		 ++x; // next letter
		 cout << '\n';
	 } // end for
 } // end main
