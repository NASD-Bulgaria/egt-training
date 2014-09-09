//4. Write a program that generates a random number
//sequence and finds the first 3 elements in descending
//order.

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {

	srand(time(0));
	cout << "Enter the count of numbers : ";
	int size;
	cin >> size;

	vector<int> randomNumbers;

	for (int i = 0; i < size; i++) {

		randomNumbers.push_back(rand() & 100);
	}

	cout << "The first 3 numbers in descending order : \n";
	for (unsigned i = 0; i < randomNumbers.size() - 2; i++) {

		if (randomNumbers[i] > randomNumbers[i + 1]
				&& randomNumbers[i + 1] > randomNumbers[i + 2]) {

			cout << randomNumbers[i] << " " << randomNumbers[i + 1] << " "
					<< randomNumbers[i + 2] << endl;
			break;
		}
	}
	return 0;
}
