//============================================================================
// Name        : File-Ex11.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str1;
	string str2;
	vector<string> words;
	vector<string> test;
	vector<string> result;

	ifstream inWords("words.txt", ios::in);

	if (!inWords) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	while (inWords >> str1) {
		words.push_back(str1);
	}
	inWords.close();

	ifstream inTest("test.txt", ios::in);

	if (!inTest) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	while (inTest >> str2) {
		test.push_back(str2);
	}
	inTest.close();

	for (unsigned int i = 0; i < words.size(); ++i) {
		for (unsigned int j = 0; j < test.size(); ++j) {
			if (words[i] == test[j]) {
				result.push_back(words[i]);
			}
		}

	}

	sort(result.rbegin(), result.rend());

	ofstream outResult("result.txt", ios::out);
		if (!outResult) {
			cerr << "File could not be opened" << endl;
			exit(1);
		}

	for (unsigned int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
		outResult << result[i]<<" ";
	}

	outResult.close();

	return 0;
}
