//============================================================================
// Name        : File-Ex9.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Write a program that compares two text files line by line and prints the number of lines that
//are different.

#include <iostream>
#include<iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <string>
using namespace std;

int main() {

	ifstream inText1("text1.txt", ios::in);

	if (!inText1) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	string str1;
	string str2;
	vector<string> text1;
	vector<string> text2;

	while (getline(inText1, str1)) {
		text1.push_back(str1);
	}
	inText1.close();

	ifstream inText2("text2.txt", ios::in);

	if (!inText2) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	while(getline(inText2, str2)){
		text2.push_back(str2);
	}
	inText2.close();

	int countDifferent = 0;

	if(text1.size() > text2.size()){
		swap(text1, text2);
	}

	for (unsigned int i = 0; i < text1.size(); ++i) {
		if(text1[i] != text2[i]){
			countDifferent++;
		}
	}

	if (countDifferent == 1){
		cout << "There is "<< countDifferent << " different line in the two files."<< endl;
	} else {
	cout << "There are "<< countDifferent << " different lines in the two files."<< endl;
	}

	return 0;
}
