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
	set<string> palindromes;

	ifstream readText("input.txt", ios::in);
	ofstream writeText("palindromes.txt", ios::out);

	if (!readText)
    {
	ofstream write("input.txt");
    write << "In Windows .EXE, .BAT and .COM files are executables. We all like ABBA because they are famous pop stars.";
	write.clear();
	write.seekp(0);
    cerr << "Creating file input.txt"<<endl<<"Please restart the program.";
	exit(1);
	}

	string word;

	while (readText >> word)
	{
		unsigned position = word.find_first_of(".,?!-–:();\"", 0);

		while (position != string::npos)
			{
				word.replace(position, 1, "");
				position = word.find_first_of(".,?!-–:();\"", position);
			}

		if (word == string(word.rbegin(), word.rend()))
		{
			 palindromes.insert(word);
		}

	}

	for (set<string>::iterator it = palindromes.begin(); it != palindromes.end(); it++)
	{
			writeText << *it << " ";
	}

	cout << "Done! Check output.txt"<<endl;

	return 0 ;
}
