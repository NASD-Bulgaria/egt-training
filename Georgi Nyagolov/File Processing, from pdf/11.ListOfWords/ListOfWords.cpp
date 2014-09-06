//============================================================================
// Name        : ListOfWords.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
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
	int min = 0;

	ifstream inFile1("test.txt", ios::in);
	ifstream inFile2("words.txt", ios::in);
	ofstream outFile("result.txt", ios::out);

	if ( !inFile1 ){
		cerr << "File could not be opened test.txt" << endl;
		exit( 1 );
	} // end if

	if ( !inFile2 ){
		cerr << "File could not be opened words.txt" << endl;
		exit( 1 );
	} // end if

	if ( !outFile ){
		cerr << "File could not be opened result.txt" << endl;
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

	tempStr = str;

	int count = countForbbiden(temp);
	string forbbiden[count];
	int counter[count];

	for (int i = 0; i < count; ++i) {
		counter[i] = 0;
	}

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
			if (str.find(forbbiden[i], position) != -1) {
				counter[i]++;
			}
			position = str.find( forbbiden[i], position + 1 );
		}
	}

	min=counter[0];
	for (int i = 1; i < count-1; ++i) {
		for (int j = i+1; j < count; ++j) {
			if (min < counter[i]) {
				min = counter[i];
				counter[i] = counter[i+1];
				counter[i+1] = min;
				forbbiden[i].swap(forbbiden[i+1]);
			}
		}
	}

	for (int i = 0; i < count; ++i) {
		outFile << setw(12) << forbbiden[i] << setw(3) << counter[i] << endl;
		cout << setw(12) << forbbiden[i] << setw(3) << counter[i] << endl;
	}

	return 0;
}
