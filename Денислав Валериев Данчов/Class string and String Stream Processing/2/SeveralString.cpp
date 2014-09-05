#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a word: ";
		cin >> s[i];
	}

	for (int j = 0; j < 5; j++)
	{

		if (((s[j].rfind("ay") == s[j].length() - 2))
				|| (s[j].rfind("r") == s[j].length() - 1))
			cout << s[j] << endl;
	}
}
