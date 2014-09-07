//Write a program that reads several sentences from the
//console and reverses not only them but and every one of
//them word by word.


#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cout << "Enter text: ";
	string s;
	getline(cin, s);
	stack<char> reversedText;
	for (unsigned int i = 0; i < s.length(); i++) {
		reversedText.push(s[i]);
	}
	while (!reversedText.empty()) {
		cout << reversedText.top();
		reversedText.pop();
	}
	return 0;
}
