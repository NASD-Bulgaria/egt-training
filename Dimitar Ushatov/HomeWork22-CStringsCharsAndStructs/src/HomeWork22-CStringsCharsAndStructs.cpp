//============================================================================
// Name        : HomeWork22-CStringsCharsAndStructs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <bitset>
#include "DeckOfCards.h"
using namespace std;

void solveTaskOne();

void solveTaskTwo();

void solveTaskThree();

void solveTaskFour();

int powerOfTwo(int num, int pow);

int packCharacters(char first, char second);

void unpackCharacters(int packed);

int main() {
//	solveTaskTwo();
//	solveTaskThree();
	solveTaskFour();
	return 0;
}

void solveTaskOne() {
	DeckOfCards deckOfCards; // create DeckOfCards object

	deckOfCards.shuffle(); // shuffle the cards in the deck
	deckOfCards.deal(); // deal the cards in the deck
}

void solveTaskTwo() {
	int number;
	cout << "Enter a number" << endl;
	cin >> number;
	bitset<32> bitNum(number);
	cout << bitNum << endl;
	number >>= 4;
	bitset<32> newBitNum(number);
	cout << newBitNum << endl;
	cout << number;
}

int powerOfTwo(int num, int pow) {
	int powOfTwo = 1;
	return num * (powOfTwo <<= pow);
}

void solveTaskThree() {
	cout << "Enter n" << endl;
	int n;
	cin >> n;
	cout << "Enter pow" << endl;
	int pow;
	cin >> pow;
	cout << "The result of " << n << " * 2^" << pow << " is "
			<< powerOfTwo(n, pow) << endl;
}

int packCharacters(char first, char second) {
	int a = first;
	a <<= 8;
	return a | second;
}

void solveTaskFour() {
	cout << "Enter first" << endl;
	char first;
	cin >> first;
	cout << "Enter second" << endl;
	char second;
	cin >> second;
	int packed = packCharacters(first, second);
	cout << "First\n" << bitset<32>(first) << endl;
	cout << "Second\n" << bitset<32>(second) << endl;
	cout << "Packed\n" << bitset<32>(packed) << endl;
	unpackCharacters(packed);
}

void unpackCharacters(int packed) {
	int second = packed & 255;
	int first = packed >> 8;
	cout << "The unpacked characters are: '" << (char) first << "' and '"
			<< (char) second << "'!\n";
}
