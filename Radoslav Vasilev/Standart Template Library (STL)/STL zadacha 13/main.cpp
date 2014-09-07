#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#define size 10

using namespace std;
static int arr[] = {6, 3, 2, 3, 4, 7, 1, 3, 5,3};
void display(int,int);
int main()
{
    list<int> numbers;
    numbers.insert(numbers.begin(), arr, arr + size);

    int previousPosition = arr[0];
    int currentPosition;
    int sequenceEndPosition;
    int maxSeq = 0;
    int count = 1;
    int countIt = 0;


    list<int>::iterator it;

    for(it = numbers.begin(); it != numbers.end(); it++)
    {
        currentPosition = *it;
        countIt++;

        if(currentPosition > previousPosition)
        {
            count++;
            if(count > maxSeq)
            {
                maxSeq = count;
                sequenceEndPosition = countIt;
            }

        }

        else
        {
            count = 1;
        }
        previousPosition = currentPosition;
    }
        display(maxSeq, sequenceEndPosition);

    return 0;
}

void display(int maxSeq,int sequenceEndPosition)
{
    cout << "Max sequence in this array is: "<< maxSeq<<endl;
    cout<< "With this numbers "<<endl;
    for(int i = sequenceEndPosition - maxSeq; i < sequenceEndPosition; i++)
    {
        cout<<arr[i]<<" ";
    }
}
