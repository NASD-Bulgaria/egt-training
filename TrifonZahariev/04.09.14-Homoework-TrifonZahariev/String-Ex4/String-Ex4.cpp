//============================================================================
// Name        : String-Ex4.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	cout << "Enter a word: " << endl;
	getline (cin, str);
	char ch;

	for(int i = str.length()-1; i >= 0; i--){
		ch = str[i];
		if(islower(ch)){
			ch = toupper(ch);
		}
		else {
			ch = tolower(ch);
		}
		cout << str.at(i);
	}

	return 0;
}

