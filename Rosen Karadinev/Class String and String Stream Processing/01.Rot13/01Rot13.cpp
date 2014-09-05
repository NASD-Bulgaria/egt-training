#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char rot13(char);
int main()
{
        string word;

		cout << "Enter a word: ";
        getline(cin, word);


        for(unsigned int i=0;i<word.length();++i)
        {
                if(isalpha(word[i]))
                {
                	cout << rot13(word[i]);
                }
                else
                {
                	cout << word[i];
                }

        }

        return 0;
}

char rot13(char x)
{
        char rotated;

        if(('a' <= x && 'n' > x) || ('A' <= x && 'N' > x))
                rotated = x + 13;
        else
                rotated = x - 13;

        return rotated;
}
