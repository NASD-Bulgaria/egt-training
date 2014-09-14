#include <iostream>

using namespace std;


namespace Currency 
{
   enum Money { ONE = 1, TWO, FIVE = 5, TEN = 10, TWENTY = 20, FIFTY = 50, HUNDRED = 100 };
}

int main()
{
   using Currency::FIVE;

   cout << "FIVE's value is: " << FIVE << endl;
}
