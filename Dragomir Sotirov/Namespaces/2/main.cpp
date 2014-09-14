#include <iostream>  

using namespace std;

int main()
{
   const char c = 'A';
   const char *ptr = &c;

   cout << "c is " << *ptr;

   *const_cast< char * > ( ptr ) = 'Z';
   
   cout << "\nc is " << *ptr << endl;
}
