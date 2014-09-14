#include <iostream> 

using namespace std;

class Base 
{
public:
   Base( int n ) 
   {
      num = n;
   }

   void print() 
   {
      cout << num;
   }

private:
   int num;
};

class D1 : virtual public Base 
{
public:
   D1(): Base( 3 ) {}
};

class D2 : virtual public Base 
{
public:
   D2(): Base( 5 ) {}
};

class Multi : public D1, D2 
{
public:
   Multi( int a ): Base( a ) {}
};

int main()
{
   Multi m( 9 );
   m.print();
   cout << endl;
}
