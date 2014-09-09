//============================================================================
// Name        : TextCode.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <stdio.h>
//#include <string.h>
using namespace std;

void codeText(string &);
void decodeText(string &);

int main() {

	string str = "";
	string tempStr;

	ifstream inFile("message.txt", ios::in);
	ofstream outFile("encoded-message.txt", ios::out);

	if (!inFile) {
		cerr << "File could not be opened message.txt" << endl;
		exit(1);
	} // end if

	if (!outFile) {
		cerr << "File could not be opened encoded-message.txt" << endl;
		exit(1);
	} // end if

	while(getline(inFile, tempStr)){
		str = str.append(tempStr);
	}

	inFile.close();

	codeText(str);
	cout << "Code string: " << str << endl;
	outFile << str;
	outFile.close();
	str = "";


//	decode from file
	ifstream newInFile("encoded-message.txt", ios::in);

	if (!newInFile) {
		cerr << "File could not be opened encoded-message.txt" << endl;
		exit(1);
	} // end if

	while(getline(newInFile, tempStr)){
		str = str.append(tempStr);
	}

	decodeText(str);
	cout << "Decode string: " << str << endl;

	return 0;
}

void codeText(string& str) {
	char matrix[6][6];

	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			matrix[i][j] = ' ';
		}
	}

	size_t count = 0;
	for (int j = 0; j < 6; ++j) {
		for (int i = 0; i < 6; ++i) {
			matrix[i][j] = str[count++];
			if (count == str.length()) {
				break;
			}
		}
		if (count == str.length()) {
			break;
		}
	}

	str = "";
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			str.append(1u,matrix[i][j]);
		}
	}
}

void decodeText(string& str) {
	char matrix[6][6];

	size_t count = 0;
	for (int j = 0; j < 6; ++j) {
		for (int i = 0; i < 6; ++i) {
			matrix[i][j] = str[count++];
			if (count == str.length()) {
				break;
			}
		}
		if (count == str.length()) {
			break;
		}
	}

	str = "";
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			str.append(1u,matrix[i][j]);
		}
	}

}
