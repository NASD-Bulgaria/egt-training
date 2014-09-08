#include <iostream>
using namespace std;

int main()
{

	string str;
	int key = 13;

	cout<<"Enter a string to encrypt: ";
	getline(cin,str);

	string::iterator mi = str.begin();

	while(mi != str.end())
	{
		*mi =  *mi + key;
		mi++;
	}

	cout<<"Encrypted string is: "<<str;

	cout<<"\nEnter string to decrypt: ";
	getline(cin,str);
	string::iterator mii = str.begin();

	while(mii != str.end())
	{
		*mii =  *mii - key;
		mii++;
	}

	cout<<"Decrypted string is: "<<str;

	return 0;
}
