/*
 * Array.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: NandM
 */

#include "Array.h"
template<typename T>
Array<T>::Array(int size) {
	this->size = (size > 0 ? size : 5);
	this->ptr = new T[size];
	for (int i = 0; i < size; ++i) {
		ptr[i] = 0;
	}
}


template<typename T>
int Array<T>::getSize() const {
	return size;
}

template<typename T>
T& Array<T>::operator [](int index) {
	if (index > size - 1 || index < 0) {
		cerr << "The index is outside the boundaries of the array!"<<endl;
		exit(1);
	}
	return ptr[index];
}

template<typename T>
T Array<T>::operator [](int index) const {
	if (index > size - 1 || index < 0) {
		cerr << "The index is outside the boundaries of the array!"<<endl;
		exit(1);
	}
	return ptr[index];
}
template<typename T>
Array<T>::~Array() {
	delete[] ptr;
	ptr = 0;
}
