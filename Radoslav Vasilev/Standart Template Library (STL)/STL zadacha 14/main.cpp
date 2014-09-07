#include <iostream>
#include <stack>
#include <string>
using namespace std;

string textReverse(string);

int main()
{
    string text;
    int check = 5;
    while(check>0)
    {
        cout<<"please enter text" <<endl;
        getline(cin,text);
        text =textReverse(text);
        cout<<text<<endl;
        check--;
    }
    return 0;
}

string textReverse(string str)
{
    string temp;
    string newStr;
    stack <string> letters;

    for(size_t  i =0;i < str.length();i++)
    {
        temp= str.at(i);
        letters.push(temp);
    }

    while (!letters.empty())
    {
        temp=letters.top();
        newStr.append(temp);
        letters.pop();
    }
    return newStr;
}
