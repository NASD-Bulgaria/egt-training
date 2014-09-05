//============================================================================
// Name        : HomeWork01-PrimitiveDataTypes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void ExerciseTwoTaskOne(){
	int integerNumber = 0x100;
	cout << "Thu number 100 in hexadecimal numeric system is "
			<< integerNumber << " in decimal system" << endl;
}

void ExerciseTwoTaskTwo(){
	char charSymbol = (char)72;
	cout << "The char symbol with code 72 (decimal) is " << charSymbol << endl;
}

void ExerciseTwoTaskTree(){
	bool isFemale = false;
	cout << "I'm a female: " << (isFemale ? "true" : "false") << endl;
}

void ExerciseTreeTaskOne(){
	string hello = "Hello";
	string world = "World";
	string helloWorld = hello + " " + world;
	string newHelloWorld = helloWorld;

	cout<< "The first string is: \"" << hello << "\"" << endl;
	cout<< "The second string is: \"" << world << "\"" << endl;
	cout<< "The concatenated string is: \"" << helloWorld << "\"" << endl;
	cout<< "The new string is: \"" << newHelloWorld << "\"" << endl;
}

void ExerciseTreeTaskTwo(){
	string quotedString = "The \"use\" of quotations causes difficulties.";
	cout<< quotedString << endl;
}

void ExerciseFourTaskOne(){
	string line = "";
	for (int i = 0; i < 11; i++) {
		for (int g = 0; g < 11; g++) {
			if (i % 2 == 0 && g == (10 - i)/2) {
				line += "*";
			} else if(i % 2 == 0 && g == (10 + i)/2){
				line += "*";
			} else if(i == 10 && g % 2 == 0){
				line += "*";
			} else {
				line += " ";
			}
		}
		cout<< line << endl;
		line = "";
	}
}

void ExerciseFourTaskTwo(){
	string line = "";
	int radius = 5;
	for (int i = 0; i < radius + 1; i++) {
		for (int g = 0; g < radius * 4 + 1; g++) {
			if (((i-radius)*(i-radius)+(g-radius)*(g-radius) == radius*radius)
					|| ((i-radius)*(i-radius)+(g-radius*3)*(g-radius*3) == radius*radius) ) {
				line += "0";
			} else {
				line += " ";
			}
		}
		if(!(line == "                     ")){
			cout << line << endl;
		}
		line = "";
	}
	for (int i = 0; i < radius * 2 + 1; ++i) {
		for (int g = 0; g < radius * 4 + 1; ++g) {
			if (g == i || i + g == radius*4) {
				line += "0";
			} else {
				line += " ";
			}
		}
		cout << line << endl;
		line = "";
	}
}

int main() {
	ExerciseTwoTaskOne();
	ExerciseTwoTaskTwo();
	ExerciseTwoTaskTree();
	cout << endl;
	ExerciseTreeTaskOne();
	ExerciseTreeTaskTwo();
	cout << endl;
	ExerciseFourTaskOne();
	ExerciseFourTaskTwo();
}
