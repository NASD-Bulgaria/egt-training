//============================================================================
// Name        : Asteriks.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
using namespace std;

string strToLower(const string &);
string strToUpper(const string &);
string split(int, const string &, const string &);
int countForbbiden(const string &, const string &);
string asteriks(const string &); // edna zvezda po malko

void canOpenfile(const fstream &);

int main() {
	string str = "";
	string strLine = "";
	fstream inFile( "input.txt", ios::in);

	canOpenfile(inFile);

	while(getline(inFile, strLine)){
		str = str.append(strLine);
		str = str.append("\n");
	}

//	cout << str;

	string delimiter = " .,!?–\n";
	string newString;
	unsigned int position = 0;

	while ( position < str.length()) {
		newString = split(position, str, delimiter);
		if (newString.compare("") != 0) {
			if (isupper(newString[0])) {
				str.replace(position+1,newString.length()-1, asteriks(newString));
			}
		}
		position += (newString.length() + 1);
	}

	inFile.close();

//	cout << str << endl;

	fstream outFile( "output.txt", ios::out);

	canOpenfile(outFile);

	outFile << str;

	outFile.close();

	return 0;
}

string strToLower(const string &str){
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

string strToUpper(const string &str){
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

string split(int startPoint, const string &str, const string &find){
	unsigned int nextPoint = str.find_first_of(find, startPoint);
	string newStr = str.substr(startPoint, nextPoint-startPoint);

	return newStr;
}

int countForbbiden(const string &temp, const string &delimiter){
	string newString;
	unsigned int position = 0;
	int count = 0;

	while ( position < temp.length()) {
		newString = split(position, temp, delimiter);
		if (newString.compare("") != 0) {
			count++;
		}
		position += (newString.length() + 1);
	}
	return count;
}

string asteriks(const string &str){
	string newStr;
	for (unsigned int i = 0; i < str.length()-1; ++i) {   // edna zvezda po malko
		newStr.append("*");
	}
	return newStr;
}

void canOpenfile(const fstream& file) {
	 if ( !file ){
		 cerr << "File could not be opened." << endl;
		 exit( EXIT_FAILURE );
	 }
}
