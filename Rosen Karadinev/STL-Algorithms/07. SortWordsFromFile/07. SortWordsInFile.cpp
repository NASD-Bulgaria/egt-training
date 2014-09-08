//Sort all words in a text file. Write the result in other
//text file.

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	ifstream readText("text.txt", ios::in);
	ofstream writeText("result.txt", ios::out);

	if(!readText)
	{
		cerr <<"File could not be opened";
		exit(1);
	}

	string tempText;
	string clearText;

	while(readText >> tempText)
	{
		clearText.append(tempText + " ");
	}

	int position = clearText.find_first_of(".,?!-:\'();\"", 0);

	while(position != string::npos)
	{
		clearText.replace(position, 1, "");
		position = clearText.find_first_of(".,?!-:\'();\"", position);
	}

	for(unsigned int i = 0; i < clearText.size(); i++)
	{
		char ch = clearText.at(i);
		ch = tolower(ch);
		clearText.at(i) = ch;
	}

	stringstream ss;
	ss.str(clearText);

	string wordFromFile;
	vector<string> words;

	while(ss >> wordFromFile)
	{
		words.push_back(wordFromFile);
	}

	sort(words.begin(), words.end());

	for(unsigned int i = 0; i < words.size(); i++)
	{
		writeText << words[i] << " ";
	}

	cout << "The program is complete!";

	return 0;
}
