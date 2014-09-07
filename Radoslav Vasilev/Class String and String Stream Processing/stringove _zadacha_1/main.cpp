#include <iostream>
#include <cctype>
#include <string>
#include<fstream>

using namespace std;

string ROT13(string );

int main()
{
    string source;
    cout << "Enter the source text: " <<flush;
    getline(cin, source);
    cout << "Result: " << ROT13(source) << endl;
    return 0;
}

string ROT13(string originalStr)
{
    string transformed;
    for (size_t i = 0; i < originalStr.size(); ++i)
    {
        if (isalpha(originalStr[i]))
        {
            if ((tolower(originalStr[i]) - 'a') < 14)
            {
                transformed.append(1, originalStr[i] + 13);
            }
            else
            {
                transformed.append(1, originalStr[i] - 13);
            }
        }
        else
        {
            transformed.append(1, originalStr[i]);
        }
    }
    return transformed;
}
