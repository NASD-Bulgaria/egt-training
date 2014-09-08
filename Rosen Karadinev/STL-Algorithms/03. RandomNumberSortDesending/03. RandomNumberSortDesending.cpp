//3. Write a program that generates a random number
//sequence and sorts it in descending order.

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
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

	sort(numbers.begin(), numbers.end(), greater<int>());

	cout << "\nDesending sort: " << endl;
	for(unsigned int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}

	return 0;
}
