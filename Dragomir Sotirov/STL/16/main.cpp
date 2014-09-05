#include <iostream>
#include <vector>

using namespace std;

int main()
{
 vector<int> numbers;
 int number = 1;
 int n;

 cout << "Enter Repeatable number of times to erase later from array:";
 cin >> n;
 cout << "Enter Integers: " << endl << "(0)-Zero Breaks" <<endl;

 while (number != 0)
 {

  cout << "Number :";
  cin >> number;

	 if (number == 0)
	 {
		 break;
	 }

  numbers.push_back(number);

 }

 int counter = 0;
 int theNumber = 0;

cout << "Searching for N-Times:"<< n << " Repeatable Numbers..." <<endl;

for (int i = 0; i < 9; i++)
{
    for (int j = 0; j < 9; j++)
    {
       if (numbers[i] == numbers[j] )
       {
    	   counter++;
       }
    }

    if (counter == n)
    {
    	cout << "Found N-Times Number..." <<endl;
    	theNumber = numbers[i];
    }

    counter = 0;
}

for (unsigned int i = 0; i < numbers.size(); i++)
{
	if (numbers[i] == theNumber)
	{
		numbers.erase(numbers.begin() + i);
		i--;
	}
}

cout << "Printing only non N-Times Repeatble Integers: ";

for (unsigned int i = 0; i < numbers.size(); i++)
{
		cout << numbers[i]<<" ";
}

 return 0;
}
