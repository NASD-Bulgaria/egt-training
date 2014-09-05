/*
 * DestructorsView.h
 *
 *  Created on: 2.09.2014 ã.
 *      Author: Admin
 */

#ifndef DESTRUCTORSVIEW_H_
#define DESTRUCTORSVIEW_H_

#include<iostream>
using namespace std;

class DestructorsView {
public:
	DestructorsView();
	virtual ~DestructorsView();
	int getValue() const;
	void setValue(int value);

private:
	int value;
};

#endif /* DESTRUCTORSVIEW_H_ */
