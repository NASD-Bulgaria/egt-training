#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    char temp[200];
    int count = 4;
    int num;
    int sum =0;
    while(count!=0)
    {
        cout<<"Please enter number"<< endl;
        fgets (temp, 200, stdin);
        count--;

        num=atoi(temp);
        sum +=num;
    }
    cout<<"Sum of you number is :"<< sum<<endl;
    return 0;
}

