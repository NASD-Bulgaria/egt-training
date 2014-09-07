//============================================================================
// Name        : CountWords.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <set>
#include <map>
using namespace std;

string strToLower(const string &);
string strToUpper(const string &);
string split(int, const string &, const string &);
int countForbbiden(const string &, const string &);
string asteriks(const string &);

int main() {
	string str = "This is the TEXT. Text, text, text – THIS TEXT! Is this the text?";
	string delimiter = " .,!?–";
	string newString;
	unsigned int position = 0;
	multiset<string> strMultiset;
	map<string, int> strMap;

	str = strToLower(str);

	while ( position < str.length()) {
		newString = split(position, str, delimiter);
		if (newString.compare("") != 0) {
			strMultiset.insert(newString);
		}
		position += (newString.length() + 1);
	}

	for (multiset<string>::iterator it = strMultiset.begin(); it != strMultiset.end(); ++it) {
		strMap.insert( map<string, int>::value_type( *it, strMultiset.count(*it)));
	}

	for ( map<string, int>::const_iterator it = strMap.begin(); it != strMap.end(); ++it ){
		cout << it->first << "->" << it->second << '\n';
	}

	return 0;
}

string strToLower(const string &str){
	char letter;
	string newStr;
	for (unsigned int i = 0; i < str.length(); ++i) {
		letter = str.at(i);
		letter = tolower(letter);
		string temp(1, letter);
		newStr = newStr.append(temp);
	}
	return newStr;
}

string strToUpper(const string &str){
	char letter;
	string newStr;
	for (unsigned int i = 0; i < str.length(); ++i) {
		letter = str.at(i);
		letter = toupper(letter);
		string temp(1, letter);
		newStr = newStr.append(temp);
	}
	return newStr;
}

string split(int startPoint, const string &str, const string &find){
	unsigned int nextPoint = str.find_first_of(find, startPoint);
	string newStr = str.substr(startPoint, nextPoint-startPoint);

	return newStr;
}

int countForbbiden(const string &temp, const string &delimiter){
	string newString;
	unsigned int position = 0;
	int count = 0;

	while ( position < temp.length()) {
		newString = split(position, temp, delimiter);
		if (newString.compare("") != 0) {
			count++;
		}
		position += (newString.length() + 1);
	}
	return count;
}

string asteriks(const string &str){
	string newStr;
	for (unsigned int i = 0; i < str.length(); ++i) {
		newStr.append("*");
	}
	return newStr;
}
