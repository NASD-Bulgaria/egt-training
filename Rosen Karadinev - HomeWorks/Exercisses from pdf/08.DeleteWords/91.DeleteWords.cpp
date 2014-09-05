//8. Write a program that deletes from a text file all words that start with the prefix "test". Words
//contain only the symbols 0...9, a...z, A…Z, _.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <iostream>
using namespace std;

int main()
{
	fstream inFile("textFile.txt", ios::in);

	if(!inFile)
	{
		cerr <<"File could not be opened";
		exit(1);
	}

	string textFromFile;
	string outputText;

	while(!inFile.eof())
	{
		getline(inFile, textFromFile);
		outputText.append(textFromFile);
		outputText.append("\n");
	}

	string textToLower;

	for(unsigned i = 0; i < outputText.length(); i++)
	{

		char ch = outputText.at(i);

		if (isupper(ch))
		{
			ch = tolower(ch);
		}


		string s(1, ch);  // convert char to string.
		textToLower = textToLower.append(s);
	}

	int position = textToLower.find( "test" );
	int position2 = textToLower.find(" " , position);

	while ( position != string::npos )
	{
		textToLower.erase(position, position2 - position);
		position = textToLower.find(" test", position + 1);
		position2 = textToLower.find( " ", position  + 1);
	}

	cout << textToLower;

	return 0;
}

//test mouse testing dog testosterone cat TestArget90
