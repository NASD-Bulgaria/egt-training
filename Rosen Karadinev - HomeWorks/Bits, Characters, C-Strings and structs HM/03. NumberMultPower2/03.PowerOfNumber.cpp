//Left-shifting an unsigned integer by 1 bit is
//equivalent to multiplying the value by 2. Write
//function power2 that takes two integer arguments,
//number and pow, and calculates number* 2pow
//Use a shift operator to calculate the result. The program
//should print the values as integers and as bits.

#include <iostream>
using namespace std;

int power2(int , int);
void displayBits(unsigned);

int main()
{

	int number;
	cout << "Enter an integer number: ";
	cin >> number;

	int power;
	cout << "Enter the power: ";
	cin >> power;

	int newValue;
	newValue = power2(number, power);

	cout <<"The new number is " << newValue  << endl;
	displayBits(newValue);

	return 0;
}

int power2(int number, int power)
{
	return number * (2 << power);

}

void displayBits( unsigned value )
{
   const int SHIFT = 4 * sizeof( unsigned ) - 1;
   const unsigned MASK = 1 << SHIFT;

   cout << value << " = ";

   for ( unsigned i = 1; i <= SHIFT + 1; i++ )
   {
      cout << ( value & MASK ? '1' : '0' );
      value <<= 1;

      if ( i % 4 == 0 )
         cout << ' ';
   }

   cout << endl;
}
