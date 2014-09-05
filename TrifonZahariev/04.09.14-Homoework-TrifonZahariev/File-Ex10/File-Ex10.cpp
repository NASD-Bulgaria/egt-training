//============================================================================
// Name        : File-Ex10.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Write a program that removes from a text file all words that are contained by given another
//text file. Handle all possible exceptions in your methods.

#include <iostream>
#include<iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <string>
using namespace std;

int main() {

	vector<string> text1;
	vector<string> text2;
	string str1;
	string str2;

	ifstream inText1("text1.txt", ios::in);

	if (!inText1) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	while (inText1 >> str1) {
		text1.push_back(str1);
	}
	inText1.close();

	ifstream inText2("text2.txt", ios::in);

	if (!inText2) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	while (inText2 >> str2) {
		text2.push_back(str2);
	}
	inText2.close();

	string currWord;

	if (text1.size() > text2.size()) {
		swap(text2, text1);
	}

	for (unsigned int i = 0; i < text1.size(); ++i) {
		currWord = text1[i];
		for (unsigned int j = 0; j < text2.size(); ++j) {
			if (currWord == text2[j]) {
//				text2.erase(text2.begin() + j);
				text2[j] = "";
//			} else {
//				text2.push_back(currWord);
//			}
			}
		}
	}

//	text2.find(text2.begin(), text2.end(), "");

	for (unsigned int i = 0; i < text2.size(); ++i) {
//		if(text2[i] == ""){
//			text2.erase(text2.begin(), "");
//		}
		cout << text2[i] << endl;
	}

	return 0;
}
