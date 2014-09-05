/*
 * IntegerSet.h
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#ifndef INTEGERSET_H_
#define INTEGERSET_H_

class IntegerSet {
public:
	IntegerSet();
	IntegerSet(const int* const, int);
	static IntegerSet* unionSets(IntegerSet, IntegerSet);
	static IntegerSet* intersectionOfSets(IntegerSet, IntegerSet);

	int* getInternalArray() const;

	void setInternalArray(const int* const internalArray);

	void insertElement(int);
	void deleteElement(int);
	void printSet();
	bool isEqualTo(const IntegerSet* const);

	virtual ~IntegerSet();

private:
	int * internalArray;
};

#endif /* INTEGERSET_H_ */
