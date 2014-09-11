//============================================================================
// Name        : Ex12_Lecture26.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
using namespace std;

string toLower(string);
void countWord(string, map<string, int>&);
void sortMapByValue(map<string, int>, multimap<int, string>&);

int main()
{
	string str = "This is the TEXT. Text, text, text – THIS TEXT! Is this the text?";
    map<string, int>m;
    countWord(str, m);
    multimap<int, string>mm;
    sortMapByValue(m,mm);
    multimap<int, string>::const_iterator it = mm.begin();
    while(it != mm.end())
	{
		cout<<it->second<<" - "<<it->first<<endl;
		it++;
	}
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

void sortMapByValue(map<string, int> m, multimap<int, string> &mm)
{
	map<string, int>::const_iterator it = m.begin();
	while(it != m.end())
	{
		mm.insert(pair<int, string>(it->second, it->first));
		it++;
	}
}
