//Write a program that uses a function template called max to determine the
//largest of three arguments. Test the program using integer, character and
//floating-point number arguments.

#include <iostream>
#include "Maximum.h"
using namespace std;

int main()
{
	int number1, number2, number3;

	cout << "Input three integer values: " << endl;
	cin >> number1 >> number2 >> number3;

	cout << "The maximum number is " << maximum(number1, number2, number3) << endl;

	char ch1, ch2, ch3;
	cout << "Input three chars: " << endl;
	cin >> ch1 >> ch2 >> ch3;

	cout << "The maximum char is " << maximum(ch1, ch2, ch3) << endl;

	float fnum1, fnum2, fnum3;

	cout << "Input three float numbers: " << endl;
	cin >> fnum1 >> fnum2 >> fnum3;

	cout << "The maximum float number is " << maximum(fnum1, fnum2, fnum3) << endl;

	return 0;
}
