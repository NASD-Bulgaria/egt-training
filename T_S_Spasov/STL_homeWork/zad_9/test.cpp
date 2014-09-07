#include <iostream>
#include <iterator>
#include <map>

using namespace std;
int main() {

	map<int, int> mymap;
	map<int, int>::iterator it;

	int myarray[] = { 1, 1, 2, 1, 2, 3, 4, 4, 4, 4, 4 };
	int arrSize = sizeof(myarray) / sizeof(*myarray);

	for (int i = 0; i < arrSize; ++i) {
		it = mymap.find(myarray[i]);
		if (it == mymap.end()) {
			mymap.insert(it, pair<int, int>(myarray[i], 1));
		} else {
			it->second++;
		}
	}

	cout << "The majorant is: ";
	for (std::map<int, int>::iterator it = mymap.begin(); it != mymap.end();
			++it) {
		if (it->second >= arrSize / 2)
			cout << it->first << '\n';
	}

	return 0;
}

