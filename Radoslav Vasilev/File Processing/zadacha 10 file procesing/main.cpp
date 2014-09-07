#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


vector<string> GetWordDelimiters();
bool IsDelimiter(string symbol, vector<string> delimiters);
size_t FindWord(string text,string word,size_t beginning);
string deleteWord(string text, string word);
int main()
{
    ifstream inFile("text.txt", ios::in);
    ifstream inFile1("text1.txt", ios::in);

    string temp;
    string temp1;

    vector <string> deleters;
    if ( !inFile )
    {
        cerr << "File could not be opened text.txt" << endl;
        exit( 1 );
    }
    if ( !inFile1 )
    {
        cerr << "File1 could not be opened text.txt" << endl;
        exit( 1 );
    }

    while(getline(inFile,temp))
    {
        temp1.append(temp);
        temp1.append("\n");
    }

    while(inFile1>>temp)
    {
       temp1= deleteWord(temp1,temp);
    }
     cout <<temp1<<endl;


    inFile.close();
    inFile1.close();
    return 0;
}

string deleteWord(string text, string word)
{
    string result = text;
    size_t start = 0;
    size_t position = 0;

    while(position != string::npos)
    {
        position = FindWord(result,word,start);

        if(position != string::npos)
        {
            result.erase(position,word.length());
        }

        start = position + word.length();
    }

    return result;
}

size_t FindWord(string text,string word,size_t beginning)
{
    size_t result = string::npos;
    size_t start = beginning;
    size_t end = start + word.length();
    size_t position = start;
    bool wordBeginning = false;
    bool wordEnd = false;

    while(start != string::npos && start < text.length())
    {
        position = text.find(word,start);

        if(position != string::npos)
        {
            if(start != position && position > 0)
            {
                if(IsDelimiter(text.substr(position-1,1),GetWordDelimiters()))
                {
                    wordBeginning = true;
                    end = position + word.length();
                }
            }
            else
            {
                wordBeginning = true;
                end = position + word.length();
            }

            if(end < text.length() -1)
            {

                if(IsDelimiter(text.substr(end,1),GetWordDelimiters()))
                {
                    wordEnd = true;
                }
            }
            else
            {
                wordEnd = true;
            }

            if(wordBeginning && wordEnd)
            {
                start = string::npos;
                result = position;
            }

            else
            {

                start = position + word.length();
            }

        }

        else
        {
            start = string::npos;
        }
    }

    return result;
}

vector<string> GetWordDelimiters()
{
    vector <string> delimiters;
    delimiters.push_back(string(" "));
    delimiters.push_back(string(","));
    delimiters.push_back(string("."));
    delimiters.push_back(string("!"));
    delimiters.push_back(string("?"));
    delimiters.push_back(string("-"));

    return delimiters;
}

bool IsDelimiter(string symbol, vector<string> delimiters)
{
    bool result = false;

    for(size_t element = 0; element < delimiters.size(); ++element)
    {
        if(symbol == delimiters[element])
        {
           result = true;
           break;
        }
    }

    return result;
}
