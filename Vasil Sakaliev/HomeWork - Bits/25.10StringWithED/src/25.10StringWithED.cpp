//10. Write a program that reads a series of strings and
//prints only those strings that end with the letters
//"ED"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> words;
	string word;

	for (int i = 0; i < 5; i++) {
		cout << "Write a word: ";
		cin >> word;
		words.push_back(word);
	}
	for (unsigned i = 0; i < words.size(); i++) {
		for (unsigned j = words[i].size() - 1; j > words[i].size() - 2; j--){
			char ch2 = words[i].at(j);
			char ch = words[i].at(j-1);

			if (ch == 'E' && ch2 == 'D'){
				cout << words[i] << " ";

			}
		}
	}
	return 0;
}
