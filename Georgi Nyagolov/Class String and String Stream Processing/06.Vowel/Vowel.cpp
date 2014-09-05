//============================================================================
// Name        : Vowel.cpp
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

string strToLower(string &str);
string strToUpper(string &str);
string split(int startPoint, string &str, string find);
int countForbbiden(string &temp);
string asteriks(string &str);

void display(string &, vector<string>);
int check(string &, string &);

int main() {
	string str = "ant, Alligator, Crocodile, Bear";
	string vowal = "aoueiy";
	string newStr = "";
	int counter[vowal.length()];

	str = strToLower(str);

	for (size_t i = 0; i < vowal.length(); ++i) {
		counter[i] = 0;
	}

	int position = str.find_first_of(vowal);

	while(position != string::npos){

		newStr.assign(str, position, 1);

		if (newStr == "a") {
			counter[0]++;
		} else {
			if (newStr == "o") {
				counter[1]++;
			} else {
				if (newStr == "u") {
					counter[2]++;
				} else {
					if (newStr == "e") {
						counter[3]++;
					} else {
						if (newStr == "i") {
							counter[4]++;
						} else {
							if (newStr == "y") {
								counter[5]++;
							}
						}
					}
				}
			}
		}

		position = str.find_first_of(vowal, position +1);
	}

	cout << vowal << endl;
	for (size_t i = 0; i < vowal.length(); ++i) {
		cout << counter[i];
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



