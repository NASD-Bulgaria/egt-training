//There are two text files. Display all words that
//present only in one of the files.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

	ifstream readText("text1.txt", ios::in);
	ifstream readText2("text2.txt", ios::in);
	ofstream writeText("result.txt", ios::out);

	if(!readText || !readText2)
	{
		cerr <<"File could not be opened";
		exit(1);
	}

	string text;
	string word;


	while (readText >> word)
	{
		text.append(word + " ");
	}

	while (readText2 >> word)
	{
		text.append(word + " ");
	}


	int position = text.find_first_of(".,?!-:();\"", 0);

	while (position != string::npos)
	{
		text.replace(position, 1, "");
		position = text.find_first_of(".,?!-:();\"", position);
	}

	for (unsigned i = 0; i < text.size(); i++)
	{
		char ch = text.at(i);
		ch = tolower(ch);
		text.at(i) = ch;
	}

	stringstream ss;
	ss.str(text);

	string wordFromFile;
	vector<string> words;

	while(ss >> wordFromFile)
	{
		words.push_back(wordFromFile);
	}

	unique(words.begin(), words.end());

	for(unsigned int i = 0; i < words.size(); i++)
	{
		writeText << words[i] << " ";
	}

	cout << "Program is complete "<< endl;

	return 0 ;
}
