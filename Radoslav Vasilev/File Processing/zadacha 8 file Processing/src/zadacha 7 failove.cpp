//============================================================================
// Name        : zadacha.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

string delWordStartWith(string,string);

int main()
{
    ifstream inFile("text.txt", ios::in);
    ofstream outFile("NewText.txt", ios::out);
    string temp;
    string combine;

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

     combine=delWordStartWith(combine,"test");

     outFile<<combine;
    return 0;
}



string delWordStartWith(string text,string substr)
{


        string result = text;
        size_t start = 0;
        size_t position = start;

        while(start != string::npos && start < text.length())
        {
            position = result.find(substr,start);



            if(position != string::npos)
            {
                result.erase(position,(result.find(" ",result.find(substr,position))-result.find(substr,position)));
            }

            else
            {
                start = string::npos;
            }
        }

        return result;
}
