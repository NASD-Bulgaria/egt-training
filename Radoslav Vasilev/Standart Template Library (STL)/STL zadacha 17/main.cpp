#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

struct PieceInfo
{
    string piece;
    size_t startPosition;
};
vector<string> ExtractWords(string text);
PieceInfo FindUnknownWord(string text,size_t beginning);
PieceInfo FindPiece(string text,size_t beginning,vector<string> delimiters);
size_t FindFirstDelimiter(string text,size_t beginning,vector<string> delimiters);
vector<string> GetWordDelimiters();
void magicHappensHere(string&);
string ReplaceWord(string text,string word,string newWord);
int main()
{
    string str = "asd Write a program that asd removes asd from a given text all words that occur in it odd number of times. Write a program that removes from a given text all words that occur in it odd number of times.";
    cout<< str<<endl<<endl;
    magicHappensHere(str);
    cout<< str<<endl<<endl;
    return 0;
}
void magicHappensHere(string &str)
{
    vector <string> words;
    words = ExtractWords(str);
    string temp;
    map<string,int> countWords;
    unsigned int position;

    for(size_t i = 0; i < words.size();i++)
    {
        if(countWords.find(words[i])==countWords.end())
        {
          countWords.insert ( pair<string,int>(words[i],1) );
        }
        else
        {
            countWords.at(words[i])++;
        }
    }
    ;

    for(map<string,int>::iterator it = countWords.begin(); it != countWords.end() ;++it)
    {

        if(it->second % 2!= 0)
        {
            position= str.find(it->first);
          while(position != string::npos)
          {

              if(position != 0)
              {
                  temp= it->first;
                  str.erase(position-1,temp.length()+1);
                  position = str.find(it->first);
              }
              else
              {
                  temp= it->first;
                  str.erase(position,temp.length()+1);
                  position = str.find(it->first);
              }
          }
        }

    }
//    for(size_t i = 0; i < words.size();i++)
//    {
//        str.append(words[i]+" ");
//    }


}

vector<string> ExtractWords(string text)
{
    PieceInfo info;
    info.piece = "";
    info.startPosition = 0;
    size_t start = 0;
    vector<string> words;

    while(start != string::npos && start < text.length())
    {
      info = FindUnknownWord(text,start);

      if(info.piece.compare(string("")))
          words.push_back(info.piece);

      if(info.startPosition != string::npos)
          start = info.startPosition + info.piece.length();
      else
          start = string::npos;
    }

    return words;
}

PieceInfo FindUnknownWord(string text,size_t beginning)
{

    return FindPiece(text,beginning,GetWordDelimiters());
}

PieceInfo FindPiece(string text, size_t beginning, vector<string> delimiters)
{
    size_t startPosition = beginning;
    size_t position = startPosition;
    PieceInfo result;
    result.startPosition = string::npos;
    result.piece = "";

    while(startPosition != string::npos && startPosition < text.length())
    {
        position = FindFirstDelimiter(text,startPosition,delimiters);

        if(position != string::npos)
        {
            if(position > startPosition)
            {
                result.piece = text.substr(startPosition,position-startPosition);
                result.startPosition = startPosition;
                startPosition = string::npos;
            }

            else
            {
                ++startPosition;
            }
        }

        else
        {
            result.piece = text.substr(startPosition,text.length() - startPosition);
            result.startPosition = startPosition;
            startPosition = string::npos;
        }
    }

    return result;
}

size_t FindFirstDelimiter(string text,size_t beginning,vector<string> delimiters)
{
    size_t position = string::npos;
    size_t newPosition = 0;

    for(size_t element = 0; element < delimiters.size(); ++element)
    {
        newPosition = text.find(delimiters[element],beginning);

        if(newPosition < position)
        {
            position = newPosition;
        }
    }

    return position;
}

vector<string> GetWordDelimiters()
{
    vector<string> delimiters;
    delimiters.push_back(string(" "));
    delimiters.push_back(string(","));
    delimiters.push_back(string("."));
    delimiters.push_back(string("!"));
    delimiters.push_back(string("?"));
    delimiters.push_back(string("-"));

    return delimiters;
}

