//1. Да се напише програма която прочита съдържанието на текстов файл
//input.txt и след това кодира текста като всяка дума която започва с главна буква
//я променя като запазва първата буква а всяка слдваща я замества с ‘*’ (звезда).
//Изходния текст да се записва във файл output.txt.
//Пример:
//Вход:
//Аз обичам Java и Microsoft.
//Изход:
//А* обичам J*** и M********.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {

	ifstream readText("text.txt", ios::in);
	ofstream writeText("output.txt", ios::out);

	if (!readText) {
		cerr << "The file can not be opened !!! ";
		exit(1);
	}
	string word;
	while (readText >> word) {
		if (isupper(word.at(0))) {
			for (unsigned i = 1; i < word.size(); i++) {
				word.at(i) = '*';
			}
		}
		writeText << word << " ";
	}
	readText.clear();
	readText.seekg(0);
	return 0;
}
