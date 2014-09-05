//============================================================================
// Name        : File-PhoneNums.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

void allCombinations(string, string);
bool correctNum(string);
bool isDigit(string);

int main() {

	string phoneNum;
	string buttons[] = { " ", ".", "!?", "abc", "def", "ghi", "jkl", "mno",
			"poqrs", "tuv", "wxyz" };

	cout << "Enter a phone number" << endl;
	cin >> phoneNum;

	correctNum(phoneNum);

	allCombinations(phoneNum);

	ofstream outNumbers("numbers.txt", ios::out);

	if(!outNumbers){
		cerr<<"File could not be created."<< endl;
		exit(1);
	}


	return 0;
}
void allCombinations(string str, string butt[]) {
	int index = str[];
	for (int digit1 = 0; digit1 < butt[index].length(); ++digit1) {
		for (int digit2 = 0; digit2 < butt[index+1].length(); ++digit2) {
			for (int digit3 = 0; digit3 < butt[index+2].length(); ++digit3) {
				for (int digit4 = 0; digit4 < butt[index+3].length(); ++digit4) {
					for (int digit5 = 0; digit5 < butt[index+4].length(); ++digit5) {
						for (int digit6 = 0; digit6 < butt[index+5].length(); ++digit6) {
							for (int digit7 = 0; digit7 < butt[index+6].length(); ++digit7) {

							}
						}
					}
				}
			}
		}
	}
}

bool correctNum(string str) {

	if (str.length() < 7 || !isDigit(str)) {
		cout << "Incorrect number! Please try again!" << endl;
		cin >> str;
	}
	return true;
}
bool isDigit(string str) {
	int countFalse = 0;
	for (unsigned int i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			countFalse++;
		}
	}
	if (countFalse > 0) {
		return false;
	}
	return true;
}
