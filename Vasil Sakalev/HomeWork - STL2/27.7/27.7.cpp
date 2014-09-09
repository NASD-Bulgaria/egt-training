//7. Sort all words in a text file. Write the result in other
//text file.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
using namespace std;

int main() {

	ifstream readText("text.txt", ios::in);
	ofstream writeText("result.txt", ios::out);
	if (!readText) {
		cerr << "The file coud not be opened !!! ";
		exit(1);
	}

	multiset<string> sortedWords;

	string word;
	while (readText >> word) {
		sortedWords.insert(word);
	}
	multiset<string>::iterator it;
	for (it = sortedWords.begin(); it != sortedWords.end(); it++) {
		writeText << *it << " ";
	}

	return 0;
}
