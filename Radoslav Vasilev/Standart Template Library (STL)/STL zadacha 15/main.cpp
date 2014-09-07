#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <bitset>
using namespace std;

void display(vector <int> numbers);

int main()
{

    int a= 2;
    a= sqrt(a);
    cout<< a<<endl;
    srand(time(NULL));
    vector <int> numbers;

    for(int i =0; i < 10;i++)
    {
        numbers.push_back(rand()%20);
    }
    display(numbers);
    for(size_t i =0;i < numbers.size();i++)
    {
        if(bitset<32>(numbers[i]).count() == 1)
        {
            numbers.erase(numbers.begin()+i);
        }
    }
    display(numbers);
    return 0;
}

void display(vector <int> numbers)
{
    for(size_t i =0;i < numbers.size();i++)
    {

           cout<<setw(3)<<left<<numbers[i]<<" ";

    }
    cout<< endl;
}
