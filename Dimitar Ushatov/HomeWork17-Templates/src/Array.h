/*
 * Array.h
 *
 *  Created on: Aug 25, 2014
 *      Author: NandM
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include <cstdlib>
#include <iostream>
using namespace std;

template<typename T>
class Array {
public:
	Array(int = 5);
	~Array();
	int getSize() const;
	T &operator [](int index);
	T operator [](int index) const;

private:
	T * ptr;
	int size;
};
#endif /* ARRAY_H_ */
