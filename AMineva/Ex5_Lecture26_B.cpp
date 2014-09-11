//============================================================================
// Name        : Ex5_Lecture26_B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

string toLower(string);
void countWord(string, map<string, int>&);
void removeWord(string& , string);

int main()
{
	string str = "This is the TEXT. Text, text, text – THIS TEXT! Is this the text?";
    map<string, int>m;
    countWord(str, m);
    map<string, int>::const_iterator it = m.begin();
    while(it != m.end())
	{
    	cout<<it->second<<" - "<<it->first<<endl;
		if(it->second%2!=0)
			removeWord(str, it->first);
		it++;
	}

    cout<<str;

	return 0;
}

string toLower(string str)
{
	string temp = str;
	for(unsigned i=0; i<temp.length(); i++)
		temp[i] = tolower(temp[i]);
	return temp;
}

void countWord(string str, map<string, int>&m)
{
	string temp = toLower(str);
	map<string, int>::iterator it;
	for(unsigned i=0; i<temp.length(); i++)
	{
		string word="";
		while(isalpha(temp[i]))
		{
			word += temp[i];
			i++;
		}
		if(!word.empty())
		{
			it=m.find(word);
			if(it!=m.end()) it->second ++;
			else m.insert(pair<string,int>(word,1));
		}
	}
}

void removeWord(string &str, string word)
{
	string temp =" "+toLower(str);
	str = " "+ str;
	word = " "+ word;
	int pos = temp.find(word);
	while(pos!=temp.npos)
	{
		if(!isalpha(temp[pos+word.length()]))
		{
			str.erase(pos, word.length());
			temp.erase(pos, word.length());
		}
		pos = temp.find(word, pos+1);
	}
	str.erase(0, 1);
}
