//============================================================================
// Name        : HomeWork08-Strings.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

string reverseString(string input) {
	string reversed = "";
	char ch;
	for (int i = input.length() - 1; i >= 0; i--) {
		ch = input[i];
		reversed += ch;
	}
	return reversed;
}

bool checkExpression(string expr) {
	char open = '(';
	char close = ')';
	int openPos = -1;
	int closePos = expr.length();
	bool valid = true;

	while (openPos != -1 || closePos != -1) {
		openPos = expr.find_first_of(open, openPos + 1);
		closePos = expr.find_last_of(close, closePos - 1);
		if (closePos < openPos || (openPos == -1 && closePos != -1)) {
			valid = false;
			break;
		}
	}

	return valid;
}

string changeCasing(string expr) {
	char d;
	for (int ch = 0; ch < (int) expr.length(); ++ch) {
		d = expr[ch];
		if (isalpha(d)) {
			if (isupper(d)) {
				expr[ch] = tolower(d);
			} else {
				expr[ch] = toupper(d);
			}
		}
	}

	return reverseString(expr);
}

int* getVowelsCount(string str) {
	string vowels = "aeiouy";
	int * counts = new int[6];
	for (int i = 0; i < 6; ++i) {
		counts[i] = 0;
	}
	int find = 0;
	char ch;
	for (int i = 0; i < (int)str.length(); ++i) {
		ch = tolower(str[i]);
		find = vowels.find(ch);
		if (find != -1) {
			counts[find]++;
		}
	}
	return counts;
}

string readString() {
	string readed;
	cout << "Enter a string" << endl;
	cin >> readed;
	return readed;
}

bool checkValidString(string readed) {
	if (readed.length() > 20) {
		cout << "The string's length must be less then 20" << endl;
		return false;
	}
	return true;
}

string fillString(string str) {
	if (str.length() < 20) {
		str = str.append(string(20 - str.length(), '*'));
	}
	return str;
}

string getCorrectString() {
	string readed = readString();

	while (!checkValidString(readed)) {
		readed = readString();
	}
	readed = fillString(readed);
	return readed;
}

string replaceSequenceOfChars(string str) {
	int count = 0;
	for (int ch = 0; ch < (int) str.length(); ++ch) {
		count = 1;
		for (int g = ch + 1; g < (int) str.length(); ++g) {
			if (str[g] == str[ch]) {
				count++;
			} else {
				break;
			}
		}
		if (count != 1) {
			str = str.replace(ch, count, string(1, str[ch]));
		}
	}
	return str;
}

void printCountOfLetters(string input) {
	int countOfLetters[26] = { 0 };

	char lower;
	for (int ch = 0; ch < (int) input.length(); ++ch) {
		if (isalpha(input[ch])) {
			lower = tolower(input[ch]);
			countOfLetters[lower - 97]++;
		}
	}

	for (int letter = 0; letter < 26; ++letter) {
		if (countOfLetters[letter] != 0) {
			cout << "Letter " << (char) (letter + 65) << " is repeated "
					<< countOfLetters[letter] << " times!" << endl;
		}
	}
}

string trimString(string str) {
	int index = 0;
	while (isspace(str[index])) {
		str.erase(index, 1);
	}
	index = str.length() - 1;
	while (index != -1 && isspace(str[index])) {
		str.erase(index, 1);
		index = str.length() - 1;
	}
	return str;
}

vector<string> split(string str, string delimiters) {
	vector<string> words;
	string word;
	int index;
	while (str.length() > 0) {
		index = str.find_first_of(delimiters);
		if (index == -1) {
			index = str.length();
		} else {
			str = str.erase(index, 1);
		}
		word = str.substr(0, index);
		if (!word.empty()) {
			str = str.erase(0, word.length());
			word = trimString(word);
			words.push_back(word);
		}
	}

	return words;
}

string convertToLower(string str) {
	for (int ch = 0; ch < (int) str.length(); ++ch) {
		str[ch] = tolower(str[ch]);
	}
	return str;
}

string convertToUpper(string str) {
	for (int ch = 0; ch < (int) str.length(); ++ch) {
		str[ch] = toupper(str[ch]);
	}
	return str;
}

vector<string> getUniqueWords(vector<string> words) {
	vector<string> uniqueWords;
	vector<string>::const_iterator it = words.begin();
	string element;
	while (it < words.end()) {
		element = convertToLower(*it);
		if (find(uniqueWords.begin(), uniqueWords.end(), element)
				== uniqueWords.end()) {
			uniqueWords.push_back(element);
		}
		++it;
	}

	return uniqueWords;
}

int* countUniqueWords(vector<string> allWords) {
	vector<string>::const_iterator wordIt;
	vector<string> uniqueWords = getUniqueWords(allWords);
	vector<string>::iterator uniqueIt = uniqueWords.begin();
	int* wordsCount = new int[uniqueWords.size()];
	int count, index;
	while (uniqueIt < uniqueWords.end()) {
		count = 0;
		wordIt = allWords.begin();
		while (wordIt < allWords.end()) {
			if (convertToLower(*wordIt) == *uniqueIt) {
				count++;
			}
			++wordIt;
		}
		index = uniqueIt - uniqueWords.begin();
		wordsCount[index] = count;
		++uniqueIt;
	}

	return wordsCount;
}

bool checkPalindome(string word) {
	int length = word.length();
	if (length < 2) {
		return false;
	}
	for (int ch = 0; ch < (length + 1) / 2; ++ch) {
		if (tolower(word[ch]) != tolower(word[length - 1 - ch])) {
			return false;
		}
	}
	return true;
}

vector<string> getPalindromes(vector<string> allWords) {
	vector<string> palindomes;
	vector<string>::const_iterator it = allWords.begin();
	string word;
	while (it < allWords.end()) {
		if (checkPalindome(*it)) {
			word = convertToLower(*it);
			if (find(palindomes.begin(), palindomes.end(), word)
					== palindomes.end()) {
				palindomes.push_back(word);
			}
		}
		it++;
	}
	return palindomes;
}

int countOccurrancies(string str, string substr) {
	int count = 0;
	substr = convertToLower(substr);
	str = convertToLower(str);
	int start = 0;
	int index = str.find(substr, start);
	while (index != -1) {
		count++;
		start = index + 1;
		index = str.find(substr, start);
	}

	return count;
}

string solveTags(string str, string openTag, string closeTag) {
	int start = str.find(openTag);
	int end = str.find(closeTag, start);
	while (end != -1 && start != -1) {
		int ch = start + openTag.length();
		while (ch < end) {
			str[ch] = toupper(str[ch]);
			ch++;
		}
		str = str.erase(end, closeTag.length());
		str = str.erase(start, openTag.length());
		start = str.find(openTag);
		end = str.find(closeTag, start);
	}
	return str;
}

vector<string> getSentencesWithWord(vector<string> sentences, string word) {
	string delimiters = " ,.!?\"\';:()[]-=+/\\@^&*=%$#";
	vector<string> wordsInSentence;
	vector<string> sentencesWithWord;
	vector<string>::const_iterator sentIt = sentences.begin();
	while (sentIt < sentences.end()) {
		wordsInSentence = split(*sentIt, delimiters);
		if (find(wordsInSentence.begin(), wordsInSentence.end(),
				convertToLower(word)) != wordsInSentence.end()) {
			sentencesWithWord.push_back(*sentIt);
		}
		sentIt++;
	}
	return sentencesWithWord;
}

int main() {
//	string expr = "((a+b/5-d))";
	string a = "sample";
//	cout << "Reversed string is " << reverseString(a) << endl;
//	cout << "The expression " << expr << " is valid: "
//			<< (checkExpression(expr) ? "True" : "False") << endl;
//
//	a = "BaKlAvA";
//	cout << "Original string: " << a << endl;
//	a = changeCasing(a);
//	cout << "Changed string: " << a << endl;
	a = "mkjnnhbrgvqzxasdei osaodkoadlkl lvmnjud,snj nby";
	int* countOfVolwes = getVowelsCount(a);
	cout << "Total count of a: " << countOfVolwes[0] << endl;
	cout << "Total count of e: " << countOfVolwes[1] << endl;
	cout << "Total count of i: " << countOfVolwes[2] << endl;
	cout << "Total count of o: " << countOfVolwes[3] << endl;
	cout << "Total count of u: " << countOfVolwes[4] << endl;
	cout << "Total count of y: " << countOfVolwes[5] << endl;
//
//	a = getCorrectString();
//	cout << a << endl;
//
//	a = "aaaaabbbbbcdddeeeedssaa";
//	cout << "Original string: " << a << endl;
//	a = replaceSequenceOfChars(a);
//	cout << "Replaced string: " << a << endl;
//
//	string a =
//			" Write a program that ABba a string from the console and lists all the different letters in the string with information how many times each letter is found";
//	printCountOfLetters(a);
//	string delimiters = " ,.!?\"\';:()[]-=+/\\@^&*=%$#";
//	vector<string> words = split(a, delimiters);
//	vector<string> uniqueWords = getUniqueWords(words);
//	int* wordsCount = countUniqueWords(words);
//
//	for (int i = 0; i < (int) uniqueWords.size(); ++i) {
//		cout << "The word \"" << uniqueWords[i] << "\" is repeated "
//				<< wordsCount[i] << (wordsCount[i] == 1 ? " time!" : " times!")
//				<< endl;
//	}
//
//	vector<string> palindomes = getPalindromes(words);
//	cout << "The palindomes are:" << endl;
//	for (int i = 0; i < (int) palindomes.size(); ++i) {
//		cout << palindomes[i] << endl;
//	}
//
	a = "We are living in a yellow <upcase>submarine. We don't "
			"have anything else</upcase>. Inside the submarine is "
			"very tight. So we are drinking <upcase>all the day. "
			"We will move</upcase> out of it in 5 days.";
	string substr = "are";
//	cout << "The count of \"" << substr << "\" in the string is "
//			<< countOccurrancies(a, substr) << endl;
//
	a = solveTags(a, "<upcase>", "</upcase>");
	cout << a << endl;
//
	vector<string> g = split(a, ".!?");
	for (int i = 0; i < (int) g.size(); ++i) {
		cout << g[i] << endl;
	}
	return 0;
}

