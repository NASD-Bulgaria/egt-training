//============================================================================
// Name        : HomeWork21-STLContainers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

void solveTaskOne();

void solveTaskTwo();

void solveTaskThree();

void solveTaskFour();

void solveTaskFive();

void solveTaskSix();

void solveTaskSeven();

void solveTaskEight();

void solveTaskNine();

void solveTaskTen();

int main() {
//	solveTaskOne();
//	solveTaskTwo();
//	solveTaskThree();
//	solveTaskFour();
//	solveTaskFive();
//	solveTaskSix();
//	solveTaskSeven();
//	solveTaskEight();
//	solveTaskNine();
	solveTaskTen();
	return 0;
}

void solveTaskOne() {
	istream_iterator<int> input(cin);
	int number = -1;
	list<int> numbers;
	number = *input;
	while (number != 0) {
		if (number < 0) {
			cout << "The value must be positive!" << endl;
		} else {
			cout << "Enter a positive value!" << endl;
			numbers.push_back(number);
		}
		++input;
		number = *input;
	}

	int sum = accumulate(numbers.begin(), numbers.end(), number);

	cout << "The sum of all elements is: " << sum << " and the avarage is: "
			<< (double) sum / numbers.size() << endl;
}

void solveTaskTwo() {
	int array[17] = { 1, 1, 1, 2, 2, 2, 2, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3 };
	list<int> largestSeq;
	list<int>::iterator it = largestSeq.begin();
	for (int i = 0; i < 17; ++i) {
		if (array[i] != largestSeq.front()) {
			it = largestSeq.begin();
		}
		if (it == largestSeq.end()) {
			largestSeq.push_back(array[i]);
		} else {
			*it = array[i];
			it++;
		}
	}
	cout << largestSeq.back() << " is repeated " << largestSeq.size()
			<< " times! " << endl;
}

void solveTaskThree() {
	int n;
	cout << "Enter the size of the sequence!" << endl;
	cin >> n;
	int num;
	stack<int> stackToResize;
	while (n > 0) {
		cin >> num;
		stackToResize.push(num);
		n--;
	}

	while (!stackToResize.empty()) {
		cout << stackToResize.top()
				<< (stackToResize.size() == 1 ? "\n" : ", ");
		stackToResize.pop();
	}
}

void solveTaskFour() {
	cout << "Enter N (the first element)!" << endl;
	int n;
	cin >> n;
	cout << "Enter the number of the element to extract!" << endl;
	queue<int> sequence;
	sequence.push(n);
	int num;
	int step = 0;
	while (step < 99) {
		num = sequence.front();
		cout << num << " ";
		sequence.pop();
		sequence.push(num + 1);
		step++;
		sequence.push(2 * num + 1);
		step++;
		sequence.push(num + 2);
		step++;
	}
	while (!sequence.empty()) {
		cout << sequence.front() << " ";
		sequence.pop();
	}
}
template<typename T>
static bool sortHelper(T first, T second) {
	return first < second;
}

void solveTaskFive() {
	int n;
	cout << "Enter n!" << endl;
	cin >> n;
	int num;
	list<int> numbers;
	while (n > 0) {
		cin >> num;
		numbers.push_back(num);
		n--;
	}
	numbers.sort(sortHelper<int>);
	ostream_iterator<int> output(cout, " ");
	copy(numbers.begin(), numbers.end(), output);
	cout << endl;
}

void solveTaskSix() {
	const int size = 9;
	int array[size] = { 3, 4, 4, 2, 3, 3, 4, 3, 2 };
	map<int, int> unique;
	for (int i = 0; i < size; ++i) {
		if (unique.find(array[i]) == unique.end()) {
			unique.insert(pair<int, int>(array[i], 0));
		}
		unique[array[i]]++;
	}

	for (map<int, int>::iterator it = unique.begin(); it != unique.end();
			++it) {
		cout << it->first << " is repeated " << unique[it->first] << " times!"
				<< endl;
	}
}

bool isNegative(int number) {
	return number < 0;
}

void solveTaskSeven() {
	int array[] = { 1, 2, 3, 5, -1, -2, 5, -4 };

	list<int> nonNegative(array, array + 8);

	nonNegative.remove_if(isNegative);

	ostream_iterator<int> output(cout, " ");
	copy(nonNegative.begin(), nonNegative.end(), output);
}

void solveTaskEight() {
	int array[] = { 4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2 };
	list<int> evenCountNumbers(array, array + 11);
	set<int> unique(array, array + 11);
	for (set<int>::iterator it = unique.begin(); it != unique.end(); ++it) {
		if (count(evenCountNumbers.begin(), evenCountNumbers.end(), *it) % 2
				== 1) {
			evenCountNumbers.remove(*it);
		}
	}

	ostream_iterator<int> output(cout, " ");
	copy(evenCountNumbers.begin(), evenCountNumbers.end(), output);
}

void solveTaskNine() {
	int array[] = { 2, 2, 3, 3, 2, 3, 4, 3, 3 };
	list<int> evenCountNumbers(array, array + 9);
	set<int> unique(array, array + 9);
	int majorant = 0;
	bool isFind = false;
	for (set<int>::iterator it = unique.begin(); it != unique.end(); ++it) {
		if (count(evenCountNumbers.begin(), evenCountNumbers.end(), *it)
				>= (int) (evenCountNumbers.size() + 1) / 2) {
			majorant = *it;
			isFind = true;
			break;
		}
	}
	if (isFind) {
		cout << "The majorant of the seq is: " << majorant << endl;
	} else {
		cout << "No majorant found!" << endl;
	}
}

void findShortestPath(int m, int n) {
	if (m < n) {
		return;
	}
	if (m >= n) {
		cout << m << " ";
		findShortestPath(m / 2, n);
		findShortestPath(m - 2, n);
		findShortestPath(m - 1, n);
	}
}

void solveTaskTen() {
	findShortestPath(22, 5);
}
