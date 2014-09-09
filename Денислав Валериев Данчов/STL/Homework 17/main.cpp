#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str = "This is a simple text, so simple is what really works! Please, write a program that removes, all words that occur in it odd number of times.";

	vector<string> words;

	unsigned position = str.find_first_of(",.!?:", 0);


	while (position != string::npos)
	{
		str.replace(position, 1, "");
		position = str.find_first_of(",.!?:", position + 1);
	}

	string res = "";

	for (unsigned i = 0; i < str.length(); i++) {
		char ch = tolower(str[i]);
		res += ch;
	}

	int startPosition = 0;
	int endPosition = 0;


	for (unsigned i = 0; i < res.length(); i++)
	{
		endPosition = res.find(" ", endPosition + 1);

		if (i == 0)
		{
			words.push_back( res.substr(startPosition, endPosition - startPosition));
			startPosition = endPosition;
		}

		else
		{
			words.push_back( res.substr(startPosition + 1, endPosition - startPosition - 1));
			startPosition = endPosition;
		}

	}

	int counter = 0;

	list<string> diffwords;


	        for (unsigned i = 0; i < words.size(); i++)
	        {
	        	diffwords.push_back(words[i]);
	        }

	        diffwords.sort();
	        diffwords.unique();
            list<string>::const_iterator it;
            vector<string> discriminate;

            	  for (it = diffwords.begin(); it != diffwords.end() ; it++)
            	  {
                      for (unsigned i = 0; i < words.size(); i++)
                      {
            		         if (*it == words[i])
            		         {
            		            counter++;
            		         }
            	      }

                      if(counter % 2 == 0)
                      {
                    	  discriminate.push_back(*it);
                      }

                      counter = 0;
                  }

            	  for(unsigned i = 0; i < discriminate.size(); i++)
            	  {
            		  cout<<discriminate[i]<<" ";
            	  }

		return 0;
}
