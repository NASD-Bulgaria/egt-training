#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream inFile("text.txt", ios::in);
    ofstream outFile("NewText.txt", ios::out);
    string temp;
    vector <string>combine;
    if ( !inFile )
       {
           cerr << "File could not be opened text.txt" << endl;
           exit( 1 );
       }

       if ( !outFile )
       {
           cerr << "File could not be opened NewText.txt" << endl;
           exit( 1 );
       }

       while(getline(inFile,temp))
       {
           combine.push_back(temp);
       }
        sort(combine.begin(),combine.end());
        for(size_t i =0;i < combine.size();i++)
        {
            outFile<<combine[i]<<"\n";
        }

        inFile.close();
        outFile.close();
    return 0;
}

