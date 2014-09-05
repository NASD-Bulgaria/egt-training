//============================================================================
// Name        : File-Ex2.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Write a program that reads a text file containing a list of strings, sorts them and saves them
//to another text file.

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

#include <fstream>

void outputLine(string name) {
	cout << name << endl;
}

int main() {

	string name;

	vector<string> names;

	ifstream inNames("names.txt", ios::in);
	ofstream outNames("names1.txt", ios::out);

	if (!inNames) {
					cerr << "File could not be opened" << endl;
					exit(1);
	}

	while (inNames >> name) {
		names.push_back(name);

	}
	sort(names.begin(), names.end());


//
//		if (!outNames) {
//			cerr << "File could not be opened" << endl;
//			exit(1);
//		}

	for (unsigned int i = 0; i < names.size(); ++i) {

		outNames <<names[i]<< endl;
		cout << names[i]<< endl;
	}
//

//	ofstream outNames2("names2.txt", ios::out);
//
//	if (!outNames2) {
//		cerr << "File could not be opened" << endl;
//		exit(1);
//	}

	return 0;
}
