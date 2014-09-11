//============================================================================
// Name        : Ex6_String_Lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
# include <string>
using namespace std;

int main()
{
	static const int size = 5;
	string str = "This exercise is for counting of vowels.";
	char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	int count[] = {0, 0, 0, 0, 0};
	int total = 0;

	for(int i=0; i<str.length(); i++) str[i]=tolower(str[i]);

	for(int i=0; i<size; i++)
	{
		for(int j=0; j<str.length(); j++)
		{
			if(str[j] == vowels[i])
			{
				count[i]++;
				total++;
			}
		}
	}

	for(int i=0; i<size; i++) cout<<vowels[i]<<" - "<<count[i]<<endl;

	cout<<"Total vowels is : "<<total;

	return 0;
}
