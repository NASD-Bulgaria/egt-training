#include <iostream>
#include <string>

using namespace std;
string ToLowerToUpper(string text);


int main()
{
    string testStr;
    cout<<"Please enter your text"<<endl;
    getline(cin,testStr);
    testStr =string(testStr.rbegin(),testStr.rend());
    testStr = ToLowerToUpper(testStr);
    cout<< testStr<<endl;
    return 0;
}



string ToLowerToUpper(string text)
{
    char temp;
    string newStr = "";

    for(size_t i = 0; i < text.length(); i++)
    {

        temp= text.at(i);
        if (islower(temp))
        {
            temp=toupper(temp);
            newStr.append(&temp,1);
        }
        else
        {
            if(isupper(temp))
            {
                temp = tolower(temp);
                newStr.append(&temp,1);
            }
        }

    }

    return newStr;
}
