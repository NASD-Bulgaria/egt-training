/*
 * Integer.h
 *
 *  Created on: 26.08.2014 ã.
 *      Author: Admin
 */

#ifndef INTEGER_H_
#define INTEGER_H_

class Integer {
public:
	Integer(int i = 0); // Integer default constructor
	~Integer(); // Integer destructor
	void setInteger(int i); // functions to set Integer
	int getInteger() const; // function to return Integer
private:
	int value;
};

#endif /* INTEGER_H_ */
