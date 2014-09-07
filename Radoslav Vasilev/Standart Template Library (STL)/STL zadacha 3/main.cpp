#include <iostream>
#include <string>
#include <vector>

#include <stack>

using namespace std;

int main()
{

    stack<int> numbers;
    int num = 0;
    int check = 1;

    while (check ==1)
    {


        cout << "Enter Number: ";
        cin >> num;

        numbers.push(num);
       cout << "do you want to continue 1- yes / 0- no"<<endl;
       cin>> check;
    }


    while (!numbers.empty())
    {

       cout << numbers.top() << " ";
       numbers.pop();
       cout <<"\n";
    }

    return 0;
}
