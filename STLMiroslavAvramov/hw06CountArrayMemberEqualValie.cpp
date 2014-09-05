/* 6. Write a program that finds in a given array of integers how
 many times each of them presents.
 Example: array = {3, 4, 4, 2, 3, 3, 4, 3, 2}
 2 -> 2 times
 3  4 times
 4  3 times*/
#include <iostream>
#include <map>
using namespace std;

//bool seearchInMap(map<int, int> search, int value ){
//	for ( map<int, int>::const_iterator iter = search.begin(); iter != search.end(); ++iter ){
//			if (*iter == value) {
//				return true;
//			}
//		}
//	return false;
//}

int main() {

	 map<int, int>::const_iterator iter;
	    int const size = 10;
	    std::map<int , int> search;
	    int array[size] = { 2, 1, 1, 2, 3, 3, 2, 2, 2, 1 };
	    for (int i = 0; i < 10; i++) {
	        if(search.find(array[i]) != search.end()){
	            ++search[array[i]];
	        }
	        else {
	            // http://www.cplusplus.com/reference/map/map/insert/
	            search.insert(std::pair<int,int>(array[i], 1));
	        }
	    }
	    for (  iter = search.begin(); iter != search.end(); ++iter )
	     cout << iter->first << '\t' << iter->second << '\n';


//	map<int, int>::const_iterator iter;
//	int const size = 10;
//	std::map<int , int> search;
//	int array[size] = { 2, 1, 1, 2, 3, 3, 2, 2, 2, 1 };
//	for (int i = 0; i < 10; i++) {
//		if(seearchInMap(map, array[i])){
//			search[array[i]]++;
//		}
//		else {
//			search.insert(array[i], 1);
//		}
//	}

//	 cout << iter->first << '\t' << iter->second << '\n';

	return 0;
}
