//============================================================================
// Name        : STL-Ex2(2).cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stack>
#include <iterator>
using namespace std;

int main() {

	//	This is the TEXT. Text, text, text – THIS TEXT! Is this the text?
	string text;

	stack<char> reverse;

	cout << "Enter text: " << endl;
	getline(cin, text);

	char ch;

	while (text.length() != 0) {
		ch = text[0];
		reverse.push(ch);
		text = text.erase(0, 1);
	}

	while (!reverse.empty()) {
		cout << reverse.top();
		reverse.pop();
	}

	return 0;
}
