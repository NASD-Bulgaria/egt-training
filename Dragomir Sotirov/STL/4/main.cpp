#include <iostream>
#include <queue>

using namespace std;


int main()
{

	queue<int> numbers;
	int number;

	cout << "Enter number: ";
	cin >> number;
	numbers.push(number);

	for (int i = 0; i < 100; ++i)
	{
		numbers.push(numbers.front() + 1);
		numbers.push(2 * numbers.front() + 1);
		numbers.push(numbers.front() + 2);
		cout << numbers.front() << ' ';
		numbers.pop();
	}

	return 0;
}
