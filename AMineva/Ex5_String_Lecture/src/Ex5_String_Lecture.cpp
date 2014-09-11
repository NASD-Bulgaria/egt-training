//============================================================================
// Name        : Ex5_String_Lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1("DOG");
	string str2("CAT");
	string str3("RABBIT");
	string str4(str2);

	cout << "str1 : " << str1 << "\nstr2 : " << str2<< "\nstr3 : " << str3 << "\nstr4 : " << str4 << "\n\n";

	if(str1 == str4) cout << "str1 == str4\n";
	else
	{
		if (str1 > str4) cout << "str1 > str4\n";
		else cout << "str1 < str4\n";
	}

	int result = str1.compare(str2);
	if (result == 0) cout << "str1.compare(str2) == 0\n";
	else
	{
		if (result > 0) cout << "str1.compare(str2) > 0\n";
		else cout << "str1.compare(str2) < 0\n";
	}

	result = str1.compare( 1, 1, str3, 2, 1 );
	if (result == 0)cout << "str1.compare(1, 1, str3, 1, 1) == 0\n";
	else
	{
		if (result > 0) cout << "str1.compare(1, 1, str3, 1, 1) > 0\n";
		else cout << "str1.compare(1, 1, str3, 1, 1) < 0\n";
	}

	result = str4.compare(0, str2.length(), str2);
	if (result == 0) cout << "str4.compare(0, string2.length(), string2) == 0" << endl;
	else
	{
		if (result > 0)cout << "str4.compare(0, string2.length(), string2) > 0" << endl;
		else cout << "str4.compare(0, string2.length(), string2) < 0" << endl;
    }

	result = str2.compare(0, 1, str4);
	if (result == 0) cout << "str2.compare(0, 1, str4) == 0" << endl;
	else
	{
		if ( result > 0 )cout << "str2.compare(0, 1, str4) > 0" << endl;
		else cout << "str2.compare(0, 1, str4) < 0" << endl;
	}

	return 0;
}
