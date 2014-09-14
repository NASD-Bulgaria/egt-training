#include <iostream>  

using namespace std;

namespace Currency 
{
   enum Money { ONE = 1, TWO, FIVE = 5, TEN = 10, TWENTY = 20, FIFTY = 50, HUNDRED = 100 };
}

int main()
{
   using namespace Currency;

   cout << "TWO's value is: " << TWO << "\nTEN's value is: " << TEN << endl;
}
