//============================================================================
// Name        : core1-string-6ta-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string str;
	vector<int> count(6);
	count[0]=0;
	count[1]=0;
	count[2]=0;
	count[3]=0;
	count[4]=0;
	count[5]=0;
	getline(cin,str);
	for(int i=0;i<str.length();i++)
	{
		if(isupper(str.at(i)))
				{
					str.at(i)=tolower(str.at(i));
				}
	}
	for(int i=0;i<str.length();i++)
	{
		switch(str.at(i))
		{
		case 'a':count[0]+=1;break;
		case 'e':count[1]+=1;break;
		case 'i':count[2]+=1;break;
		case 'o':count[3]+=1;break;
		case 'u':count[4]+=1;break;
		case 'y':count[5]+=1;break;
		}
	}
	cout<<"The number of vowel a in the sentence is "<<count[0]<<endl;
	cout<<"The number of vowel e in the sentence is "<<count[1]<<endl;
	cout<<"The number of vowel i in the sentence is "<<count[2]<<endl;
	cout<<"The number of vowel o in the sentence is "<<count[3]<<endl;
	cout<<"The number of vowel u in the sentence is "<<count[4]<<endl;
	cout<<"The number of vowel y in the sentence is "<<count[5]<<endl;




	return 0;
}
