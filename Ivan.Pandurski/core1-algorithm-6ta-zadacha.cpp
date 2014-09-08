#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<stdlib.h>
#include<ctime>

using namespace std;
int randomNum();

int main() {
	vector<int> ints(10);
	ostream_iterator<int> output(cout, " ");
	generate(ints.begin(), ints.end(), randomNum);
	copy(ints.begin(), ints.end(), output);
	cout << endl;
	make_heap(ints.begin(), ints.end());
	copy(ints.begin(), ints.end(), output);
	cout << endl;
	sort_heap(ints.begin(), ints.end());
	copy(ints.begin(), ints.end(), output);

	return 0;
}
int randomNum() {
	int num = rand() % 100;
	return num;
}
