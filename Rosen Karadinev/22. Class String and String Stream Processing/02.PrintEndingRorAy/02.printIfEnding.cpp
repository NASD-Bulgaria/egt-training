#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{

    string words[4] = {"Rosen", "Car", "Way", "Dog"};

    for(int i = 0; i < 4; i++)
    {
         if ((( words[i].rfind( "ay" ) == words[i].length() - 2 ))
          || ( words[i].rfind( "r" ) == words[i].length() - 1 ))
         cout << words[i] << endl;
    }
}


