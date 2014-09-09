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
	ifstream readText("input.txt", ios::in);

	if (!readText)
    {
	ofstream write("input.txt");
    write << "Aз обичам Java и Microsoft.";
	write.clear();
	write.seekp(0);
    cerr << "Creating file input.txt"<<endl<<"Please restart the program.";
	exit(1);
	}

	string text;
	string word;

	while (readText >> word)
	{
		text.append(word + " ");
	}

	readText.clear();
	readText.seekg(0);

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

		cout << "Done! Check output.txt"<<endl;

	return 0 ;
}
