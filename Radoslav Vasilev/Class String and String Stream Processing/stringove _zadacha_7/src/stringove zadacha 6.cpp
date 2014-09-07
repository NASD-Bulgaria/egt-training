//============================================================================
// Name        : stringove.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string CreatePalindrom(string seed);
string Invert(string text);

int main() {


	    string base = "abcdefghijklmnopqrstuvwxyz{";
	    string palindrom = "";
	    size_t width = base.length();
	    size_t height = width/2+1;


	    for(size_t i = 0; i < height; i++)
	    {
	        palindrom = CreatePalindrom(base.substr(i,i+1));
	        cout<<setw(width + i)<<palindrom<<endl;
	    }
	return 0;
}

string CreatePalindrom(string seed)
{
    string result;

    result = seed;
    result.append(Invert(seed.substr(0,seed.length() - 1)));

    return result;
}


string Invert(string text)
{
    string result;

    for(int i = text.length() - 1; i >=0;i--)
    {
        result.append(text.substr(i,1));
    }

    return result;
}
