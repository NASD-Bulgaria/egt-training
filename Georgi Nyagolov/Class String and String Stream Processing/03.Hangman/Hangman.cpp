//============================================================================
// Name        : Hangman.cpp
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
using namespace std;

string strToLower(string &str);
string strToUpper(string &str);
string split(int startPoint, string &str, string find);
int countForbbiden(string &temp);
string asteriks(string &str);

void display(string &, vector<string>);
int check(string &, string &);

int main() {
	string find = "Hangman";
	find = strToLower(find);
	string newLetter = "";
	int endOfGame = 10;
	int win;

	win = find.length();

	vector <string> letter;
	for (size_t i = 0; i < find.length(); ++i) {
		letter.push_back("");
	}

	cout << "Enter letter: ";
	cin >> newLetter;

	while(true){
		if (check(find, newLetter) != -1) {
			letter[check(find, newLetter)] = newLetter;
			win--;
		} else {
			endOfGame--;
			cout << endOfGame << endl;
		}
		if (endOfGame == 0) {
			cout << "Game over!" << endl;
			break;
		}
		if (win == 0) {
			cout << "You win!" << endl;
			break;
		}
		display(find, letter);
		cout << "Enter letter: ";
		cin >> newLetter;
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

void display(string &str, vector<string> letter){
	for (size_t i = 0; i < letter.size(); ++i) {
		if (str.find(letter[i]) == i) {
			cout << letter[i] << " ";
		} else {
			cout << "_" << " ";
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

