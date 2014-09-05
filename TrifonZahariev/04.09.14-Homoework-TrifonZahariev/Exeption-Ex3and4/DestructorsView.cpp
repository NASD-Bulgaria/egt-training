/*
 * DestructorsView.cpp
 *
 *  Created on: 2.09.2014 ã.
 *      Author: Admin
 */

#include "DestructorsView.h"

DestructorsView::DestructorsView() {
	// TODO Auto-generated constructor stub
this->value = value;
}

DestructorsView::~DestructorsView() {
	// TODO Auto-generated destructor stub
	cout << "Destructor called"<<endl;
}

int DestructorsView::getValue() const {
	return value;
}

void DestructorsView::setValue(int value) {
	this->value = value;
}
