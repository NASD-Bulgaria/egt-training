//============================================================================
// Name        : File-Ex5.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Write a program that replaces all occurrences of the substring "start" with the substring
//"finish" in a text file.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {

	ifstream inText("text.txt", ios::in);
	ofstream outResultText("resultText.txt", ios::out);

	if (!inText && outResultText) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	string text;
	string start = "start";
	string finish = "finish";

	unsigned int position = 0;

	while (inText >> text) {
		position = text.find("start");

		while (position != string::npos) {
			text.replace(position, 5, "finish");
			position = text.find("start", position + 1);
		}
		outResultText << text<< " ";
	}


	return 0;
}
