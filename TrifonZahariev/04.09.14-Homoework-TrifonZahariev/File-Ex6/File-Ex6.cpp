////============================================================================
//// Name        : File-Ex6.cpp
//// Author      : Trifon Zahariev
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
////Modify the solution of the previous problem to replace only whole words.
//
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <string>
//using namespace std;
//
//int main() {
//
//	ifstream inText("text.txt", ios::in);
//	ofstream outResultText("resultText.txt", ios::out);
//
//	if (!inText && outResultText) {
//		cerr << "File could not be opened" << endl;
//		exit(1);
//	}
//	string text;
//
//	int position;
//
//	while (inText >> text) {
//		position = text.find("start");
//		if (position > -1)
//		{
//			if (text.length() == 5)
//			{
//				text = "finish";
//			}
//			if (text.length() > 5)
//			{
//				if (isalpha(text[5]) == false)
//				{
//					text="finish";
//				}
//			}
//		}
//
//		outResultText << text  << " ";
//		}
//
////
////		while (position != string::npos) {
////			text = text.replace(position,
////					5 , 'finish');
////			position = text.find("start");
////		}
//
//return 0;
//}
