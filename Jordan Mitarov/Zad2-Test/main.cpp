#include <iostream>
using namespace std;

int main()
{

	char str1[10], str2[20];

	//primer : abcd.efgh.klmn.

	/*cin.get(str1, 10,'.').get(str2, 10, '.');
	cout << "str1: " << str1 << "\nstr2: " << str2 << endl;*/

	 cin.getline(str1, 10,'.').getline(str2, 10, '.');
	 cout << "str1: " << str1 << "\nstr2: " << str2 << endl;



	return 0;
}
