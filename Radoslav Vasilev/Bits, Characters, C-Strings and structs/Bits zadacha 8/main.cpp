#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    char temp[200];
    int count = 4;
    double num;
    double sum =0.0;
    while(count!=0)
    {
        cout<<"Please enter 4 double`s"<< endl;
        fgets (temp, 200, stdin);
        count--;

        num=atof(temp);
        sum +=num;
    }
    cout<<"Sum of you number is :"<< sum<<endl;
    return 0;
}

