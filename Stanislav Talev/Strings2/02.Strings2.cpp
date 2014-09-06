#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> fewStrings;

	cout<<"Enter a string: "<<endl;
	string str1 = "";
	getline(cin, str1);
	fewStrings.push_back(str1);

	cout<<"Enter a string: "<<endl;
	string str2 = "";
	getline(cin, str2);
	fewStrings.push_back(str2);

	cout<<"Enter a string: "<<endl;
	string str3 = "";
	getline(cin, str3);
	fewStrings.push_back(str3);

	for(unsigned i = 0; i < fewStrings.size(); i++)
	{
		string temp = fewStrings[i];
		string clearTemp = "";
		for(unsigned j = 0; j < temp.length(); j++)
		{
			char ch = temp[j];
			if(isalpha(ch))
			{
				clearTemp += ch;
			}
		}
		//cout<<clearTemp;
		if(clearTemp[clearTemp.length() - 1] == 'r' || (clearTemp[clearTemp.length() - 1] == 'y' && clearTemp[clearTemp.length() - 2] == 'a'))
		{
			cout<<temp<<endl;
		}
	}
	return 0;
}
