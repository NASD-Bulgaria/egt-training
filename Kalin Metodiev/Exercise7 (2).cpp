///*
// * Exercise7.cpp
// *
// *  Created on: 9.09.2014 г.
// *      Author: стаса
// */
//
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <map>
//#include <sstream>
//#include <string>
//#include <algorithm>
//#include <set>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    multiset<string> sortedWords;
//
//	ifstream readText("text.txt", ios::in);
//
//	if (!readText)
//    {
//	ofstream write("text.txt");
//	write.clear();
//	write.seekp(0);
//    cerr << "Creating file, please restart program.";
//	exit(1);
//	}
//
//	string text;
//	string word;
//
//	while (readText >> word)
//	{
//		text.append(word + " ");
//	}
//
//	unsigned position = text.find_first_of(".,?!-:();\"", 0);
//
//	while (position != string::npos)
//	{
//		text.replace(position, 1, "");
//		position = text.find_first_of(".,?!-:();\"", position);
//	}
//
//	for (unsigned i = 0; i < text.size(); i++)
//	{
//		char ch = text.at(i);
//		ch = tolower(ch);
//		text.at(i) = ch;
//	}
//
//	    stringstream ss;
//		ss.str(text);
//
//		while (ss >> text)
//		{
//           sortedWords.insert(text);
//		}
//
//		multiset<string>::iterator it;
//
//		ofstream writeText("resultText.txt", ios::out);
//
//		for (it = sortedWords.begin() ; it != sortedWords.end() ; it ++)
//		{
//               writeText << *it << " ";
//		}
//
//		readText.clear();
//		readText.seekg(0);
//
//	return 0 ;
//}
//
//
//
