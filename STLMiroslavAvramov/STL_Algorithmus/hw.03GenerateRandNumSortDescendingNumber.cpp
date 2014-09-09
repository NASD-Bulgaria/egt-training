/* 3. Write a program that generates a random number
 sequence and sorts it in descending order.*/
#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <random>

#include <vector>
#include <algorithm> // algorithm definitions
#include <iterator> // ostream_iterator
using namespace std;

int nextDigit();

int main() {

	srand(time(0));

	vector<int> randNum(10);
	std::ostream_iterator<int> output(cout, " ");
	std::generate(randNum.begin(), randNum.end(), nextDigit);

	std::copy(randNum.begin(), randNum.end(), output);
	sort(randNum.begin(),randNum.end());
	reverse(randNum.begin(),randNum.end());

//	for (int i = 0; i < 10; ++i) {
//		cout << randNum[i]<< " ";
//	}

	return 0;
}

int nextDigit() {
	int next = rand()%20;
	return next;
}
