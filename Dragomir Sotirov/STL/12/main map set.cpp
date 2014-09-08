#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{

	map<string, int> countWords;
	set<string,greater<string> > sortedWords;

	string sentence = "This is the TEXT. Text, text, text - THIS TEXT! Is this the text? ";

	//Remove signs
	unsigned position = sentence.find_first_of(".,?!-:();\"", 0);
	while (position != string::npos)
	{
		sentence.replace(position, 1, "");
		position = sentence.find_first_of(".,?!-:();\"", position);
	}

	//All chars tolower
	for (unsigned i = 0; i < sentence.size(); i++)
	{
		char ch = sentence.at(i);
		ch = tolower(ch);
		sentence.at(i) = ch;
	}

	stringstream ss;
	ss.str(sentence);

	string wordFromFile;

	//Add sentence to MAP
	while (ss >> wordFromFile)
	{
		countWords[wordFromFile]++;
	}

	map<string, int>::iterator it;

	//Add sentence to SET
	for (it = countWords.begin(); it != countWords.end(); it++)
	{
		stringstream aa;
		stringstream bb;
		string result;
		aa << it->first;
		bb << it->second;
		result.append(bb.str() + "->" + aa.str());
		sortedWords.insert(result);
		aa<<"";
		bb<<"";
		result = "";

		cout << it->first << "->" << it->second << endl;

	}

	for (set<string>::iterator i= sortedWords.begin() ; i != sortedWords.end() ; i ++){
		cout << *i << endl;
	}

	return 0 ;
}
