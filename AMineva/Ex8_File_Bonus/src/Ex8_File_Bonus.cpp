//============================================================================
// Name        : Ex8_File_Bonus.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string strWord;
	string strText;

	ifstream inText("text.txt",ios::in);
	if(!inText)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}

	while(!inText.eof())
	{
		string temp;
		getline(inText, temp);
		strText.append(temp + "\n");
	}
	inText.close();

	ifstream inWord("words.txt",ios::in);
	if(!inWord)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}

	while(!inWord.eof())
	{
		inWord>>strWord;
		int index = strText.find(strWord);
		while(index < strText.length())
		{
			strText.erase(index, strWord.length());
			index=strText.find(strWord, ++index);
		}
	}
	inWord.close();

	ofstream out("text.txt",ios::app);
	if(!out)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}
	out<<"\n"<<strText;
	out.close();

	return 0;
}
