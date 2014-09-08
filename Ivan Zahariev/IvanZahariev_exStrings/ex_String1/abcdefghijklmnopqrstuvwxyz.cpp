//============================================================================
// Name        : abcdefghijklmnopqrstuvwxyz.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int numberChar = 0;

string strToLower(string &str);
string strToUpper(string &str);
string split(int startPoint, string &str, string find);
int countForbbiden(string &temp);
string asteriks(string &str);

void display(int, int, string &);
int check(string &, string &);



int main() {
	string str = "abcdefghijklmnopqrstuvwxyzz";
	int j = str.length()/2;

	for (size_t i = 1; i < str.length(); i=i+2, j--) {
		display(i, j, str);
	}

	return 0;
}


int check(string &str, string &letter){
	int number = str.find(letter);

	if (number != -1) {
		str.replace(number, 1, letter);
		return number;
	} else {
		return number;
	}

}

void display(int i, int j, string &str){
	for (int printJ = j; printJ > 0; --printJ) {
		cout << " ";
	}
	for (int printChar = i; printChar > 0; --printChar) {
		cout << str[numberChar];
		numberChar++;
		if (numberChar >= str.length()) {
			numberChar = 0;
		}
	}
	cout << endl;
}

string strToLower(string &str){
	char letter;
	string newStr;
	for (unsigned int i = 0; i < str.length(); ++i) {
		letter = str.at(i);
		letter = tolower(letter);
		string temp(1, letter);
		newStr = newStr.append(temp);
	}
	return newStr;
}

string strToUpper(string &str){
	char letter;
	string newStr;
	for (unsigned int i = 0; i < str.length(); ++i) {
		letter = str.at(i);
		letter = toupper(letter);
		string temp(1, letter);
		newStr = newStr.append(temp);
	}
	return newStr;
}

string split(int startPoint, string &str, string find){
	unsigned int nextPoint = str.find_first_of(find, startPoint);
	string newStr = str.substr(startPoint, nextPoint-startPoint);

	return newStr;
}

int countForbbiden(string &temp){
	string newString;
	unsigned int position = 0;
	int count = 0;

	while ( position < temp.length()) {
		newString = split(position, temp, " ,");
		if (newString.compare("") != 0) {
			count++;
		}
		position += (newString.length() + 1);
	}
	return count;
}

string asteriks(string &str){
	string newStr;
	for (unsigned int i = 0; i < str.length(); ++i) {
		newStr.append("*");
	}
	return newStr;
}



