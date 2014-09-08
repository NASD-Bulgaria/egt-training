//============================================================================
// Name        : core1-algorithm-7ma-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
using namespace std;

int main() {
	ifstream in("text-7ma.txt",ios::in);
	string words;
	vector<string>word;
	while(!in.eof())
	{
		getline(in,words);
	}
	int index=words.find_first_of(",.!?-");
	while(index<=words.length())
	{
		words.erase(index,1);
		index=words.find_first_of(",.!?-",index+1);
	}
	stringstream ss(words);

	do {
			string sub;
			ss >> sub;
			string oneByOne = sub;
			word.push_back(oneByOne);


		} while (ss);

	sort(word.begin(),word.end());
	ofstream out("text2-7ma.txt",ios::out);
	for(int i=0;i<word.size();i++)
	{
		out<<word[i]<<" ";
	}



	return 0;
}
