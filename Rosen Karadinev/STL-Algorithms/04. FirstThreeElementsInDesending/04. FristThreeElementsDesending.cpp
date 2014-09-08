//4. Write a program that generates a random number
//sequence and finds the first 3 elements in descending
//order.

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(0));

	int size;
	cout << "How many number you want to enter? :";
	cin >> size;

	vector<int> numbers;

	for(int i = 0; i < size; i++)
	{
		numbers.push_back(1 + rand() % 100);
	}


	cout << "The first three elments in desending order are: " << endl;

	for(int i = 0; i < size - 2; i++)
	{
		if(numbers[i] > numbers[i+1] && numbers[i+1] > numbers[i+2])
		{
			cout << numbers[i] << " " << numbers[i+1] << " " << numbers[i+2];
			break;
		}
	}

	return 0;
}
