#include <iostream>
using namespace std;

int main()
{
	const int size = 5;

	string str[size];

	for (int  i= 0;  i < size; i++)
	{
		cout<<"Enter a string: ";
		getline(cin,str[i]);
	}

	for (int i = 0; i < size; i++)
	{
		if(((str[i].rfind("ay") == str[i].length()-2)) || (str[i].rfind("r") == str[i].length()-1))
		{
			cout<<str[i]<<endl;
		}
	}






	return 0;
}
