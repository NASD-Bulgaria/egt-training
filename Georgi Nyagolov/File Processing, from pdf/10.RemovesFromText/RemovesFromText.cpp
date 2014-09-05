//============================================================================
// Name        : RemovesFromText.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

string strToLower(string str){
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

string strToUpper(string str){
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

string split(int startPoint, string str, string find){
	unsigned int nextPoint = str.find_first_of(find, startPoint);
	string newStr = str.substr(startPoint, nextPoint-startPoint);

	return newStr;
}

int countForbbiden(string temp){
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

string asteriks(string str){
	string newStr;
	for (unsigned int i = 0; i < str.length(); ++i) {
		newStr.append("*");
	}
	return newStr;
}

int main() {
	string str = "";
	string temp = "";
	string tempStr;
	string newString;
	unsigned int position = 0;

	fstream inFile1("Text.txt", ios::out|ios::in);
	ifstream inFile2("Forbbiden.txt", ios::in);

	if ( !inFile1 ){
		cerr << "File could not be opened Text.txt" << endl;
		exit( 1 );
	} // end if

	if ( !inFile2 ){
		cerr << "File could not be opened NewText.txt" << endl;
		exit( 1 );
	} // end if

	while(getline(inFile1, tempStr)){
		str.append(tempStr);
		str.append("\n");
	}

	while(getline(inFile2, tempStr)){
		temp.append(tempStr);
		temp.append("\n");
	}

	cout << str << endl;
	cout << temp << endl;

	tempStr = str;

	int count = countForbbiden(temp);
	string forbbiden[count];

	for (int i = 0; i < count; ++i) {
			newString = split(position, temp, " ,.");
			if (newString != "") {
				forbbiden[i] = newString;
			}
			position += (newString.length()+2);
	}

	for (int i = 0; i < count; ++i) {
		position = str.find(forbbiden[i]);
		while ( position != string::npos ) {
			str.replace(position, forbbiden[i].length(), "");
			position = str.find( forbbiden[i], position + 1 );
		}
	}

	inFile1.clear();
	inFile1.seekg(0);

	inFile1 << tempStr << endl << str;

	return 0;
}
