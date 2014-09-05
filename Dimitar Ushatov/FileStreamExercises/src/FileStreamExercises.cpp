//============================================================================
// Name        : FileStreamExercises.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

void readFromWriteToWithLines(ifstream&, ofstream&, string, string);
void readFromWriteSorted(ifstream&, ofstream&, string, string);
int findMaxSubSum(int**, int);
int findMaxFromReadedMatrix(ifstream&, string&);
void writeMaxSumToFile(ofstream &, string, int);
void readMatrixWriteMax(ifstream&, ofstream&, string, string);
void replaceSubstring(ifstream&, ofstream&, string, string, string);
void replaceOnlywords(ifstream&, ofstream&, string, string, string);
void deleteWordsWithPrefix(ifstream&, ofstream&, string, string);
void countDifferentLines(ifstream&, string, string);

int main() {
	ifstream istream;
	ofstream ostream;
//	readFromWriteSorted(istream, ostream, "words.txt", "wordsSorted.txt");
//	readFromWriteToWithLines(istream, ostream, "words.txt", pathTo);
//	readMatrixWriteMax(istream, ostream, "matrix.txt", "maxFromMatrix.txt");
//	replaceSubstring(istream, ostream, "replaceStart.txt","start","finish");
//	replaceOnlywords(istream, ostream, "replaceStart.txt", "start", "finish");
//	deleteWordsWithPrefix(istream, ostream, "replaceStart.txt", "start");
	countDifferentLines(istream, "replaceStart.txt", "replaceStartDif.txt");
	return 0;
}

string readFromFFile(ifstream& istream, string pathFrom) {
	if (istream.is_open()) {
		istream.close();
	}
	istream.open(pathFrom.data(), ios::in);

	char buffer[255];
	string text;
	while (istream) {
		istream.read(buffer, 255);
		text.append(buffer);
	}
	istream.close();
	return text;
}

void readFromWriteToWithLines(ifstream& istream, ofstream & ostream,
		string pathFrom, string pathTo) {
	if (istream.is_open()) {
		istream.close();
	}
	istream.open(pathFrom.data(), ios::in);
	if (!istream) {
		cerr << "The file (input) can't be opened!";
		exit(1);
	}

	if (ostream.is_open()) {
		ostream.close();
	}
	ostream.open(pathTo.data(), ios::out);
	if (!ostream) {
		cerr << "The file (output) can't be opened!";
		exit(1);
	}

	string line;
	int lineNumber = 1;
	istream >> line;
	while (!istream.eof()) {
		ostream << lineNumber << " " << line << endl;
		lineNumber++;
		istream >> line;
	}

	istream.close();
	ostream.close();
}

void readFromWriteSorted(ifstream& istream, ofstream& ostream, string pathFrom,
		string pathTo) {

	if (istream.is_open()) {
		istream.close();
	}
	istream.open(pathFrom.data(), ios::in);
	if (!istream) {
		cerr << "The file (input) can't be opened!";
		exit(1);
	}
	string word;
	vector<string> words;
	istream >> word;
	while (!istream.eof()) {
		words.push_back(word);
		istream >> word;
	}
	istream.close();
	sort(words.begin(), words.end());

	if (ostream.is_open()) {
		ostream.close();
	}
	ostream.open(pathTo.data(), ios::out);
	if (!ostream) {
		cerr << "The file (output) can't be opened!";
		exit(1);
	}

	for (unsigned int i = 0; i < words.size(); ++i) {
		ostream << words[i] << endl;
	}

	ostream.close();
}

int findMaxSubSum(int** matrix, int size) {
	int sum;
	int maxSum = INT_MIN;
	for (int i = 0; i < size - 1; ++i) {
		for (int g = 0; g < size - 1; ++g) {
			sum = matrix[i][g] + matrix[i][g + 1] + matrix[i + 1][g + 1]
					+ matrix[i + 1][g];
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	return maxSum;
}

int findMaxFromReadedMatrix(ifstream &stream, string &pathFrom) {
	if (stream.is_open()) {
		stream.close();
	}
	stream.open(pathFrom.data(), ios::in);
	if (!stream) {
		cerr << "The file (input) can't be opened!";
		exit(1);
	}
	int num;
	stream >> num;
	int** matrix = new int*[num];
	for (int i = 0; i < num; ++i) {
		matrix[i] = new int[num];
	}

	for (int i = 0; i < num; ++i) {
		for (int g = 0; g < num; ++g) {
			stream >> matrix[i][g];
		}
	}
	stream.close();
	return findMaxSubSum(matrix, num);
}

void writeMaxSumToFile(ofstream & stream, string pathTo, int max) {

	if (stream.is_open()) {
		stream.close();
	}
	stream.open(pathTo.data(), ios::out);
	if (!stream) {
		cerr << "The file (output) can't be opened!";
		exit(1);
	}

	stream << max << endl;

	stream.close();
}

void readMatrixWriteMax(ifstream& istream, ofstream& ostream, string pathFrom,
		string pathTo) {
	writeMaxSumToFile(ostream, pathTo,
			findMaxFromReadedMatrix(istream, pathFrom));
}

void replaceSubstring(ifstream& istream, ofstream& ostream, string path,
		string replace, string replaceWith) {
	string text = readFromFFile(istream, path);
	int index = text.find(replace);
	while (index != -1) {
		text.replace(index, replace.length(), replaceWith);
		index = text.find(replace);
	}
	if (ostream.is_open()) {
		ostream.close();
	}
	ostream.open(path.data(), ios::out);
	ostream << text;
	ostream.close();

	cout << text << endl;
}

bool isWord(string word, string text, int index) {
	if (index + word.length() == text.length() - 1
			|| (index == 0 && index + word.length() < text.length()
					&& !isalpha(text[index + word.length()]))
			|| (index > 0 && index + word.length() < text.length() - 1
					&& !isalpha(text[index - 1])
					&& !isalpha(text[index + word.length()]))) {
		return true;
	}
	return false;
}

void writeDataTo(ofstream& ostream, string path, string data) {
	if (ostream.is_open()) {
		ostream.close();
	}
	ostream.open(path.data(), ios::out);
	ostream << data;
	ostream.close();
}

void replaceOnlywords(ifstream& istream, ofstream& ostream, string path,
		string replace, string replaceWith) {
	string text = readFromFFile(istream, path);
	int index = text.find(replace);
	while (index != -1) {
		if (isWord(replace, text, index)) {
			text.replace(index, replace.length(), replaceWith);
		}
		index = text.find(replace, index + 1);
	}
	writeDataTo(ostream, path, text);

	cout << text << endl;
}

void deleteWordsWithPrefix(ifstream& istream, ofstream& ostream, string path,
		string prefix) {
	string text = readFromFFile(istream, path);
	string word;
	unsigned int g = 0;
	for (unsigned int i = 0; i < text.length(); i++) {
		word = "";
		g = i;
		while (g < text.length() && (isalpha(text[g]) || isdigit(text[g]))) {
			word.append(string(1, text[g]));
			g++;
		}
		if (word != "") {
			if (word.find(prefix) == 0) {
				text.erase(i, word.length());
			} else {
				i += word.length();
			}
		}
	}
	writeDataTo(ostream, path, text);
}

void addReadedLines(ifstream& stream, string path,
		vector<string>& lines) {
	string text = readFromFFile(stream, path);
	int lineIndex = text.find('\n');
	string line;
	while(lineIndex != -1){
		line = text.substr(0, lineIndex);
		text.erase(0, line.length() + 1);
		lines.push_back(line);
		lineIndex = text.find('\n');
	}
	if (text != "") {
		lines.push_back(text);
	}
}

void countDifferentLines(ifstream& firstStream,
		string firstPath, string secondPath) {
	vector<string> lines;
	addReadedLines(firstStream, firstPath, lines);

	vector<string> secondLines;
	addReadedLines(firstStream, secondPath, secondLines);

	int minSize = min(lines.size(), secondLines.size());
	int difCount = max(lines.size(), secondLines.size()) - minSize;
	for (int line = 0; line < minSize; ++line) {
		if (lines[line] != secondLines[line]) {
			difCount++;
		}
	}

	cout<<"The number of different lines is: " << difCount<<endl;

}
