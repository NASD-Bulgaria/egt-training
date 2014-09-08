/*
 * IPrintable.h
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#ifndef IPRINTABLE_H_
#define IPRINTABLE_H_
#include <iostream>
using namespace std;


class IPrintable {
public:
	IPrintable();
	virtual ~IPrintable();

	virtual string getInfo() = 0;

};

#endif /* IPRINTABLE_H_ */
