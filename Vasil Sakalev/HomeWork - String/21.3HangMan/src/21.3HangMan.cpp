//============================================================================
// Name        : 3HangMan.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
	string leftHand = "/";
	string rightHand = "\\";
	string head = "O";
	string body = "|";
	string leftFoot = "/";
	string rightFoot = "\\";

	cout << setw(2) << head << endl;
	cout << left << setw(0) << leftHand << body << rightHand << endl;
	cout << left << setw(2) << leftFoot << setw(1) << rightFoot << endl;

	char ch;

	string word = "vasko";
	char guessedWord[word.length()];

	cout << "The word you have to gues is: ";
	for (unsigned int i = 0; i < word.length(); i++) {
		guessedWord[i] = '_';
		cout << "_ ";
	}
	bool check = false;
	int count = 0;
	int count2 = 0;
	for (unsigned i = 0; i < 6 + word.length(); i++) {
		cout << "Gues a char of word: ";
		cin >> ch;
		for (unsigned j = 0; j < word.length(); j++) {
			if (ch == word[j]) {
				guessedWord[j] = ch;
				check = true;
				count2++;
			}
		}

		if (check == true) {

			for (unsigned k = 0; k < word.length(); k++) {
				cout << guessedWord[k] << " ";
			}
		} else {
			count++;
			cerr << "YOU ARE WRONG !!! " << endl;
			switch (count) {
			case 1:
				cout << right << setw(2) << head << endl;
				cout << left << setw(0) << leftHand << body << rightHand
						<< endl;
				cout << right << setw(3) << rightFoot << endl;
				break;
			case 2:
				cout << right << setw(2) << head << endl;
				cout << left << setw(0) << leftHand << body << rightHand
						<< endl;
				cout << endl;
				break;
			case 3:
				cout << right << setw(2) << head << endl;
				cout << right << setw(2) << body << rightHand << endl;
				cout << endl;
				break;
			case 4:
				cout << right << setw(2) << head << endl;
				cout << right << setw(3) << rightHand << endl;
				cout << endl;

				break;
			case 5:
				cout << right << setw(2) << head << endl;
				cout << endl;
				cout << endl;
				break;
			case 6:
				cerr << "you are dead !!!";
				system("PAUSE");
				break;
			default:
				break;

			}
		}

		check = false;
		if (count2 == word.length()) {
			cout << endl;
			cerr << "YOU WIN !!! ";
			system("PAUSE");
			break;
		}
	}

	return 0;
}
