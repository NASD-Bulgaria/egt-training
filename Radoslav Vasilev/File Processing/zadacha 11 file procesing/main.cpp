#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct wordCount
{
  string word;
  int count;
};
bool compareByLength(const wordCount &a, const wordCount &b);
vector<string> GetWordDelimiters();
bool IsDelimiter(string symbol, vector<string> delimiters);
size_t FindWord(string text,string word,size_t beginning);
size_t CountWord(string text,string word);
int main()
{
    ifstream inFile("text.txt", ios::in);
    ifstream inFile1("text1.txt", ios::in);
    ofstream outFile( "write.txt", ios::out );
    string temp;
    string temp1;
    wordCount temp2;
    vector <wordCount> counter;

    if ( !inFile&& !outFile)
    {
        cerr << "File could not be opened text.txt" << endl;
        exit( 1 );
    }
    if ( !inFile1 )
    {
        cerr << "File1 could not be opened text.txt" << endl;
        exit( 1 );
    }

    while(getline(inFile,temp1))
    {
        temp1.append(temp);
        temp1.append("\n");
    }
    while ( inFile1 >> temp)
    {
        temp2.word =temp;
        temp2.count=CountWord(temp1,temp);
        counter.push_back(temp2);
    }
    sort(counter.begin(),counter.end(),compareByLength);
    for(size_t i = 0;i < counter.size();i++)
    {
        cout<<counter[i].word<< " - "  <<counter[i].count<<endl;
        outFile<<counter[i].word<< " - "  <<counter[i].count<<endl;
    }
    inFile.close();
    inFile1.close();
    outFile.close();
    return 0;
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

size_t CountWord(string text,string word)
{
    size_t count = 0;
    size_t start = 0;
    size_t position = start;

    while(position != string::npos)
    {
        position = FindWord(text,word,start);

        if(position != string::npos)
        {
            ++count;
            start = position + word.length();
        }

    }

    return count;
}

bool compareByLength(const wordCount &a, const wordCount &b)
{
    return a.count > b.count;
}
