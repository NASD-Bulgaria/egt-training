//============================================================================
// Name        : Ex9_File_Bonus.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
# include <vector>
#include <algorithm>
using namespace std;

void sort(vector<int> &arrInt, vector<string> &arrStr)
{
	int temp = arrInt[0];
	for(size_t i=0; i<arrInt.size()-1; ++i)
	{
		for(size_t j=1; j<arrInt.size(); ++j)
		{
			if(temp > arrInt[j])
			{
				temp=arrInt[j-1];
				arrInt[j-1]=arrInt[j];
				arrInt[j]=temp;
				arrStr[j-1].swap(arrStr[j]);
			}
		}

	}
//	for (size_t i = 0; i < arrStr.size(); ++i) {
//		cout << arrStr[i] << " " << arrInt[i] << endl;
//	}
}

int main()
{
	vector<string> words;
	vector<int> count;

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
		string temp;
		inWord>>temp;
		words.push_back(temp);
		count.push_back(0);
	}
	inWord.close();

	for(size_t i=0; i<words.size(); i++)
	{
		string temp = words[i];
		int index = strText.find(temp);
		cout<<index<<endl;
		while(index != -1)
		{
			count[i]++;
			index=strText.find(temp, ++index);
			cout<<index<<endl;
		}
	}

	//sort(count.begin(), count.end());

	sort(count, words);

	ofstream out("result.txt",ios::out);
	if(!out)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}
	for(size_t i=0; i<count.size(); i++)
	{
		out<<count[i]<<" - "<<words[i]<<endl;
	}
	out.close();
	return 0;
}
