//============================================================================
// Name        : RemoveNumberOddNumberOfTime.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <set>
#include <deque>
using namespace std;

void display(deque<int> &);
void eraseFromDeque(deque<int> &, int);

int main()
{
	deque <int> tempDeque;
	multiset<int> tempMultiset;
	int temp;
	int array[11] = {4,2,2,5,2,3,2,3,1,5,2};

	for (int i = 0; i < 11; ++i) {
		tempDeque.push_back(array[i]);
		tempMultiset.insert(array[i]);
	}

	for (multiset<int>::iterator it = tempMultiset.begin(); it != tempMultiset.end(); ++it){
		temp = tempMultiset.count(*it);
		if (temp % 2 != 0 ) {
			eraseFromDeque(tempDeque, *it);
		}
	}

	display(tempDeque);

    return 0;
}

void display(deque<int> &temp){
	cout << endl;
    for(size_t i = 0; i < temp.size() ;i++){
       cout << setw(5)<< temp[i];
    }
    cout<< endl;
}

void eraseFromDeque(deque<int>& tempDeque, int velue) {
	for (deque<int>::iterator it = tempDeque.begin(); it != tempDeque.end(); ++it){
		if (*it == velue) {
			tempDeque.erase(it);
			break;
		}
	}
}
