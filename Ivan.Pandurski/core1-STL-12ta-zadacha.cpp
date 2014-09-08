//============================================================================
// Name        : Examp_12.cpp
// Author      : RadoslavNikolov
// Version     :
// Copyright   : ThisIsTheTest
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
string toLower(string);

int main() {

	map<string, int>::iterator it;
	map<string, int> wordsCount;

	string str(
			"This is the TEXT. Text, text, text – THIS TEXT! Is this the text?");
	string s = toLower(str);
	int index = s.find_first_of(".,–!?");
	while (index <= s.length()) {
		s.erase(index, 1);
		index = s.find_first_of(".,!?–", index + 1);
	}
	istringstream iss(s);

	do {
		string sub;
		iss >> sub;
		string word = sub;
		it = wordsCount.find(word);
		if (it == wordsCount.end()) {

			wordsCount.insert(pair<string, int>(word, 1));
		} else {

			int count = it->second;

			count++;
			it->second = count;
		}
	} while (iss);
	for (map<string, int>::const_iterator iter = wordsCount.begin();
			iter != wordsCount.end(); ++iter)
		cout << iter->first << '\t' << iter->second << '\n';

	return 0;
}

string toLower(string str) {
	string temp = str;
	for (unsigned i = 0; i < temp.length(); i++)
		temp[i] = tolower(temp[i]);
	return temp;
}

