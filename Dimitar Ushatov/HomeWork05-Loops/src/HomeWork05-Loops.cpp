//============================================================================
// Name        : HomeWork05-Loops.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <climits>
#include <algorithm>
using namespace std;

void PrintNumbersToN() {
	int n;
	cout << "Enter n:" << endl;
	cin >> n;

	for (int var = 1; var <= n; ++var) {
		cout << var << (var != n ? ", " : "\n");
	}
}

void PrintNotDivisibleBy3And7() {
	int n;
	cout << "Enter n:" << endl;
	cin >> n;

	for (int var = 1; var <= n; ++var) {
		if (var % 3 == 0 && var % 7 == 0) {
			continue;
		} else {
			cout << var << (var != n ? ", " : "\n");
		}
	}
}

void FindMinAndMax() {
	int n, num;
	cout << "Enter n:" << endl;
	cin >> n;
	int min = INT_MAX;
	int max = INT_MIN;

	for (int var = 0; var < n; ++var) {
		cin >> num;
		if (num > max) {
			max = num;
		}
		if (num < min) {
			min = num;
		}
	}

	cout << max << endl << min << endl;
}

void CalculateFormula() {
	int n;
	double x;
	double sum = 1;
	cout << "Enter n:" << endl;
	cin >> n;
	cout << "Enter x:" << endl;
	cin >> x;
	for (int i = n; i > 0; i--) {
		sum = sum * (i / x) + 1;
	}

	cout << "The result is: " << sum << endl;
}

void ConvertToBinary() {
	int num;
	string binNum = "";
	cout << "Enter number:" << endl;
	cin >> num;

	while (num != 0) {
		if (num % 2 == 0) {
			binNum += '0';
		} else {
			binNum += '1';
		}

		num /= 2;
	}

	for (int bit = binNum.length() - 1; bit >= 0; bit--) {
		cout << binNum[bit];
	}
	cout << endl;
}

void ConvertBinaryToDecimal() {
	string binNum = "";
	int num = 0;
	cout << "Enter binary number:" << endl;
	cin >> binNum;
	for (int var = 0; var < (int) binNum.length(); ++var) {
		if (binNum[var] != 0) {
			num += pow(2, (int) binNum.length() - 1 - var);
		}
	}

	cout << num << endl;
}

void ConvertDecimalToHex() {
	int num;
	string hexNum = "";
	cout << "Enter decimal number:" << endl;
	cin >> num;
	while (num != 0) {
		switch (num % 16) {
		case 0:
			hexNum += '0';
			break;
		case 1:
			hexNum += '1';
			break;
		case 2:
			hexNum += '2';
			break;
		case 3:
			hexNum += '3';
			break;
		case 4:
			hexNum += '4';
			break;
		case 5:
			hexNum += '5';
			break;
		case 6:
			hexNum += '6';
			break;
		case 7:
			hexNum += '7';
			break;
		case 8:
			hexNum += '8';
			break;
		case 9:
			hexNum += '9';
			break;
		case 10:
			hexNum += 'A';
			break;
		case 11:
			hexNum += 'B';
			break;
		case 12:
			hexNum += 'C';
			break;
		case 13:
			hexNum += 'D';
			break;
		case 14:
			hexNum += 'E';
			break;
		case 15:
			hexNum += 'F';
			break;
		default:
			break;
		}
		num /= 16;
	}

	for (int bit = hexNum.length() - 1; bit >= 0; bit--) {
		cout << hexNum[bit];
	}
	cout << endl;
}

void ConvertHexToDecimal() {
	string hexNum = "";
	int multyplier;
	int num = 0;
	cout << "Enter hexadecimal number:" << endl;
	cin >> hexNum;
	for (int bit = 0; bit < (int) hexNum.length(); ++bit) {
		switch ((char) toupper(hexNum[bit])) {
		case '0':
			multyplier = 0;
			break;
		case '1':
			multyplier = 1;
			break;
		case '2':
			multyplier = 2;
			break;
		case '3':
			multyplier = 3;
			break;
		case '4':
			multyplier = 4;
			break;
		case '5':
			multyplier = 5;
			break;
		case '6':
			multyplier = 6;
			break;
		case '7':
			multyplier = 7;
			break;
		case '8':
			multyplier = 8;
			break;
		case '9':
			multyplier = 9;
			break;
		case 'A':
			multyplier = 10;
			break;
		case 'B':
			multyplier = 11;
			break;
		case 'C':
			multyplier = 12;
			break;
		case 'D':
			multyplier = 13;
			break;
		case 'E':
			multyplier = 14;
			break;
		case 'F':
			multyplier = 15;
			break;
		default:
			break;
		}
		num += multyplier * pow(16, (int) hexNum.length() - 1 - bit);
	}

	cout << num << endl;
}

void PrintFibonachi() {
	int n;
	int first = 0;
	int second = 1;
	int third = first + second;
	int sum = 0;
	cout << "Enter n:" << endl;
	cin >> n;

	sum += first;
	if (n == 1) {
		cout << first << endl;
		cout << sum << endl;
	} else if (n == 2) {
		sum += second;
		cout << first << ", " << second << endl;
		cout << sum << endl;
	} else {
		sum = second + third;
		cout << first << ", " << second << ", " << third << (n > 3 ? ", " : "\n");
		for (int element = 4; element <= n; ++element) {
			first = second;
			second = third;
			third = first + second;
			sum += third;
			cout << third << (element != n ? ", " : "\n");
		}
		cout<<sum<<endl;
	}
}

void CatalanNumbers() {
	int n = 0;
	long nominator = 1;
	long denominator = 1;
	double catalan = 0;
	cout << "Enter n:" << endl;
	cin >> n;
	for (int element = n + 2; element <= n * 2; ++element) {
		nominator *= (element % 2 == 0 ? element / 2 : element);
	}

	for (int element = 1; element <= n; ++element) {
		denominator *= (element % 2 == 0 ? element / 2 : element);
	}

	catalan = nominator / denominator;

	cout << "The Catalan number by given N = " << n << " is " << catalan
			<< endl;
}

void FindTrailingZeros() {
	int n = 0;
	int divisor = 5;
	int trailingZeros = 0;

	cout << "Enter n:" << endl;
	cin >> n;

	while (divisor <= n) {
		trailingZeros += n / divisor;
		divisor = divisor * 5;
	}

	cout << "The number of trailing zeros in " << n << "! is " << trailingZeros
			<< endl;
}

void PrintReverseNumber() {
	int sumOfDigits, currentSum, reversed, digit, control;
	cout << "Enter the sum of digits:" << endl;
	cin >> sumOfDigits;

	currentSum = 0;
	reversed = 0;

	for (int num = 1; num <= 10000000; ++num) {
		control = num;
		while (control != 0) {
			digit = control % 10;
			reversed = reversed * 10 + digit;
			currentSum += digit;
			control /= 10;
		}

		if (reversed == num && currentSum == sumOfDigits) {
			cout << num << endl;
		}

		reversed = 0;
		currentSum = 0;
	}
}

void PrintAccendingNum() {
	int control, num, currentMin;
	bool digitLess = true;
	currentMin = INT_MAX;

	for (num = 1; num <= 1000000; ++num) {
		currentMin = num % 10;
		control = num / 10;
		while (control != 0) {
			if (currentMin - control % 10 == 1) {
				currentMin = control % 10;
			} else {
				digitLess = false;
				break;
			}
			control /= 10;
		}

		if (digitLess) {
			cout << num << endl;
		}
		digitLess = true;
	}
}


void PrintPowNumbers() {
	int candidate, power, baseMultiplier, added;
	candidate = 0;
	power = 0;
	for (int start = 1; start <= 9; start++) {
		baseMultiplier = 10;
		while (true) {
			power = power + 1;
			added = pow(start, power);
			while(added > baseMultiplier){
				baseMultiplier*=10;
			}
			candidate = candidate * baseMultiplier + added;
			if (candidate > 0 && candidate < 10000000) {
				cout << candidate << endl;
			} else {
				break;
			}
		}
		candidate = 0;
		power = 0;
	}
}

void CheckDigitPowerOfTwo(){
	int num = 0;
	cout << "Enter a number:" << endl;
	cin >> num;
	bool valid = false;

	while(num!=0){
		switch(num % 10){
			case 0:
			case 1:
			case 2:
			case 4:
			case 8:
				valid = true;
				break;
			default:
				valid = false;
				break;
		}
		if(!valid){
			break;
		}
		num /= 10;
	}

	if (valid) {
		cout << "The digits of the number are 2^(OfSomePower)" << endl;
	} else{
		cout << "The digits of the number are not 2^(OfSomePower)" << endl;
	}
}

void FindNumWithMaxDividers() {
	int n, m, max, currentMax, candidate, divider;
	max = 0;
	currentMax = 0;
	cout << "Enter start" << endl;
	cin >> n;
	cout << "Enter end" << endl;
	cin >> m;

	for (; n <= m; n++) {
		for (divider = 2; divider < n; divider++) {
			if (n % divider == 0) {
				currentMax++;
			}
		}
		if (currentMax > max) {
			candidate = n;
			max = currentMax;
		}

		currentMax = 0;
	}

	cout << "The number " << candidate << " has the highest count of dividers ("
			<< max << ")" << endl;
}

void FindRepeatableDigit() {
	int num, maxValue, copyOfNum;
	cout << "Enter a number:" << endl;
	cin >> num;
	copyOfNum = num;
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;
	int count7 = 0;
	int count8 = 0;
	int count9 = 0;

	while(copyOfNum != 0){
		switch (copyOfNum % 10) {
			case 0:
				count0++;
				break;
			case 1:
				count1++;
				break;
			case 2:
				count2++;
				break;
			case 3:
				count3++;
				break;
			case 4:
				count4++;
				break;
			case 5:
				count5++;
				break;
			case 6:
				count6++;
				break;
			case 7:
				count7++;
				break;
			case 8:
				count8++;
				break;
			default:
				count9++;
				break;
		}

		copyOfNum /= 10;
	}

	maxValue = max(count0, count1);
	maxValue = max(maxValue, count2);
	maxValue = max(maxValue, count3);
	maxValue = max(maxValue, count4);
	maxValue = max(maxValue, count5);
	maxValue = max(maxValue, count6);
	maxValue = max(maxValue, count7);
	maxValue = max(maxValue, count8);
	maxValue = max(maxValue, count9);

	if (maxValue == count0) {
		cout << "The digit 0 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
	if (maxValue == count1) {
		cout << "The digit 1 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
	if (maxValue == count2) {
		cout << "The digit 2 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
	if (maxValue == count3) {
		cout << "The digit 3 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
	if (maxValue == count4) {
		cout << "The digit 4 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
	if (maxValue == count5) {
		cout << "The digit 5 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
	if (maxValue == count6) {
		cout << "The digit 6 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
	if (maxValue == count7) {
		cout << "The digit 7 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
	if (maxValue == count8) {
		cout << "The digit 8 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
	if (maxValue == count9) {
		cout << "The digit 9 has the highest count of occurrences in " << num
				<< " equal to " << maxValue << endl;
	}
}

void CalcGCD(){
	int first, second;
	cout << "Enter the first number" << endl;
	cin >> first;
	cout << "Enter the second number" << endl;
	cin >> second;
	int x = first;
	int y = second;
	while (x != y) {
		if (x > y) {
			x -= y;
		} else {
			y -= x;
		}
	}

	cout << "The Grates Common Divisor of " << first << " and " << second
			<< " = " << y << endl;
}

void CalcLCD(){
	int first, second;
	cout << "Enter the first number" << endl;
	cin >> first;
	cout << "Enter the second number" << endl;
	cin >> second;
	int x = first;
	int y = second;
	int temp;

	while (y != 0) {
		temp = x;
		x = y;
		y = temp % y;
		cout << x << " " << y <<endl;
	}
	cout << "The least common denominator of " << first << " and " << second
			<< " is " << (first * second) / x << endl;
}

void Interval100To1000(){
	int num, reversed, copyOfNum;
	bool prime;

	for (num = 100; num <= 1000; num++) {
		copyOfNum = num;
		reversed = 0;
		while (copyOfNum != 0) {
			reversed = reversed * 10 + copyOfNum % 10;
			copyOfNum /= 10;
		}

		if (num == reversed) {
			prime = true;
			for (int divider = 2; divider <= (int) sqrt(num); divider++) {
				if (num % divider == 0) {
					prime = false;
					break;
				}
			}
			if (prime) {
				cout << num << endl;
			}
		}
	}
}

void Solve5Of35(){
	int max = 36;
	int count = 0;
	for (int a = 1; a < max; ++a) {
		for (int b = a + 1; b < max; ++b) {
			for (int c = b + 1; c < max; ++c) {
				for (int d = c + 1; d < max; ++d) {
					for (int e = d + 1; e < max; ++e) {
						cout << a << ", "<< b << ", "<< c << ", "<< d << ", "<< e <<endl;
					}
				}
			}
		}
	}

	cout << count << endl;
}

int main() {
//	PrintNumbersToN();
//	PrintNotDivisibleBy3And7();
//	CalculateFormula();
//	ConvertToBinary();
//	ConvertBinaryToDecimal();
//	ConvertDecimalToHex();
//	ConvertHexToDecimal();
//	PrintFibonachi();
//	CatalanNumbers();
//	FindTrailingZeros();
//	PrintReverseNumber();
//	PrintAccendingNum();
//	PrintPowNumbers();
//	CheckDigitPowerOfTwo();
//	FindNumWithMaxDividers();
//	FindRepeatableDigit();
	CalcGCD();
//	CalcLCD();
//	Interval100To1000();
//	Solve5Of35();
	return 0;
}
