//4. Write a program that inputs a string and prints the
//string backward. Convert all uppercase characters to
//lowercase and all lowercase characters to uppercase.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string words;
	cout << "Write a sentence: ";
	getline(cin, words);

	char ch;


	for (int i = words.length() - 1; i > -1; i--) {
		ch= words[i];
		if (isupper(ch)) {

			ch = tolower(ch);
			cout << ch;
		} else {
			ch = toupper(ch);
			cout << ch;
		}
	}
	return 0;
}
