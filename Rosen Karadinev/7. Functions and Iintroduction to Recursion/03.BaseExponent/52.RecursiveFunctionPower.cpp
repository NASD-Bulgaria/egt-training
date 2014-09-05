//Write a recursive function power ( base, exponent ) that,
//when invoked, returns
//baseexponent For example, power( 3, 4 ) = 3 * 3 * 3 * 3.
//Assume that exponent is an integer greater than or equal to 1.


#include <iostream>
using namespace std;

int power (int base, int exp)
{
	// base case
	if (exp == 1)
	{
		return base * 1;
	}

	// recursive step
	else if (exp > -1)
	{
		exp--;
	}

	return base * (power(base,exp));

}

int main()
{
	int base, exp;
	cout << "a= ";
	cin >> base;

	cout << "b= ";
	cin >> exp;

	cout << base << "^" << exp << " = " << power(base,exp) << endl;

	return 0;
}
