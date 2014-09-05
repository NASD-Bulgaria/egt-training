//4. Write a program that counts the total number of vowels
//in a sentence. Output the frequency of each vowel.

#include <iostream>
#include <string>
using namespace std;

int main()
{

	string str;
	int a = 0, e = 0, i =0, o = 0, u = 0;
	char ch;

	cout << "write a sentence: ";
	getline(cin, str);

	for(unsigned int j = 0; j <= str.length() - 1; j++)
	{
		ch = str.at(j);

		switch(ch)
		{
		case 'a': a++; break;
		case 'e': e++; break;
		case 'i': i++; break;
		case 'o': o++; break;
		case 'u': u++; break;
		default: break;
		}
	}

	cout << "Frequancy of a is " << a << endl;
	cout << "Frequancy of e is " << e << endl;
	cout << "Frequancy of i is " << i << endl;
	cout << "Frequancy of o is " << o << endl;
	cout << "Frequancy of u is " << u << endl;

	return 0;
}
