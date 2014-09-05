#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

   reverse(str.begin(), str.end());

   string newStr;

   for(int i = 0; i < str.size(); i++)
    {
        char ch = str.at(i);

        if(isupper(ch))
		{
			ch = tolower(ch);
		}
		else
        {
            ch = toupper(ch);
        }

        string s(1, ch);
		newStr = newStr.append(s);
    }

    cout << "The Reversed string is " <<  newStr << endl;
}
