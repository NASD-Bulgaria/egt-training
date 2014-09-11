//============================================================================
// Name        : STL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void swapRight(string&);
void rotate(int[][6], int, int);
string genAsteriks(int);

void TaskOne() {
	ifstream inFile("input.txt", ios::in);
	if (!inFile) {
		exit(1);
	}
	string line;
	string word;
	vector<string> words;
	while (getline(inFile, line))
		for (unsigned int i = 0; i < line.length(); i++) {
			char d = line.at(i);
			if (isalnum(d)) {
				word.append(string(1, d));
			}
			if (word != "") {
				if (ispunct(d) || isspace(d) || i == line.length() - 1) {
					words.push_back(word);
					word = "";
				}
			}
		}
	cout << line << endl;
	for (unsigned int i = 0; i < words.size(); i++) {
		if (isupper(words[i].at(0))) {
			int index = line.find(words[i]);
			line.replace(index + 1, words[i].length() - 1,
					genAsteriks(words[i].length() - 1));
		}
	}
	cout << line << endl;
}
void TaskTwo() {
	ifstream inFile("matrix.txt", ios::in);
	if (!inFile) {
		exit(1);
	}
	int number;
	string d;
	vector<int> theMatrix;
	while (inFile >> d) {
		number = atoi(d.c_str());
		theMatrix.push_back(number);
	}

	int size = sqrt(theMatrix.size());
	int array[size][size];
	int r = 0;
	for (int i = 0; i < size; i++) {
		for (int g = 0; g < size; g++) {
			array[i][g] = theMatrix[r];
			r++;
			cout << array[i][g] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++) {
		int check = i;
		for (int g = 0; g < size; g++) {
			if (check >= 0) {
				cout << array[check][g] << " ";
				check--;

			}

		}
		cout << endl;
	}
	for (int g = 1; g < size; g++) {
		int col = g;
		int check = size - 1;
		while (col < size) {
			cout << array[check][col] << " ";
			col++;
			check--;
		}
		cout << endl;
	}
}
void TaskFour() {
	ifstream inFile("message.txt", ios::in);
	if (!inFile) {
		exit(1);
	}
	string line;
	while (getline(inFile, line))
		;

	int size = sqrt(line.length()) + 1;
	char matrix[size][size];
	vector<char> symbol;
	for (unsigned int i = 0; i < line.length(); i++) {
		char d = line.at(i);
		symbol.push_back(d);
	}
	int r = 0;
	for (int g = 0; g < size; g++) {
		for (int i = 0; i < size; i++) {

			if (r < symbol.size()) {
				matrix[i][g] = symbol[r];
				r++;
			} else {
				matrix[i][g] = '\0';
			}
		}
	}
	ofstream outFile("encoded-message.txt", ios::out);
	if (!outFile) {
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		for (int g = 0; g < size; g++) {
			char d = matrix[i][g];
			outFile << d;
		}
	}
}
void TaskSeven() {
	string line;
	char d;
	ifstream inFile("problem1.txt", ios::in);
	if (!inFile) {
		exit(1);
	}
	inFile >> d;
	vector<string> v1;
	vector<string> v2;
	int check = 0;
	while (!inFile.eof()) {
		inFile >> line;
		if (check % 2 == 0) {
			v1.push_back(line);
		} else {
			v2.push_back(line);
		}
		check++;
	}
	for (unsigned int i = 0; i < v1.size(); i++) {
		int check = 0;
		while (v1[i] != v2[i]) {
			swapRight(v1[i]);
			check++;
			if (check >= v1[i].length()) {
				check = -1;
				break;
			}
		}
		cout << check << endl;
	}

}
void TaskTwelve() {
	multiset<string> words;
	ifstream inFile("problem3.txt", ios::in);
	string line;
	string text;
	if (!inFile) {
		exit(1);
	}
	string word;
	while (getline(inFile, line)) {
		text.append(line);
		text.append(" ");
	}

	for (unsigned i = 0; i < text.length(); i++) {
		char d = tolower(text.at(i));
		if (isalnum(d)) {
			word.append(string(1, d));
		}
		if (word != "") {
			if (isspace(d) || ispunct(d) || i == text.length() - 1) {
				words.insert(word);
				word = "";
			}
		}

	}
	multiset<string>::iterator it;
	string element;
	multiset<string> subWords;
	for (it = words.begin(); it != words.end(); it++) {
		element = *it;
		for (multiset<string>::iterator itn = words.begin(); itn != words.end();
				itn++) {
			if (it != itn) {
				element.append(*itn);
				subWords.insert(element);
				element = *it;
			}
		}
	}

	for (it = words.begin(); it != words.end(); it++) {
		for (multiset<string>::iterator itn = subWords.begin();
				itn != subWords.end(); itn++) {
			if (*it == *itn) {
				cout << *it << endl;
				break;

			}
		}
	}
}
void TaskSix(){
	int matrix[6][6] = { { 1, 2, 3, 4, 5, 6 }, { 7, 8, 9, 10, 11, 12 }, { 13,
			14, 15, 16, 17, 18 }, { 19, 20, 21, 22, 23, 24 }, { 25, 26, 27, 28,
			29, 30 }, { 31, 32, 33, 34, 35, 36 } };
	ifstream command("game36.txt", ios::in);
	if (!command) {
		exit(1);
	}
	int commands;
	string line;
	getline(command, line);
	commands = atoi(line.data());
	int x;
	int y;
	while (commands > 0) {
		getline(command, line);
		x = atoi(line.substr(line.find('(') + 1, 1).data());

		y = atoi(line.substr(line.find(',') + 1, 1).data());
		rotate(matrix, x, y);
		commands--;
		cout<<x<<" "<<y<<endl;
	}
	for (int i = 0; i < 6; i++) {
		for (int g = 0; g < 6; g++) {
			cout << matrix[i][g] << " ";
		}
		cout << endl;
	}
}
int main() {

	return 0;
}

void swapRight(string &word) {
	char d = word.at(word.length() - 1);
	word.erase(word.length() - 1);
	word = string(1, d).append(word);
}
string genAsteriks(int a) {
	string result = "";
	for (int i = 0; i < a; i++) {
		result.append("*");
	}
	return result;

}

void rotate(int array[][6], int x, int y) {
	int tmp = array[x][y + 1];
	array[x][y + 1] = array[x][y];
	array[x][y] = array[x + 1][y];
	int tmp2 = array[x + 1][y + 1];
	array[x + 1][y + 1] = tmp;
	array[x + 1][y] = tmp2;
}
