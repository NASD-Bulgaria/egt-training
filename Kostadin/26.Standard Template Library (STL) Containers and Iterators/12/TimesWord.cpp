//============================================================================
// Name        : TimesWord.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string sentence = "";
	cout << " enter sentence: ";
	getline(cin, sentence);
	char d;
	string word = "";
	string words[sentence.length() / 2 + 1];
	string copyOfSentence = sentence;
	int count = 0;
	while (sentence.length() != 0) {
		word = "";
		d = tolower(sentence[0]);
		while (isdigit(d) || isalpha(d)) {
			word += d;
			sentence = sentence.erase(0, 1);
			d = tolower(sentence[0]);
		}
		if (word != "") {
			words[count] = word;
			count++;
		}
		sentence = sentence.erase(0, 1);
	}
	map<string, int> mp;
	map<string, int>::iterator it;
	for(int i = 0; i < count; i++)
	{
		it = mp.find(words[i]);
		if(it == mp.end())
		{
			mp.insert(pair<string, int>(words[i], 1));
		}
		else
		{
			int count = it->second;
			count++;
			it->second = count;
		}

	}
	for(it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << " -> " << it->second<< endl;
	}
	return 0;
}
