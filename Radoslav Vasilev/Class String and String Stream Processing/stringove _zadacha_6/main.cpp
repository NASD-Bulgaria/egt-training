#include <iostream>

using namespace std;

//Write a program that counts the total number of vowels
//in a sentence. Output the frequency of each vowel.

int main()
{
    string str = "This important fact helps to explain why pronunciation can be difficult for both native speakers and learners of English";
    int b = str.length();
    char temp;
    int count[]= {0,0,0,0,0,0};

    for(int x = 0; x < b ; x++)
    {
        temp = str.at(x);

        switch (temp)
        {
        case 'a':
            count[0]++;
            break;
        case 'e':
            count[1]++;
            break;
        case 'i':
            count[2]++;
            break;
        case 'o':
            count[3]++;
            break;
        case 'u':
            count[4]++;
            break;
        case 'y':
            count[5]++;
            break;
        default:
            break;

       }

        switch (temp)
        {
        case 'A':
            count[0]++;
            break;
        case 'E':
            count[1]++;
            break;
        case 'I':
            count[2]++;
            break;
        case 'O':
            count[3]++;
            break;
        case 'U':
            count[4]++;
            break;
        case 'Y':
            count[5]++;
            break;
        default:
            break;

       }
    }

    cout << "Letter A: " << count[0] << endl <<  "Letter E: " << count[1]<< endl <<  "Letter I: " << count[2]<< endl << "Letter O: " << count[3]<< endl << "Letter U: " << count[4]<< endl <<  "Letter Y: " << count[5]<< endl << endl;
    return 0;
}

