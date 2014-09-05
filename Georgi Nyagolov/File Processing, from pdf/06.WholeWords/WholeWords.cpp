//============================================================================
// Name        : StartFinish.cpp
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

string strToLower(string str);
string strToUpper(string str);
string split(int startPoint, string str, string find);
int countForbbiden(string temp);
string asteriks(string str);

int main() {

	string str = "";
	string tempStr = "";
	string temp = "start";
	string newTemp = "finish";
	string newString;
	unsigned int position = 0;


	ifstream inFile("Start.txt", ios::in);
	ofstream outFile("Finish.txt", ios::out);

	if ( !inFile ){
		cerr << "File could not be opened Text.txt" << endl;
		exit( 1 );
	} // end if

	if ( !outFile ){
		cerr << "File could not be opened NewText.txt" << endl;
		exit( 1 );
	} // end if

	while(getline(inFile, tempStr)){
		str.append(tempStr);
		str.append("\n");
	}
//	cout << str << endl;

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
			if (str.compare(position-1,1," ")==0 && (str.compare(position+temp.length(),1," ")==0 || str.compare(position+temp.length(),1,",")==0 || str.compare(position+temp.length(),1,".")==0)) {
				str.replace(position, forbbiden[i].length(), newTemp); //asteriks(forbbiden[i])

			}

			position = str.find( forbbiden[i], position + 1 );
		}
	}

	outFile << str << endl;

	return 0;
}

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
