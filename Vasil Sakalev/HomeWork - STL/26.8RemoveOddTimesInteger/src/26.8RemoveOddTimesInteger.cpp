//8. Write a program that removes from a given
//sequence all the numbers that present in it odd
//number of times. Example:
//{4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2}  {5, 3, 3, 5}


#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
	list<int> numbers;

	numbers.push_back(4);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(5);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(2);

	int count = 0;
	list<int> removed = numbers;

	cout << "The original list is : " << endl;
	for (list<int>::iterator i = numbers.begin(); i != numbers.end(); i++) {
		cout << *i << " ";
		for (list<int>::iterator k = numbers.begin(); k != numbers.end(); k++) {

			if (*i == *k) {

				count++;
			}
		}

		if (count % 2 != 0) {
			removed.remove(*i);
		}
		count = 0;
	}
	cout << "\nThe list after removing is: " << endl;
	for (list<int>::iterator i = removed.begin(); i != removed.end(); i++) {
		cout << *i << " ";
	}

	return 0;
}
