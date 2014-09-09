#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream readText("text.txt", ios::in);
	ifstream readReplacement("replacement.txt", ios::in);
	ofstream writeText("output.txt", ios::out);

	if (!readText || !readReplacement)
	    {
		ofstream write1("text.txt");
		ofstream write2("replacement.txt");
	    write1 << "Хитър Петър е много умен, но Гошо не е много умен. Петър е мъдър, а Гошо е силен. Те са двама, ама не са братя.";
	    write1.clear();
		write1.seekp(0);
		write2 << "умен - мъдър , ама - но , силен - здрав.";
		write2.clear();
		write2.seekp(0);
	    cerr << "Creating files input.txt and replacement.txt"<<endl<<"Please restart the program.";
		exit(1);
		}

	string word;
	string sentence;
	string replacement;

	while (readText >> word)
	{
		sentence.append(word + " ");
	}

	while (readReplacement >> word)
	{
		replacement.append(word + " ");
	}

return 0;
}
