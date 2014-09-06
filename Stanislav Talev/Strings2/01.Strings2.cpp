#include <iostream>
using namespace std;

int main()
{
//	cout<<(int)('a') + 13<<endl;
//	cout<<'a' + (((int)('o') + 13) % 122)<<endl;
//	cout<<'a' + 13<<endl;
//	cout<<(char)110<<endl;

	//CRYPTING MESSAGE

	cout<<"Enter a message: ";
	string message = "";
	getline(cin, message);

	string crypto = "";

	for(unsigned i = 0; i < message.length(); i++)
	{
		char ch = message[i];
		if(isalpha(ch))
		{
			if((int)ch >= 97 && (int)ch <=122)
			{
				if((int)(ch) + 13 > 122)
				{
					ch = 'a' + ((ch + 13) % 122);
				}
				else
				{
					ch = ch + 13;
				}
				//cout<<ch;
			}

			if((int)ch >= 65 && (int)ch <=90)
			{
				if((int)(ch) + 13 > 90)
				{
					ch = 'A' + ((ch + 13) % 90);
				}
				else
				{
					ch = ch + 13;
				}
				//cout<<ch;
			}
		}
		crypto += ch;
	}

	cout<<"Decrypted message: "<<crypto<<endl;

	//DECRYPTING MESSAGE

	cout<<"Enter a message: ";
	string message2 = "";
	getline(cin, message2);

	string decrypto = "";

	for(unsigned i = 0; i < message2.length(); i++)
	{
		char ch2 = message2[i];
		if(isalpha(ch2))
		{
			if((int)ch2 >= 97 && (int)ch2 <= 122)
			{
				if((int)(ch2) - 13 < 97)
				{
					ch2 += 12;
				}
				else
				{
					ch2 = ch2 - 13;
				}
				//cout<<ch;
			}

			if((int)ch2 >= 65 && (int)ch2 <= 90)
			{
				if((int)(ch2) - 13 < 65)
				{
					ch2 += 12;
				}
				else
				{
					ch2 = ch2 - 13;
				}
				//cout<<ch;
			}
		}
		decrypto += ch2;
	}

	cout<<"Encrypted message: "<<decrypto<<endl;


	return 0;
}
