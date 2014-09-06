//12. Write a program that counts how many times
//each word from a given text presents in it. The
//casing differences should be ignored. The result
//words should be ordered by their number of
//occurrences in the text. Example:
//       "This is the TEXT. Text, text, text THIS TEXT!
//         Is this the text?"
//      is  2
// 	    the  2
//		this  3
//		text  6
//

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>
#include <map>
#include  <cctype>
using namespace std;

typedef multimap<int, string, less<int> > Mmid;
int main()
{

	string str = "This is the TEXT. Text, text, text THIS TEXT! Is this the text?";
	str += " ";

	int position = str.find_first_of(".,-!?:", 0);

	while (position != string::npos)
	{
		str.replace(position, 1, "");
		position = str.find_first_of(".,-!?:", position + 1);
	}

	string newStr;

	for (unsigned i = 0; i < str.size(); i++)
	{
		char ch = str.at(i);

		if (isupper(ch))
		{
			ch = tolower(ch);
			newStr += ch;
		}
		else
		{
			ch = tolower(ch);
			newStr += ch;
		}

		if (isspace(ch))
		{
			newStr += ch;
		}
	}


	list<string> uniqueWords;

	position = 0;

	int posSpace = newStr.find_first_of(" ", 0);

	while (posSpace != string::npos)
	{
		string word = newStr.substr(position, posSpace - position);
		uniqueWords.push_back(word);
		position = posSpace + 2;
		posSpace = newStr.find_first_of(" ", position);
	}

	list<string> wordsList = uniqueWords;
	uniqueWords.sort();
	uniqueWords.unique();
	uniqueWords.remove(" ");

	Mmid sigleWord;

	int count = 0;

	for (list<string>::iterator i = uniqueWords.begin(); i != uniqueWords.end(); i++)
	{
		string temp = *i;

		for (list<string>::iterator j = wordsList.begin(); j != wordsList.end(); j++)
		{
			string temp2 = *j;

			if (temp == temp2)
			{
				count++;
			}
		}

		sigleWord.insert(Mmid::value_type(count, temp));
		count = 0;

	}

	for (Mmid::const_iterator iter = sigleWord.begin(); iter != sigleWord.end(); ++iter)
	{
		if (iter->second != " ")
		{
			cout << iter->second << " -> " << iter->first << '\n';
		}

	}

	return 0;
}

