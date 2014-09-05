//============================================================================
// Name        : File-Ex8.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Write a program that deletes from a text file all words that start with the prefix "test". Words
//contain only the symbols 0...9, a...z, A…Z, _.


#include <iostream>
#include<iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main() {

	ifstream inText("text.txt", ios::in);

	if (!inText) {
			cerr << "File could not be opened" << endl;
			exit(1);
		}
	string str;
	string total;
	while(getline(inText, str)){
		total.append(str);
	}
	inText.close();
	string word = "";
	char ch;

	string copyTotal = total;
	vector<string>words;
	for (unsigned int i = 0; i < total.length(); ++i) {
		ch = total.at(i);
		if(isalpha(ch) || isdigit(ch)){
			word.append(string(1, ch));
		}
		if(((!isalpha(ch) && !isdigit(ch))|| (i == total.length() - 1))){
			int index = word.find("test");
			if(index == 0){
				words.push_back(word);
			}
			word = "";
		}

	}
	for (unsigned int i = 0; i < words.size(); ++i) {
		int index = copyTotal.find(words[i]);
		copyTotal.erase(index, words[i].length());
	}
	while(!isalpha(copyTotal[0])){
		copyTotal.erase(0,1);
	}
	ofstream outResultText("resultText.txt", ios::out);

	if(!outResultText){
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	outResultText<<copyTotal<< endl;

	return 0;
}
