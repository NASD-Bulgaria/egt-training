//============================================================================
// Name        : file10DeleteWordsByFile.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	fstream text("textToDelete.txt", ios::in);
	fstream remove("checkText.txt", ios::in);
	fstream result("resultText.txt", ios::out );


	if (!text) {
		cerr << "the file coud not be opened !!!";
	}
	string words;
	string newText;
	while (text >> words) {
		newText.append(words + " ");

	}
	text.clear();
	text.seekg(0);

	string newText2;
	for (unsigned i = 0; i < newText.length(); i++) {
		char ch = newText.at(i);
		if (isupper(ch)) {
			ch = tolower(ch);
		}
		string s(1, ch);
		newText2 = newText2.append(s);
	}

	string word;
	string wordCheck;
	vector<string> textToRemove;
	while (text >> word) {

		textToRemove.push_back(word);

	}
	text.clear();
	text.seekg(0);
	while (remove >> wordCheck) {
		for (unsigned i = 0; i < textToRemove.size(); i++) {
			if (wordCheck == textToRemove[i]) {
				textToRemove.erase(textToRemove.begin() + i);
			}
		}
	}
	remove.clear();
	remove.seekg(0);

	for (unsigned i = 0; i < textToRemove.size(); i++) {

				cout<< textToRemove[i] << " " ;
				result << textToRemove[i]<< " ";
	}

	return 0;
}
