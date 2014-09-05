//6. Write a program that counts the total number of
//vowels in a sentence. Output the frequency of each
//vowel.

#include <iostream>
#include <string>
using namespace std;
enum vowels {
	A = 1, E, U, I, O
};
int main() {
	string sentence;
	string sentenceTolower = "";

	cout << "Write a sentence: ";
	getline(cin, sentence);

	char ch;
	for (unsigned i = 0; i < sentence.length(); i++) {
		ch = sentence[i];
		if (isupper(ch)) {
			ch = toupper(ch);
			sentenceTolower += ch;
		} else {
			ch = toupper(ch);
			sentenceTolower += ch;
		}
	}
	int countA = 0;
	int countE = 0;
	int countU = 0;
	int countI = 0;
	int countO = 0;

	int position = sentenceTolower.find_first_of("A,E,U,I,O", 0);

	while (position != string::npos) {
		ch = sentenceTolower.at(position);

		switch (ch) {
		case 'A':
			countA++;
			break;
		case 'E':
			countE++;
			break;
		case 'U':
			countU++;
			break;
		case 'I':
			countI++;
			break;
		case 'O':
			countO++;
			break;
		default:
			break;
		}
		position = sentenceTolower.find_first_of("A,E,U,I,O", position + 1);
	}
	cout << "The frequency of \"A\" is: " << countA << endl;
	cout << "The frequency of \"E\" is: " << countE << endl;
	cout << "The frequency of \"U\" is: " << countU << endl;
	cout << "The frequency of \"I\" is: " << countI << endl;
	cout << "The frequency of \"O\" is: " << countO << endl;

	return 0;
}
