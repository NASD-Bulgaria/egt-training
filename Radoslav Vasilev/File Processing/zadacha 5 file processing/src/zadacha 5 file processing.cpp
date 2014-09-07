#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

string ReplaceSubstr(string text,string substr,string newSubstr);

int main()
{
                string temp;
                string combine;
                ifstream inFile("text.txt", ios::in);
                ofstream outFile("NewText.txt", ios::out);


                if ( !inFile )
                {
                    cerr << "File could not be opened text.txt" << endl;
                    exit( 1 );
                }

                if ( !outFile )
                {
                    cerr << "File could not be opened NewText.txt" << endl;
                    exit( 1 );
                }

                while(getline(inFile,temp))
                {
                    temp.append("\n");
                    combine.append(temp);

                }
                combine = ReplaceSubstr(combine,"start","finish");
                outFile<<combine;

    return 0;
}

string ReplaceSubstr(string text,string substr,string newSubstr)
{
    string result = text;
    size_t start = 0;
    size_t position = start;

    while(start != string::npos && start < text.length())
    {
        position = result.find(substr,start);

        if(position != string::npos)
        {
            result.replace(position,substr.length(),newSubstr);
            start = position + substr.length();
        }

        else
        {
            start = string::npos;
        }
    }

    return result;
}
