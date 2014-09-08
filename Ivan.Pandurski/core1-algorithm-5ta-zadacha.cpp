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
	vector<int>::reverse_iterator p;
	generate(ints.begin(), ints.end(), randomNum);
	copy(ints.begin(), ints.end(), output);
	int n;
	cout << "Enter n ";
	cin >> n;
	int k = ints[n];
	vector<int> vec1;
	vector<int> vec2;
	vector<int> result;
	for (int i = 0; i < ints.size(); i++) {
		if (ints[i] <= k) {
			vec1.push_back(ints[i]);
		} else {
			vec2.push_back(ints[i]);
		}
	}
	sort(vec1.begin(),vec1.end());
	for (int i = 0; i < vec1.size(); i++) {
		result.push_back(vec1[i]);
	}
	for (int i = 0; i < vec2.size(); i++) {
		result.push_back(vec2[i]);
	}
	copy(result.begin(), result.end(), output);

	return 0;
}
int randomNum() {
	int num = rand() % 100;
	return num;
}
