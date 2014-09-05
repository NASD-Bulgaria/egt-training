#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <iostream>
using namespace std;

int main()
{
	fstream inFile("text.txt", ios::in);
	ofstream outFile("replaceText.txt", ios::out);


	if(!inFile)
	{
		cerr <<"File could not be opened";
		exit(1);
	}

	string textFromFile;
	string result;

	while(!inFile.eof())
	{
		getline(inFile, textFromFile);
		result.append(textFromFile);
		result.append("\n");
	}


	string textToLower;

	for(unsigned i = 0; i < result.length(); i++)
	{

		char ch = result.at(i);

		if (isupper(ch))
		{
			ch = tolower(ch);
		}


		string s(1, ch);  // convert char to string.
		textToLower = textToLower.append(s);
	}

	int position = textToLower.find( "start" );

	while ( position != string::npos )
	{
		textToLower.replace(position,5, "finish");
		position = textToLower.find( "start", position + 1 );
	}

	outFile << textToLower;





	return 0;
}
