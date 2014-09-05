/* 3. Write a program that reads N integers from the
console and reverses them using a stack.*/
#include <iostream>
using namespace std;

#include <stack>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

int main() {

	std::stack< int > elemants;
	for (int i = 0; i < 5; ++i) {
		elemants.push(i);
	}
	while(!elemants.empty()){
		cout << elemants.top();
		elemants.pop();
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

//void pushElements()
