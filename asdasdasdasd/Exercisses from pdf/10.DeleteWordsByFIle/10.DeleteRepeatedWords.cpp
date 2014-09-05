#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{

	fstream inFile("textToDelete.txt", ios::in);
	fstream removeFile("checkText.txt", ios::in);
	fstream result("resultText.txt,", ios::out);

	if(!inFile)
	{
		cerr << "Error to open the file.";
	}

	string words;
	string newText;

	while(inFile >> words)
	{
		newText.append(words + " ");
	}

	inFile.clear();
	inFile.seekg(0);

	string newText2;

	for(unsigned int i = 0; i < newText.length(); i++)
	{
		char ch = newText.at(i);

		if(isupper(ch))
		{
			ch = tolower(ch);
		}

		string s(1, ch);
		newText2 = newText2.append(s);
	}

	string word;
	string wordCheck;

	vector<string> textToRemove;

	while(inFile >> word)
	{
		textToRemove.push_back(word);
	}

	inFile.clear();
	inFile.seekg(0);

	while(removeFile >> wordCheck)
	{
		for(unsigned int i = 0; i < textToRemove.size(); i++)
		{
			if(wordCheck == textToRemove[i])
			{
				textToRemove.erase(textToRemove.begin() + i);
			}
		}
	}

	removeFile.clear();
	removeFile.seekg(0);

	for(unsigned int i = 0; i < textToRemove.size(); i++)
	{
		cout<< textToRemove[i] << " " ;
		result << textToRemove[i]<< " ";
	}


	return 0;
}
