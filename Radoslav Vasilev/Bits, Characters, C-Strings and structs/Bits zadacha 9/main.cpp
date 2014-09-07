#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool conditionCheker(string);
bool stoper = true;
int main()
{   string strPtr;
    vector<string> temp;

    for(int i = 0;i<5;i++)
    {   strPtr="";
        cout<<"Please enter string"<<endl;
        getline(cin,strPtr);

        if(conditionCheker(strPtr))
        {
            temp.push_back(strPtr);
        }


    }
    for(size_t i = 0;i < temp.size();i++)
    {
        cout<<"string " <<i+1<<": "<<temp[i]<<endl;
    }
    return 0;
}
bool conditionCheker(string str)
{
    string newStr= str;
    bool check = false;
    char *cstr = new char[newStr.length() + 1];
    strcpy(cstr, newStr.c_str());


    if(cstr[0]=='b')
    {
        check= true;
    }

    return check;
}
