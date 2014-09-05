//============================================================================
// Name        : String-Ex7.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void pyramidLetters() {
	string lettets = "abcdefghijklmnopqrstuvwxyz}";
	char ch;
	int space = lettets.length() / 2;
	int count = 1;
	int index = 0;
	for (unsigned int i = 0; i < (lettets.length() + 1) / 2; i++) {
		index = i;
		for (int sp = 0; sp < space; sp++) {
			cout << " ";
		}
		for (int j = 0; j < count; j++) {
			ch = lettets.at(index);
			cout << ch;
			if (j < count / 2) {
				index++;
			} else {
				index--;
			}
		}
		space--;
		count += 2;
		cout << endl;
	}
}



int main() {

	pyramidLetters();

	return 0;
}
