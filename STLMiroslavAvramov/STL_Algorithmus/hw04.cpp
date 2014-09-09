/*4. Write a program that generates a random number
 sequence and finds the first 3 elements in descending
 order.
 17 16 16 16 10 8 6 5 2 2
First tree elements in descending order are :16 10 8*/
#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <random>

#include <vector>
#include <algorithm> // algorithm definitions
#include <iterator> // ostream_iterator
using namespace std;

int nextDigit();
void findFirstTreeElementInDecendingOrder(vector<int> r);

int main() {

	srand(time(0));

	vector<int> randNum(10);
	std::ostream_iterator<int> output(cout, " ");
	std::generate(randNum.begin(), randNum.end(), nextDigit);

	sort(randNum.begin(), randNum.end());
	reverse(randNum.begin(), randNum.end());
	std::copy(randNum.begin(), randNum.end(), output);

	findFirstTreeElementInDecendingOrder(randNum);

	return 0;
}

int nextDigit() {
	int next = rand() % 20;
	return next;
}

void findFirstTreeElementInDecendingOrder(vector<int> r){
	for (int i = 0; i < 10; ++i) {
		if (r[i] > r[i + 1]) {
			if (r[i + 1] > r[i + 2]) {
				cout<< "\nFirst tree elements in descending order are :" <<r[i]<< " "<< r[i+1]<< " "<< r[i+2];
				break;
			}
		}
	}
}
