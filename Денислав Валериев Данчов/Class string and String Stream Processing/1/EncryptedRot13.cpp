#include <iostream>
#include <string>
using namespace std;

int main()
{
	string m;
	int key = 13;
	cout << "Enter a string: ";
	getline(cin, m);

	string::iterator mi = m.begin();

	while (mi != m.end())
	{
		*mi += key;
		mi++;
	}

	cout << "\nEncrypted string is: " << m << endl;

	return 0;
}
