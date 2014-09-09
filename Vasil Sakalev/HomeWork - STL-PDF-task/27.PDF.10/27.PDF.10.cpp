//============================================================================
// Name        : 10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

int main() {
	ifstream readNames("text.txt", ios::in);
	if (!readNames) {
		cerr << "The file coud not be opened !!! ";
		exit(1);
	}

	multimap<string, string, greater<string> > studentNames;
	string word;

	while (!readNames.eof()) {
		getline(readNames, word);
//		cout << word << endl;
		for (unsigned i = 0; i < word.size(); i++) {
			if (isdigit(word.at(i))) {
				string name = word.substr(0,i);
				string grade = word.substr(i,word.size() - i);
			studentNames.insert(pair<string,string>(grade , name));break;
			}
		}
	}
	multimap<string,string>::iterator it = studentNames.begin();
	for (int i = 0 ; i < 10 ; i++){
		cout << it->second << it->first << endl;
		it++;
	}
	return 0;
}
