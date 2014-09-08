#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
using namespace std;

int main() {
	ifstream in("text1-8ma.txt", ios::in);
	ifstream in2("text2-8ma.txt", ios::in);
	string words;
	string words2;
	vector<string> word;
	vector<string> word2;
	while (!in.eof()) {
		getline(in, words);
	}
	while (!in2.eof()) {
		getline(in2, words2);
	}
	int index = words.find_first_of(",.!?-");
	while (index <= words.length()) {
		words.erase(index, 1);
		index = words.find_first_of(",.!?-", index + 1);
	}
	int index2 = words2.find_first_of(",.!?-");
	while (index2 <= words2.length()) {
		words2.erase(index2, 1);
		index2 = words2.find_first_of(",.!?-", index2 + 1);
	}
	stringstream ss(words);
	stringstream ss2(words2);

	do {
		string sub;
		ss >> sub;
		string oneByOne = sub;
		word.push_back(oneByOne);

	} while (ss);
	do {
		string sub;
		ss2 >> sub;
		string oneByOne = sub;
		word2.push_back(oneByOne);

	} while (ss2);
	sort(word.begin(),word.end());
	sort(word2.begin(),word2.end());
	vector<string>::iterator it;
	vector<string>different(10);
	it=set_symmetric_difference(word.begin(),word.end(),word2.begin(),word2.end(),different.begin());
	for (it=different.begin(); it!=different.end(); ++it)
	    std::cout << ' ' << *it;
	  std::cout << '\n';


	return 0;
}
