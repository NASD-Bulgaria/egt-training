//============================================================================
// Name        : String-Ex3.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int maxTries = 5;

int letterFill(char guess, string secretword, string &guessword){
	int i;
		int matches = 0;
		int len = secretword.length();
		for (i = 0; i < len; i++) {
	// Did we already match this letter in a previous guess?
			if (guess == guessword[i])
				return 0;
	// Is the guess in the secret word?
			if (guess == secretword[i]) {
				guessword[i] = guess;
				matches++;
			}
		}
		return matches;
}

int main() {

	string name;
	char ch;
	int numWrong;
	string word;
	string words[] = {"Sofia", "Burgas", "tomato", "vegetables", "meat", "dinner", "breakfast", "football", "sports",
	"Varna", "Pleven", "fitness", "mother", "father", "baby", "core", "computer", "programming", "code"};

	srand(time(NULL));
	int n = rand() % 19;
	word = words[n];
	string hidden(word.length(), '*');

	cout<<"Hello! Welcome in Hangman game!"<< endl;
	cout << "Guess wich is the hidden word.."<< endl <<"Each letter is represented by \"*\"."<< endl;
	cout << "In each try you have to type only a one single letter"<< endl;
	cout << "You have a "<<maxTries<< " times to guess the hidden word."<< endl<< endl<< endl;


	return 0;
}
