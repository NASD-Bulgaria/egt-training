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

	sort(randomNumbers.begin(), randomNumbers.end(), greater<int>());

	cout << "The descending order of numbers: \n";
	for (unsigned i = 0; i < randomNumbers.size(); i++) {
		cout << randomNumbers[i] << " ";
	}
}
