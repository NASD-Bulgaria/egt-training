//============================================================================
// Name        : Hangman.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand( time( 0 ) );
	string words[] = {"car", "boat", "plane", "ship", "shark", "eclipse","dog", "array", "cards", "hangman"};
	int j = rand() % 10;
	string wordToGuess = words[j];
	string secretWord = "";
	char ast = '*';
	int counter = 0;
	for(int i = 0; i < wordToGuess.length(); i++)
	{
		secretWord += ast;
		counter++;
	}

	cout << secretWord << endl;

	int lives = 5;

	while(true)
	{
		bool guessed = 0;
		char let;
		cout << "Enter a letter: ";
		cin >> let;

		for(int i = 0; i < wordToGuess.length(); i++)
		{
			if(wordToGuess.at(i) == let)
			{
				secretWord[i] = let;
				counter--;
				guessed = 1;
			}
		}
		if(guessed == 0)
		{
			cout<<"Life down!"<<endl;
			lives--;
			cout << "Lifes left "<< lives<<endl;
			cout << secretWord << endl;
		}
		if(guessed == 1)
		{
			cout << secretWord << endl;
		}
		if(lives == 0)
		{
			cout<<"You lost!"<<endl;
			cout << "The word was: "<< wordToGuess<<endl;
			break;
		}
		if(counter == 0)
		{
			cout<<"You win!"<<endl;
			break;
		}
	}
	return 0;
}
