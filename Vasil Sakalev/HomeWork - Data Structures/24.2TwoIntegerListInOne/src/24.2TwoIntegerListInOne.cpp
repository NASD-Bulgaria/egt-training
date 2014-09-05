#include <iostream>
#include <functional>
#include <list>
#include <ctime>
#include <cstdlib>

using namespace std;

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list) {
	for (auto &i : list) {
		ostr << " " << i;
	}
	return ostr;
}

int main() {
	srand(time(0));
	std::list<int> list;

	int sum = 0;
	float average;

	for (int i = 0; i < 25; i++) {
		int temp = 1 + rand() % 100;
		list.push_back(temp);
		sum += temp;

	}

	cout << "before:     " << list << "\n";
	list.sort();
	cout << "ascending:  " << list << "\n";

	cout << "The sum is " << sum << endl;
	average = (float) sum / 25;
	cout << "The average is " << average;

	return 0;
}

