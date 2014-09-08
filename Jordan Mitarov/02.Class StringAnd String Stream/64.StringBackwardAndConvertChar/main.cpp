#include <iostream>
using namespace std;

int main()
{

	string str;
	cout<<"Enter a string: ";
	getline(cin,str);

	string::reverse_iterator r = str.rbegin();

	while(r!=str.rend())
	{
		if(isupper(*r))
		{
			*r = tolower(*r);
		}
		else
		{
			*r = toupper(*r);
		}
		cout<<*(r++);
	}
	cout<<endl;

	return 0;
}
