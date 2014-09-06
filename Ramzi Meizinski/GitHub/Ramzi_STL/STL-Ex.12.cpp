//Write a program that counts how many times
//each word from a given text presents in it. The
//casing differences should be ignored. The result
//words should be ordered by their number of
//occurrences in the text. Example:
//is -> 2
//the -> 2
//this -> 3
//text -> 6

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;

typedef multimap < int, string, less< int > > Mid;

int main() {

	string str = "This is the TEXT. Text, text, text - THIS TEXT!Is this the text?";
	string temp;
	vector <string> words;
	Mid wordRepeat;


	for (unsigned int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			str[i] = tolower(str[i]);
			temp = temp.append(1, str[i]);
		}
		else
		{	if(isalpha(str[i-1])){
			words.push_back(temp);
			}
		temp="";
		}
	}
	sort(words.begin(),words.end());
	int count=0;
	temp = words[0];
	for (unsigned int i = 0; i < words.size(); i++) {
		if (words[i] == temp) {
			count++;
		} else {
			wordRepeat.insert( Mid::value_type( count, temp ) );
			count = 1;
			temp = words[i];
		}
		if(i == words.size()-1)
		{
			wordRepeat.insert( Mid::value_type( count, temp ) );
		}
	}


	Mid::iterator it;
	for (it = wordRepeat.begin(); it != wordRepeat.end();it++)
	{
		cout << it->second << " -> " << it->first <<   endl;
	}

return 0;
}
