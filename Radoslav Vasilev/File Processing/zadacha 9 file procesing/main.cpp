#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream inFile("text.txt", ios::in);
    ifstream inFile1("text1.txt", ios::in);
    string temp="";
    string temp1="";
    int differantLines = 0;


    if ( !inFile )
    {
        cerr << "File could not be opened text.txt" << endl;
        exit( 1 );
    }
    if ( !inFile1 )
    {
        cerr << "File1 could not be opened text.txt" << endl;
        exit( 1 );
    }

    while(!inFile.eof()&&!inFile1.eof())
    {
        getline(inFile,temp);
        getline(inFile1,temp1);
        cout<<temp<<" - ";
        cout<<temp1<<endl;

        if(temp.compare(temp1) !=0)
        {
            differantLines++;


        }

        temp="";
        temp1="";

    }

    cout<<differantLines<<endl;
    inFile.close();
    inFile1.close();

    return 0;
}
