//============================================================================
// Name        : HomeWork10-FunctionsAndRecursion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Garage.h"
#include <cstdlib>
#include <ctime>
using namespace std;

enum fliped {
	tails = 1, heads = 0
};

int flip() {
	return rand() % 2;
}

void firstTask() {
	ParkedCar carA(12.5);
	ParkedCar carB(1.5);
	ParkedCar carC(24);
	vector<ParkedCar> cars;
	cars.push_back(carA);
	cars.push_back(carB);
	cars.push_back(carC);

	Garage garage(2, 10, 0.5, cars);
	vector<double> fees = garage.calculateFees();

	for (int fee = 0; fee < fees.size(); ++fee) {
		cout << fees[fee] << endl;
	}
}

void coinToss() {
	int coutOfFlips[2] = { 0 };
	srand(time(NULL));
	for (int fliped = 0; fliped < 100; ++fliped) {
		if (flip() == heads) {
			coutOfFlips[0]++;
		} else {
			coutOfFlips[1]++;
		}
	}
	cout << coutOfFlips[0] << " " << coutOfFlips[1] << endl;
}

long recursivePow(long base, int exponent) {
	if (exponent == 1) {
		return base;
	} else {
		return base * recursivePow(base, exponent - 1);
	}
}

int recursiveGCD(long x, long y) {
	if (y == 0) {
		return x;
	} else {
		return recursiveGCD(y, x % y);
	}
}

int arrangeDisks(int firstPeg, int secondPeg, int thirdPeg) {
	cout << firstPeg << endl;
	cout << secondPeg << endl;
	cout << thirdPeg << endl;
	if (thirdPeg == 1 && secondPeg == 0 && firstPeg == 0) {
		return thirdPeg;
	}

	if (thirdPeg > firstPeg && secondPeg == 0) {
		return arrangeDisks(firstPeg - 1, secondPeg, firstPeg);
	}
}

void towersOfHanoy() {
}

int main() {
//	firstTask();
//	coinToss();
//	cout << recursivePow(2, 10) << endl;
//	cout << recursiveGCD(1000,101)<< endl;
	int peg = arrangeDisks(64, 0, 0);
	return 0;
}
