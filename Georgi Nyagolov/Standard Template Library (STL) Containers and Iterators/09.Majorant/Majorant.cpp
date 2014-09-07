//============================================================================
// Name        : Majorant.cpp
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

int main()
{
	deque <int> tempDeque;
	multiset<int> tempMultiset;
	int temp;
	int maxCount = 0;
	int majorant = 0;
	int array[11] = {2,2,2,2,2,3,2,3,1,5,8};

	for (int i = 0; i < 11; ++i) {
		tempDeque.push_back(array[i]);
		tempMultiset.insert(array[i]);
	}

	for (multiset<int>::iterator it = tempMultiset.begin(); it != tempMultiset.end(); ++it){
		temp = tempMultiset.count(*it);
		if ((unsigned)temp > (tempMultiset.size()/2) && temp > maxCount) {
			maxCount = temp;
			majorant = *it;
		}
	}

	display(tempDeque);
	cout << "Majorant is: " << majorant;

    return 0;
}

void display(deque<int> &temp){
	cout << endl;
    for(size_t i = 0; i < temp.size() ;i++){
       cout << setw(5)<< temp[i];
    }
    cout<< endl;
}

