/*12. Write a program that counts how many times
each word from a given text presents in it. The
casing differences should be ignored. The result
words should be ordered by their number of
occurrences in the text. Example:This is the TEXT. Text, text, text – THIS TEXT!
Is this the text?
is -> 2
the -> 2
this -> 3
text -> 6*/
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
using namespace std;

vector<string> split(const string &sourceStr, const string &delimiter, bool ignoreEmpty)
{
    vector<string> resultVector;

    size_t idxA = 0;
    size_t idxB = sourceStr.find(delimiter);
    string tempStr;
    bool done = false;

    while(!done)
    {
        if(idxB != string::npos)
        {
            tempStr = sourceStr.substr(idxA, idxB-idxA);
            idxA = idxB + delimiter.length();
            idxB = sourceStr.find(delimiter, idxA);
        }
        else
        {
            tempStr = sourceStr.substr(idxA);
            done = true;
        }

        if(!(ignoreEmpty && tempStr.empty()))
            resultVector.push_back(tempStr);
    }
    return resultVector;
}

int main() {
	string text = "This is the ext text text Is this the text";
	vector<string> vector = split(text, " ", false);
	string* myarray = vector.data();

	map<string, int> mymap;
		map<string, int>::iterator it;


		//int myarray[] = { 1, 1, 2, 1, 2, 3, 4 };


		for (int i = 0; i < 7; ++i) {
	        it =  mymap.find(myarray[i]);
			if (it == mymap.end()) {

				 mymap.insert (it, pair<string,int>(myarray[i],1));

			} else {
				it->second++;
			}

		}


		for (std::map<string, int>::iterator it = mymap.begin(); it != mymap.end();
				++it)
			std::cout << it->first << " => " << it->second << '\n';

	return 0;
}
