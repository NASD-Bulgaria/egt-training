//============================================================================
// Name        : TestDelete.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream inFile( "test.txt", ios::in );
	if(!inFile)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}
	ofstream endFile("delTest.txt", ios::out);
	if(!endFile)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}
	string sentence;

	char d;
	string word = "";
	vector <string> words;

	while(!inFile.eof())
	{
		getline(inFile, sentence);
		while(sentence.length() != 0)
		{
			word = "";
			d = tolower(sentence[0]);
			while (isdigit(d) || isalpha(d))
			{
				word += d;
				sentence = sentence.erase(0, 1);
				d = tolower(sentence[0]);

			}
			if (word != "")
			{
				words.push_back(word);
			}
			sentence = sentence.erase(0, 1);
		}
	}

	for(int i = 0; i < words.size(); i++)
	{
		if(words[i].at(0) == 't' && words[i].at(1) == 'e' && words[i].at(2) == 's' && words[i].at(3) == 't')
		{
			continue;
		}
		endFile << words[i] << " ";
	}
	return 0;
}
