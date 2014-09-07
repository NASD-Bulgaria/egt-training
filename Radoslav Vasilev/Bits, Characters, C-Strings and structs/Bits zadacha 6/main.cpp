#include <iostream>
#include <cctype>
using namespace std;

//Write a program that inputs a character from the
//keyboard and tests the character with each
//function in the character-handling library. Print
//the value returned by each function

int main()
{
    char temp;
    cout <<"Please enter character" << endl;
    cin>>temp;

    if(isdigit(temp))
    {
        cout<< temp << " is digit"<< endl;
    }
    else
    {
        cout<< temp << " is not digit"<< endl;
    }

    if(isalpha(temp))
    {
        cout<< temp << " is alpha"<< endl;
    }
    else
    {
        cout<< temp << " is not alpha"<< endl;
    }

    if(isalnum(temp))
    {
        cout<< temp << " is digit"<< endl;
    }
    else
    {
        cout<< temp << " is alpha"<< endl;
    }

    if(isxdigit(temp))
    {
        cout<< temp << " is a hexadecimal digit character"<< endl;
    }
    else
    {
        cout<< temp << " is not a hexadecimal digit character"<< endl;
    }

    if(islower(temp))
    {
        cout<< temp << " is a lower character"<< endl;
    }
    else
    {
        cout<< temp << " is not a lower character"<< endl;
    }
    if(isupper(temp))
    {
        cout<< temp << " is a upper character"<< endl;
    }
    else
    {
        cout<< temp << " is not a upper character"<< endl;
    }

    temp =toupper(temp);
    cout<< temp << endl;


    temp =tolower(temp);
    cout<< temp << endl;


    if(isspace(temp))
    {
        cout<< temp << " is a white-space character"<< endl;
    }
    else
    {
        cout<< temp << " is not a white-space character"<< endl;
    }

    if(iscntrl(temp))
    {
        cout<< temp << " is a control character"<< endl;
    }
    else
    {
        cout<< temp << " is not a control character"<< endl;
    }

    if(ispunct(temp))
    {
        cout<< temp << " is a printing character(other than a space, a digit, or a letter)"<< endl;
    }
    else
    {
        cout<< temp << " is not a printing character"<< endl;
    }

    if(isprint(temp))
    {
        cout<< temp << " is a printing character(including space (' '))"<< endl;
    }
    else
    {
        cout<< temp << " is not a printing character"<< endl;
    }

    if(isgraph(temp))
    {
        cout<< temp << " is a printing character other than space (' ')"<< endl;
    }
    else
    {
        cout<< temp << " is not a printing character"<< endl;
    }
    return 0;
}

