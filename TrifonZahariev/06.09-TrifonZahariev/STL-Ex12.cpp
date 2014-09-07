//============================================================================
// Name        : STL-Ex12.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int findKey(vector<pair<string,int> > collection, string & key){
	for (unsigned int i = 0; i < collection.size(); ++i) {
		if (collection[i].first == key) {
			return i;
		}
	}
	return -1;
}

static bool sortPair(pair<string,int> first, pair<string,int>  second){
	return first.second < second.second;
}

int main() {
//	This is the TEXT. Text, text, text – THIS TEXT! Is this the text?
	string text;
	vector<string> textElements;

	cout << "Enter text: " << endl;
	getline(cin, text);

	char ch;
	string word = "";
	while (text.length() != 0) {
		word = "";
		ch = tolower(text[0]);
		while (isalpha(ch) || isdigit(ch)) {
			word += ch;
			text = text.erase(0, 1);
			ch = tolower(text[0]);
		}
		if (word != "") {
			textElements.push_back(word);
		}
		text = text.erase(0, 1);
	}
	vector<pair<string, int> > elements;

	for (unsigned int i = 0; i < textElements.size(); ++i) {
		int index = findKey(elements, textElements[i]);
		if (index == -1) {
			elements.push_back(pair<string, int>(textElements[i], 0));
			index = elements.size() - 1;
		}
		elements[index].second++;
	}
	sort(elements.begin(), elements.end(), sortPair);
	for (vector<pair<string, int> >::iterator it = elements.begin(); it < elements.end();
			it++) {
		cout << it->first << " -> " << it->second << "\n";
	}

	return 0;
}
