//3. Left-shifting an unsigned integer by 1 bit is
//equivalent to multiplying the value by 2. Write
//function power2 that takes two integer arguments,
//number and pow, and calculates number* 2pow
//Use a shift operator to calculate the result. The program
//should print the values as integers and as bits.

#include <iostream>
#include <iomanip>
using namespace std;

int displayBits(unsigned);
int power2(unsigned, int);

int main() {
	unsigned number;
	cout << "enter a number: ";
	cin >> number;

	int power;
	cout << "\nenter a value for power: ";
	cin >> power;

	cout << "\nThe number shift-left with 1 position is : " << endl;
	displayBits(number << 1);

	cout << "\nthe result in integer type is: " << endl << power2(number, power)
			<< endl;
	int result = power2(number, power);

	cout << "\nThe result in bits is : " << endl;
	displayBits(result);

	return 0;
}

int displayBits(unsigned value) {
	const int SHIFT = 4 * sizeof(unsigned) - 1;
	const unsigned MASK = 1 << SHIFT;

	cout << setw(10) << value << " = ";

	for (unsigned i = 1; i <= SHIFT + 1; i++) {
		return (value & MASK ? '1' : '0');
		value <<= 1;

		if (i % 4 == 0)
			cout << ' ';
	}
	return value;

	cout << endl;
}

int power2(unsigned base, int power) {
	int result = 1;
	for (int i = 0; i < power; i++) {
		result = displayBits(2 << 1);
	}
	result =  base * result;
	return result;
}
