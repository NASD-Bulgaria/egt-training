//============================================================================
// Name        : Ex1_String_Lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void encryptDecript(char& symbol)
{
	bool index = false;;
	char ch = symbol;
	if(isupper(ch))
	{
		ch = tolower(ch);
		index = true;
	}
	switch(ch){
	case 'a': ch = 'n'; break;
	case 'b': ch = 'o'; break;
	case 'c': ch = 'p'; break;
	case 'd': ch = 'q'; break;
	case 'e': ch = 'r'; break;
	case 'f': ch = 's'; break;
	case 'g': ch = 't'; break;
	case 'h': ch = 'u'; break;
	case 'i': ch = 'v'; break;
	case 'j': ch = 'w'; break;
	case 'k': ch = 'x'; break;
	case 'l': ch = 'y'; break;
	case 'm': ch = 'z'; break;
	case 'n': ch = 'a'; break;
	case 'o': ch = 'b'; break;
	case 'p': ch = 'c'; break;
	case 'q': ch = 'd'; break;
	case 'r': ch = 'e'; break;
	case 's': ch = 'f'; break;
	case 't': ch = 'g'; break;
	case 'u': ch = 'h'; break;
	case 'v': ch = 'i'; break;
	case 'w': ch = 'j'; break;
	case 'x': ch = 'k'; break;
	case 'y': ch = 'l'; break;
	case 'z': ch = 'm'; break;
	}
	if(index) ch = toupper(ch);
	symbol = ch;
}

int main()
{
	string str = "abC + Abc";

	for(int i=0; i<str.length(); i++) encryptDecript(str[i]);
	cout<< str<<endl;

	for(int i=0; i<str.length(); i++) encryptDecript(str[i]);
	cout<< str<<endl;

	return 0;
}
