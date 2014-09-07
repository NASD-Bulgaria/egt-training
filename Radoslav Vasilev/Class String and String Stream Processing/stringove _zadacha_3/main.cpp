#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;
string checkAlphas(string original);
bool letterChecker(string, char);
void secredWordChecker(const string, string &, char, int &);
void Gamedisplay(const int);
int main()
{

    string secredWord="pesho";
    string userSecredWord=checkAlphas(secredWord);
    int trysCount= 5;
    char guessLetter;

    while(trysCount != 0)
    {

        cout<<userSecredWord<<endl;
        cout<<"Please Enter Letter"<<endl;
        cin>>guessLetter;

        if(letterChecker(userSecredWord,guessLetter))
        {
            trysCount--;

        }
        else
        {

            secredWordChecker(secredWord,userSecredWord,guessLetter,trysCount);

        }
        if(secredWord == userSecredWord)
        {
            cout<<"You won !"<<endl;
          break;
        }
        else
        {
            if(trysCount ==0)
            {
                cout<<"You lose !"<<endl;
            }
        }

    }

    cout<<userSecredWord<<endl;
    return 0;
}

string checkAlphas(string original)
{
    string alphaCheker=original;
    for(size_t i =1; i <original.length()-1;i++)
    {
        alphaCheker.replace(i,1,"*");
    }
    return alphaCheker;
}

bool letterChecker(string word, char letter)
{
    char *cstr = new char[word.length() + 1];
    strcpy(cstr, word.c_str());

    bool check = false;

    for(size_t i = 0;i< word.length();i++)
    {

        if(cstr[i]==letter)
        {
            check = true;
            break;
        }
    }
    return check;
}

void secredWordChecker(const string word, string &userSecredWord, char letter, int &trysCount)
{
   stringstream ss;
   string temp;
   ss<<letter;
   ss>>temp;
   bool flagy= false;
   size_t found = 0;
   while(found != word.npos)
   {
       found = word.find(letter,found+1);

           if(found == word.npos)
           {
               if(!flagy)
               {
                    trysCount--;
                    cout<<"You have "<< trysCount<<" trys !"<<endl;
               }
           }

           else
           {

               userSecredWord.replace(found,1,temp);
               flagy=true;
           }


   }
}

