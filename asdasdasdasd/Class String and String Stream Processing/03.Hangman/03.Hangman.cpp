#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

int toupper(int c);


int updateWord(string& tempWord, string realWord, string guessedChar)
 {
       string previousWord = tempWord;

       for(int i=0;i<=realWord.length()-1;i++)
       {
            if (realWord.substr(i,1)==guessedChar)
            {
                tempWord = tempWord.substr(0,i)+ guessedChar + tempWord.substr(i+1,tempWord.length());
            }
       }

        if(previousWord == tempWord)
        {
            cout << "Sorry, there are none of that letter in the puzzle.\n";
        }
        else
        {
            cout << "Some letters were found and now your puzzle has been updated.\n";
        }
}

int main()
{
    string dictionary[6] = { "monkey", "rabbit", "horse", "hippopotamus", "rattlesnake", "scorpion" };
    string guess, playagain;

    cout << "------------------ Welcome to Hangman! ------------------\n";
    cout << "\nThe words category is \"Animals\"\n";

  do
  {

    srand(time(0));
    int wordNumber = rand() % 6;

    string word = dictionary[wordNumber];
    string tempWord (word.length(),'_');

    while(tempWord != word)
    {
        cout << "\nThe puzzle is " << tempWord << " (" << tempWord.length() << " characters), guess a letter.\n";

        guess = getch();

        updateWord(tempWord, word, guess);
    }

    cout << "You win! The word was: " << word << "\n";

    do
    {
        cout << "\nWould you like to play again? (Y/N).\n";
        playagain = getch();
    }
    while(playagain!="y" && playagain !="n"  && playagain !="Y"  && playagain !="N");

  }
  while(playagain=="y" || playagain=="Y");

    system("PAUSE");
    return 0;
}
