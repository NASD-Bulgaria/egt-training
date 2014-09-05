//============================================================================
// Name        : String-Ex1.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

string encription(string, string);
string decription(string, string);

int main() {

	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string text;
	getline(cin, text);

	cout << "The text encripted is: " << encription(text, alphabet) << endl;

	string text2 = text;
	cout << "The text decripted is: "<< decription(text2, alphabet)<< endl;

	return 0;
}
string encription(string decripted, string letters) {

	string encripted;

	for (unsigned int i = 0; i < decripted.length(); ++i) {
		char ch = decripted.at(i);
		int index = letters.find(ch);
		if ((index + 13) > (int) letters.length()) {
			index = (index + 13) - letters.length();
		} else {
			index = index + 13;
		}
		encripted.append(string(1, letters.at(index)));

	}
	return decripted;
}

string decription(string encripted, string letters) {

	string decrypted;

	for (unsigned int i = 0; i < encripted.length(); i++) {
		char ch = encripted.at(i);
		int index = letters.find(ch);
		if ((index - 13) < 0) {
			index = letters.length() - (13 - index);
		} else {
			index = index - 13;
		}
		decrypted.append(string(1, letters.at(index)));
	}

	return encripted;
}
