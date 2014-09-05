//============================================================================
// Name        : HomeWork19-FileInputOutput.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Hardware.h"

using namespace std;

void formatFile(fstream &stream, const char* filePath, int objectCount,
		Hardware& empty);

void generateHardware(vector<Hardware> &emptyCollection, int objectCount,
		string* validTypes, int * prices, int count);

void writeHardwareToFile(fstream &stream, const char *filePath,
		vector<Hardware> &collection);

void readHardwareFromFile(fstream &stream, const char *filePath,
		vector<Hardware> &collection);

void printingAllHardware(vector<Hardware> &collection);

void writeAllCombinations();

int main() {
//	string validTypes[4] = { "Lap top", "PC", "Smart Phone", "Tablet" };
//	int prices[4] = { 1200, 900, 450, 350 };
//
//	fstream inOutHardwareData;
//	const char* filePath = "HardwareRecords.dat";
//	int objectCount = 100;
//	Hardware empty;
//
//	formatFile(inOutHardwareData, filePath, objectCount, empty);
//
//	vector<Hardware> allHardware;
//	cout << "Generating " << objectCount << " Hardware records" << endl;
//	generateHardware(allHardware, objectCount, validTypes, prices, 4);
//
//	cout << "Writing all Hardware to ~\\" << filePath << endl;
//	writeHardwareToFile(inOutHardwareData, filePath, allHardware);
//
//	allHardware.clear();
//	cout << "Reading all files from ~\\" << filePath << endl;
//	readHardwareFromFile(inOutHardwareData, filePath, allHardware);
//
//	cout << "Printing all readed Hardware" << endl;
//	printingAllHardware(allHardware);

	writeAllCombinations();
	return 0;
}

void formatFile(fstream &stream, const char *filePath, int objectCount,
		Hardware& empty) {
	if (!stream.is_open()) {
		stream.open(filePath, ios::binary | ios::in | ios::out);
	}
	if (!stream) {
		cout << "The file can not be opened!" << endl;
		return;
	}
	for (int i = 0; i < objectCount; i++) {
		stream.write(reinterpret_cast<const char*>(&empty), sizeof(Hardware));
	}
	stream.close();
}

void generateHardware(vector<Hardware> &emptyCollection, int objectCount,
		string* validTypes, int * prices, int count) {
	Hardware empty;
	int index;
	srand(time(NULL));
	for (int i = 0; i < objectCount; i++) {
		index = rand() % count;
		empty.setIdentNumber(i).setPrice(prices[index]).setType(
				validTypes[index]);
		emptyCollection.push_back(empty);
	}
}

void writeHardwareToFile(fstream &stream, const char *filePath,
		vector<Hardware> &collection) {
	if (!stream.is_open()) {
		stream.open(filePath, ios::binary | ios::in | ios::out);
	}
	if (!stream) {
		cout << "The file can not be opened!" << endl;
		return;
	}
	for (unsigned int i = 0; i < collection.size(); i++) {
		stream.write(reinterpret_cast<const char*>(&collection[i]),
				sizeof(Hardware));
	}
	stream.close();
}

void readHardwareFromFile(fstream &stream, const char *filePath,
		vector<Hardware> &collection) {
	if (!stream.is_open()) {
		stream.open(filePath, ios::binary | ios::in | ios::out);
	}
	if (!stream) {
		cout << "The file can not be opened!" << endl;
		return;
	}
	Hardware empty;
	stream.seekg(0, ios::end);
	int end = stream.tellg();
	stream.seekg(0);
	while (stream.tellg() < end) {
		stream.read(reinterpret_cast<char*>(&empty), (sizeof(Hardware)));
		collection.push_back(empty);
	}
	stream.close();
}

void printingAllHardware(vector<Hardware> &collection) {
	for (unsigned int i = 0; i < collection.size(); i++) {
		cout << left << setw(10) << collection[i].getIdentNumber() << left
				<< setw(30) << collection[i].getType() << left << setw(10)
				<< collection[i].getPrice() << endl;
	}
}

bool allAreNumbers(string numberStr) {
	for (unsigned int i = 0; i < numberStr.length(); ++i) {
		if (!isdigit(numberStr[i])) {
			return false;
		}
	}
	return true;
}

void writeCombination(ofstream& stream, const char * const path,
		const char* const wordToPrint) {
	if (!stream.is_open()) {
		stream.open(path, ios::out);
	}
	if (!stream) {
		cerr << "The file can not be opened!";
		exit(1);
	}

	stream << wordToPrint << endl;
}

void calcAllCombinations(const string * const buttons,
		const char * const number, int const & digitCount, char* wordToPrint,
		int const & index, vector<string>& allCombinations) {
	for (unsigned int i = 0; i < buttons[(int) number[index] - 48].length();
			++i) {
		wordToPrint[index] = buttons[(int) number[index] - 48][i];
		if (index < digitCount - 1) {
			calcAllCombinations(buttons, number, digitCount, wordToPrint,
					index + 1, allCombinations);
		} else {
			allCombinations.push_back(wordToPrint);
		}
	}
}

void writeAllCombinations() {
	string buttons[] = { " ", ".,!?", "abc", "def", "ghi", "jkl", "mno", "pqrs",
			"tuv", "wxyz" };

	unsigned int length = 7;
	cout << "Enter a " << length << " digit number" << endl;
	string number;
	cin >> number;

	while (number.length() != length || !allAreNumbers(number)) {
		cout << "Invalid input!" << endl;
		cin >> number;
	}

	char* wordToPrint = new char[length];
	vector<string> allCombinations;
	calcAllCombinations(buttons, number.data(),
			length, wordToPrint, 0, allCombinations);

	string path = "allCombinations.txt";
	ofstream ostream;
	for (unsigned int i = 0; i < allCombinations.size(); ++i) {
		writeCombination(ostream, path.data(), allCombinations[i].data());
	}

}
