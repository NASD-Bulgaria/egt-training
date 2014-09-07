#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
struct PieceInfo
{
    string piece;
    size_t startPosition;
};
vector<string> ExtractWords(string text);
PieceInfo FindUnknownWord(string text,size_t beginning);
PieceInfo FindPiece(string text, size_t beginning, vector<string> delimiters);
size_t FindFirstDelimiter(string text,size_t beginning,vector<string> delimiters);
vector<string> GetWordDelimiters();
void mapDisplay(map<string, int> mapD);
string ToLower(string text);
int main()
{

    vector <string> words;
    map<string,int> wordsCount;
    string tempStr = "Write a program that counts how many times each word from a given text presents in it. The casing differences should be ignored. The result  words should be ordered by their number of occurrences in the text. Example:";
    tempStr = ToLower(tempStr);
    words = ExtractWords(tempStr);

    for(size_t i =0; i < words.size();i++)
    {
        if(wordsCount.find(words[i])==wordsCount.end())
        {
          wordsCount.insert ( pair<string,int>(words[i],1) );
        }
        else
        {
            wordsCount.at(words[i])++;
        }
    }
    mapDisplay(wordsCount);
    return 0;
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

vector<string> GetWordDelimiters()
{
    vector<string> delimiters;
    delimiters.push_back(string(" "));
    delimiters.push_back(string(","));
    delimiters.push_back(string("."));
    delimiters.push_back(string("!"));
    delimiters.push_back(string("?"));
    delimiters.push_back(string("-"));
    delimiters.push_back(string(":"));

    return delimiters;
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

void mapDisplay(map<string,int> mapD)
{

    for ( map<string,int>::iterator it = mapD.begin();it != mapD.end(); ++it )
    {
        cout <<setw(14)<<left<< it->first << '\t' <<setw(3)<< it->second << '\n';
    }
}

string ToLower(string text)
{
    char temp;
    string newStr = "";

    for(size_t i = 0; i < text.length(); i++)
    {
        temp= text.at(i);
        temp = tolower(temp);
        newStr.append(&temp,1);

    }

    return newStr;
}
