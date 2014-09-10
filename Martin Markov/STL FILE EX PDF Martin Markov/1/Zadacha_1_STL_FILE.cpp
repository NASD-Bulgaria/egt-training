/*
 * Zadacha_1_STL_FILE.cpp
 *
 *  Created on: 9.09.2014 ã.
 *      Author: Marty
 */
#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
using namespace std;

int main() {
	ifstream in("input.txt",ios::in);
	string words;
	while(!in.eof())
	{
		getline(in,words);
	}
	int unsigned index=words.find_first_of(",.!?-");
		while(index<=words.length())
		{
			words.erase(index,1);
			index=words.find_first_of(",.!?-",index+1);
		}
		stringstream ss(words);
		ofstream out("output.txt",ios::out);

		do {
				string sub;
				ss >> sub;
				string oneByOne = sub;

					for(int unsigned i=1;i<oneByOne.length();i++)
					{
						if(isupper(oneByOne.at(0))) //at(0) vzima purvata poziciq

						{
						oneByOne[i]='*';

						}
					}

					out<<oneByOne<<" ";



			} while (ss);





	return 0;
}

