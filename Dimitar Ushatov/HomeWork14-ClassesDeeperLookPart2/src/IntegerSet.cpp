/*
 * IntegerSet.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#include "IntegerSet.h"

IntegerSet::IntegerSet() {
	this->internalArray = new int[101];
}

IntegerSet::IntegerSet(const int* const array, int size) {
	this->internalArray = new int[100];
	for (int i = 0; i < size; ++i) {
		this->internalArray[array[i]] = 1;
	}
}

IntegerSet* IntegerSet::unionSets(IntegerSet fisrtSet, IntegerSet secondSet) {
	IntegerSet *newIntegerSet = new IntegerSet();
	for (int i = 0; i <= 100; ++i) {
		newIntegerSet->internalArray[i] = fisrtSet.internalArray[i]
				|| secondSet.internalArray[i];
	}

	return newIntegerSet;
}

IntegerSet* IntegerSet::intersectionOfSets(IntegerSet fisrtSet,
		IntegerSet secondSet) {
	IntegerSet *newIntegerSet = new IntegerSet();
	for (int i = 0; i <= 101; ++i) {
		newIntegerSet->internalArray[i] = fisrtSet.internalArray[i]
				& secondSet.internalArray[i];
	}

	return newIntegerSet;
}

int* IntegerSet::getInternalArray() const {
	return this->internalArray;
}

void IntegerSet::setInternalArray(const int* const internalArray) {
	for (int i = 0; i < 101; ++i) {
		this->internalArray[i] = internalArray[i];
	}
}

void IntegerSet::insertElement(int element) {
	if (element >= 0 && element <= 101) {
		this->internalArray[element] = 1;
	}
}

void IntegerSet::deleteElement(int element) {
	if (element >= 0 && element <= 101) {
		this->internalArray[element] = 0;
	}
}

void IntegerSet::printSet() {
}

bool IntegerSet::isEqualTo(const IntegerSet* const integerSet) {
	for (int i = 0; i < 101; ++i) {
		if (this->internalArray[i] != integerSet->internalArray[i]) {
			return false;
		}
	}
	return true;
}

IntegerSet::~IntegerSet() {
	delete[] this->internalArray;
}

