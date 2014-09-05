#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  double x = 100.453627; // value to test precision outputs

   cout << fixed; // display output using fixed point notation

   // display output using loop counter as precision
   for ( int loop = 0; loop <= 5; loop++ )
    {
         cout << setprecision( loop ) << "Rounded to " << loop
          << " digit(s) is " << x << endl;
    }


    return 0;
}


