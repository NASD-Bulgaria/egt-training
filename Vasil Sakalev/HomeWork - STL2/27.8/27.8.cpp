//8. There are two text files. Display all words that
//present only in one of the files.
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

int main() {

	ifstream readText("text.txt", ios::in);
	ifstream readText2("text2.txt", ios::in);
	ofstream writeText("result.txt", ios::out);

	if (!readText) {
		cerr << "The file coud not be opened !!! ";
		exit(1);
	}
	string word;
	string secondWord;
	int count = 0;

	multimap<int, string> uniqueWords;
	while (readText >> word) {
		while (readText2 >> secondWord) {
			if (word == secondWord) {
				count++;
			}
		}
		uniqueWords.insert(pair<int, string>(count, word));
		count = 0;
		readText2.clear();
		readText2.seekg(0);
	}

	readText.clear();
	readText.seekg(0);

	while (readText2 >> secondWord) {
		while (readText >> word) {
			if (secondWord == word) {
				count++;
			}
		}
		uniqueWords.insert(pair<int, string>(count, secondWord));
		count = 0;
		readText.clear();
		readText.seekg(0);
	}
	multimap<int, string>::iterator it;
	for (it = uniqueWords.begin(); it != uniqueWords.end(); it++) {
		if (it->first == 0) {
			writeText << it->second << " ";
		}
	}
	return 0;
}
