//============================================================================
// Name        : Ex5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void stringToVector(vector<string>&, string);
bool isPalindrome(string word);

int main()
{
	string str;
	ifstream in("input.txt");
	if(in.is_open())
	{
		string temp;
		while(!in.eof())
		{
			getline(in,temp);
			str.append(temp);
		}
		in.close();
	}
	else cerr<<"Error opening file mesage.txt !";

	vector<string>words;
	stringToVector(words, str);
	vector<string>is;
	for(unsigned i=0; i<words.size(); i++)
		if(isPalindrome(words[i]))
			is.push_back(words[i]);
	sort(is.begin(), is.end());
	ofstream out("output.txt");
	if(out.is_open())
	{
		for(unsigned i=0; i<is.size(); i++)
			out<<is[i]<<endl;
		out.close();
	}
	else cerr<<"Error opening file mesage.txt !";

	return 0;
}

void stringToVector(vector<string>&v, string str)
{
	string temp=str;
	//transform(str.begin(), str.end(),back_inserter(temp),ptr_fun<int,int>(tolower));
	for(unsigned i=0; i<temp.length(); i++)
	{
		string word="";
		while(isalpha(temp[i]))
		{
			word += temp[i];
			i++;
		}
		if(!word.empty())
			v.push_back(word);
	}
}

bool isPalindrome(string word)
{
	bool index=true;
	for(unsigned i=0; i<word.length()/2; i++)
	{
		if(word[i]!=word[word.length()-i-1])
		{
			index=false;
			break;
		}
	}
	return index;
}
