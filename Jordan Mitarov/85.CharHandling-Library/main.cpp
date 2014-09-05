#include <iostream>
using namespace std;



void testLibraryFunc(char);

int main()
{
	char ch;

	cout<<"Enter a char: ";
	cin>>ch;

	testLibraryFunc(ch);

	return 0;
}

void testLibraryFunc(char ch)
{
	cout<<"Is a digit? "<<isdigit(ch)<<endl;
	cout<<"Is a alpha? "<<isalpha(ch)<<endl;
	cout<<"Is a digit or a letter? "<<isalnum(ch)<<endl;
	cout<<"Is a hex digit? "<<isxdigit(ch)<<endl;
	cout<<"Is a lower case? "<<islower(ch)<<endl;
	cout<<"Is a upper case? "<<isupper(ch)<<endl;
	ch = tolower(ch);
	cout<<"Convert to lower: "<<ch<<endl;
	ch = toupper(ch);
	cout<<"Convert to upper: "<<ch<<endl;
	cout<<"If \"ch\" is white-space,newline\"\\n\",form feed,hor tab etc.. "<<isspace(ch)<<endl;
	cout<<"If \"ch\" is a control character: "<<iscntrl(ch)<<endl;
	cout<<"If \"ch\" print char other than space ,digit or letter: "<<ispunct(ch)<<endl;
	cout<<"If \"ch\" printing char including a space(' '): "<<isprint(ch)<<endl;
	cout<<"If \"ch\" printing char other than space(' '): "<<isgraph(ch)<<endl;

}
