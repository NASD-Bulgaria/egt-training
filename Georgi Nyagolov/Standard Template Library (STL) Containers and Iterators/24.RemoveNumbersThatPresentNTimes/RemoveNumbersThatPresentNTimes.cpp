//============================================================================
// Name        : RemoveNumbersThatPresentNTimes.cpp
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

template<typename T>
void display(deque<T> &);
template<typename T>
void eraseFromDeque(deque<T> &, T);

int main()
{
	deque <int> tempDeque;
	multiset<int> tempMultiset;
	int temp;
	int nTimes;
	int array[12] = {4,2,2,5,2,3,2,3,1,5,2,8};

	cout << "Enter N: ";
	cin >> nTimes;

	for (int i = 0; i < 12; ++i) {
		tempDeque.push_back(array[i]);
		tempMultiset.insert(array[i]);
	}

	display(tempDeque);

	for (multiset<int>::iterator it = tempMultiset.begin(); it != tempMultiset.end(); ++it){
		temp = tempMultiset.count(*it);
		if (temp == nTimes ) {
			eraseFromDeque(tempDeque, *it);
		}
	}

	display(tempDeque);

    return 0;
}

template<typename T>
void display(deque<T> &temp){
	cout << endl;
    for(size_t i = 0; i < temp.size() ;i++){
       cout << setw(5)<< temp[i];
    }
    cout<< endl;
}


template<typename T>
void eraseFromDeque(deque<T>& tempDeque, T velue) {
	for (deque<int>::iterator it = tempDeque.begin(); it != tempDeque.end(); ++it){
		if (*it == velue) {
			tempDeque.erase(it);
			break;
		}
	}
}
