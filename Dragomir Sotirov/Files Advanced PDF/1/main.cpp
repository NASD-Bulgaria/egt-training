#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
    map<string,int> different;

	ifstream readText1("input.txt", ios::in);

	if (!readText1 )
    {
	ofstream write1("input.txt");
    write1 << "Aз обичам Java и Microsoft.";
	write1.clear();
	write1.seekp(0);
    cerr << "Creating file input.txt"<<endl<<"Please restart the program.";
	exit(1);
	}

	string text;
	string word;

	while (readText1 >> word)
	{
		text.append(word + " ");
	}

	readText1.clear();
	readText1.seekg(0);

	unsigned position = 0;

	for (unsigned i = 0; i < text.size(); i++)
	{
		char ch = text.at(i);

		if (isupper(ch))
		{
			position = text.find_first_of(" .,?!-:();\"", i);
			string asterisk;
			asterisk.assign(position-i-1,'*');
			text.replace(i+1, position-i-1, asterisk);
		}

	}

		ofstream writeText("output.txt", ios::out);
		writeText << text;

		readText1.clear();
		readText1.seekg(0);

		cout << "Done! Check output.txt"<<endl;

	return 0 ;
}
