//============================================================================
// Name        : HomeWork07-Functions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printName(string name) {
	cout << "Hello, " << name << endl;
}

int getMax(int first, int second) {
	int max = first;
	if (second > max) {
		max = second;
	}

	return max;
}

string convertDigitToName(int number) {
	int lastDigit = number % 10;
	string word = "";

	switch (lastDigit) {
	case 0:
		word = "zero";
		break;
	case 1:
		word = "one";
		break;
	case 2:
		word = "two";
		break;
	case 3:
		word = "three";
		break;
	case 4:
		word = "four";
		break;
	case 5:
		word = "five";
		break;
	case 6:
		word = "six";
		break;
	case 7:
		word = "seven";
		break;
	case 8:
		word = "eight";
		break;
	case 9:
		word = "nine";
		break;
	default:
		break;
	}

	return word;
}

int reverseNumber(int number) {
	int reversed = 0;

	while (number != 0) {
		reversed = reversed * 10 + number % 10;
		number /= 10;
	}

	return reversed;
}

double getAvarage(int array[3]) {
	double sum = 0;

	for (int element = 0; element < 3; ++element) {
		sum += array[element];
	}

	return sum / 3;
}

double solveEquation(double a, double b) {
	return -b / a;
}

bool validateNumber(int number) {
	return number > 0;
}

bool validateArray(int array[]) {
	if (array == NULL) {
		return false;
	}
	return true;
}

bool validateEquation(int paramA) {
	return paramA != 0;
}

double calcParkingCharge(double hours) {
	double charge = 2.0;
	if (24 > hours && hours >= 3) {
		hours = hours - 3;
		while (hours > 0) {
			charge += 0.5;
			hours -= 1;
		}
	} else if (hours >= 24) {
		charge = 10;
	}
	return charge;
}

int flip() {
	return rand() % 2;
}

int* registerTrows(int numberOfTrows) {
	int * countOfSides = new int[2];
	countOfSides[0] = 0;
	countOfSides[1] = 0;
	srand(time(NULL));
	int side;
	for (int round = 0; round < 100; ++round) {
		side = flip();
		if (side == 1) {
			cout << "Heads" << endl;
			countOfSides[0]++;
		} else {
			cout << "Tails" << endl;
			countOfSides[1]++;
		}
	}

	return countOfSides;
}

bool perfect(int number) {
	int sum = 0;
	for (int del = 1; del <= number / 2; ++del) {
		if (number % del == 0) {
			sum += del;
		}
	}

	return sum == number;
}

void simulateCoinToss() {
	int* sides = registerTrows(100);
	cout << "Heads was trowed " << sides[0] << " times" << endl;
	cout << "Tails was trowed " << sides[1] << " times" << endl;
}

int main() {

//	string name = "Dimitar";
//	printName(name);
//	name = "Kalin";
//	printName(name);
//
//	cout << "Enter a" << endl;
//	int a = 0;
//	cin >> a;
//	cout << "Enter b" << endl;
//	int b = 0;
//	cin >> b;
//	cout << "Enter c" << endl;
//	int c = 0;
//	cin >> c;
//
//	int max = getMax(a, b);
//	max = getMax(max, c);
//
//	cout << "The max number between " << a << ", " << b << " and " << c
//			<< " is " << max << endl;
//
//	cout << "Enter an integer to convert his last digit to word" << endl;
//	cin >> a;
//	cout << "The last digit of " << a << " is " << convertDigitToName(a)
//			<< endl;
//
//	cout << "Enter a positive number" << endl;
//	cin >> a;
//	while (!validateNumber(a)) {
//		cout << "The number must be positive. Enter a positive number" << endl;
//		cin >> a;
//	}
//
//	cout << "The reversed number is " << reverseNumber(a) << endl;
//
//	int seq[3] = { 0 };
//
//	for (int i = 0; i < 3; ++i) {
//		cout << "Enter element " << i << endl;
//		cin >> seq[i];
//	}
//
//	cout << "The avarage is " << getAvarage(seq) << endl;
//
//	cout << "Enter parameter a" << endl;
//	cin >> a;
//	while (!validateEquation(a)) {
//		cout << "Parameter a must not be equal to 0. Enter again" << endl;
//		cin >> a;
//	}
//
//	cout << "Enter parameter b" << endl;
//	cin >> b;
//	cout << "The result of " << a << "*X + " << b << " is "
//			<< solveEquation(a, b) << endl;
//
//	double first, second, third;
//	cout << "Enter first car hours" << endl;
//	cin >> first;
//	cout << "Enter second car hours" << endl;
//	cin >> second;
//	cout << "Enter third car hours" << endl;
//	cin >> third;
//
//	cout << "First car charge for " << first << " hours is "
//			<< calcParkingCharge(first) << " USD" << endl;
//	cout << "Second car charge for " << second << " hours is "
//			<< calcParkingCharge(second) << " USD" << endl;
//	cout << "Third car charge for " << third << " hours is "
//			<< calcParkingCharge(third) << " USD" << endl;

	simulateCoinToss();

	for (int num = 1; num <= 40000000; ++num) {
		if (perfect(num)) {
			cout<<num<<endl;
		}
	}
	return 0;
}
