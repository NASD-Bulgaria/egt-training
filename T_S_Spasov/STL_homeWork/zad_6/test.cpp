#include <iostream>
#include <list>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
using namespace std;
int main() {

	map<int, int> mymap;
	map<int, int>::iterator it;


	int myarray[] = { 1, 1, 2, 1, 2, 3, 4, 4, 4, 4, 4 };
    int arrSize = sizeof(myarray)/sizeof(*myarray);

	for (int i = 0; i < arrSize; ++i) {
        it =  mymap.find(myarray[i]);
		if (it == mymap.end()) {

			 mymap.insert (it, pair<int,int>(myarray[i],1));

		} else {
			it->second++;
		}

	}


	for (std::map<int, int>::iterator it = mymap.begin(); it != mymap.end();
			++it)
		std::cout << it->first << " => " << it->second << '\n';



	return 0;
}

