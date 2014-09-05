//9. Write a program that reads a series of strings and
//prints only those strings beginning with the letter “b”.

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
	for (unsigned i = 0 ; i < words.size() ; i ++){
		char ch = words[i].at(0);
		if (ch == 'b' || ch == 'B'){
			cout << words[i] << " ";
		}
	}
	return 0;
}
