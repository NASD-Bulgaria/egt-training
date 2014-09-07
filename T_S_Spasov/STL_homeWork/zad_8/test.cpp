#include <iostream>
#include <vector>
#include <iterator>
#include <map>

using namespace std;
int main() {

	map<int, int> mymap;
	map<int, int>::iterator it;
	vector<int> result;
	vector<int>::iterator vit;

	int myarray[] = { 1, 1, 2, 1, 2, 3, 4, 4, 5 };
	int arrSize = sizeof(myarray) / sizeof(*myarray);

	for (int i = 0; i < arrSize; ++i) {
		it = mymap.find(myarray[i]);
		if (it == mymap.end()) {
			mymap.insert(it, pair<int, int>(myarray[i], 1));
		} else {
			it->second++;
		}
	}

	for (int i = 0; i < arrSize; ++i) {
		it = mymap.find(myarray[i]);
		if (!(it->second % 2 == 0))
			result.push_back(myarray[i]);
	}

	cout << "{ ";
	for (vit = result.begin(); vit != result.end(); ++vit)
		cout << *vit << " ";
	cout << "}";

	return 0;
}

