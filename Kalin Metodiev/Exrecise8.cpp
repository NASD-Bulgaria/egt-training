///*
// * Exrecise8.cpp
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
//    map<string,int> different;
//
//	ifstream readText1("text1.txt", ios::in);
//	ifstream readText2("text2.txt", ios::in);
//
//	if (!readText1 || !readText2)
//    {
//	ofstream write1("text1.txt");
////    write1 << "Imalo edno vreme edna kostenurka.\nTazi kostenurka se syztezavala s edin zaek.\nI nakraq kostenurkata pobedila.";
//	write1.clear();
//	write1.seekp(0);
//	ofstream write2("text2.txt");
////	write2 << "Imalo edno vreme edin korab.\nTozi korab bil piratski.\nI kapitana se kazval Drago.";
//	write2.clear();
//	write2.seekp(0);
//    cerr << "Creating files, please restart program.";
//	exit(1);
//	}
//
//	string text;
//	string word;
//
//
//	while (readText1 >> word)
//	{
//		text.append(word + " ");
//	}
//
//	readText1.clear();
//	readText1.seekg(0);
//	readText2.clear();
//	readText2.seekg(0);
//
//	while (readText2 >> word)
//	{
//		text.append(word + " ");
//	}
//
//	readText1.clear();
//	readText1.seekg(0);
//	readText2.clear();
//	readText2.seekg(0);
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
//			different[text]++;
//		}
//
//		map<string,int>::iterator it;
//
//		ofstream writeText("resultText.txt", ios::out);
//
//		int max = 2;
//
//		for (it = different.begin() ; it != different.end() ; it ++)
//				{
//					stringstream aa;
//					stringstream bb;
//					string result;
//					aa << it->first;
//					bb << it->second;
//					result.append(aa.str());
//
//					if (it->second < max)
//						{
//						  writeText << result <<endl;
//						}
//
//					aa<<"";
//					bb<<"";
//					result = "";
//				}
//
//		readText1.clear();
//		readText1.seekg(0);
//		readText2.clear();
//		readText2.seekg(0);
//
//		cout << "Done! Check resultText.txt"<<endl;
//
//	return 0 ;
//}
//
//
//
