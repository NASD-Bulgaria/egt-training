/*
 * BigInteger.h
 *
 *  Created on: Aug 17, 2014
 *      Author: NandM
 */

#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_
#include <iostream>
#include <algorithm>
using namespace std;

class BigInteger {
	friend ostream &operator<<(ostream &, const BigInteger &);
	friend istream &operator>>(istream &, BigInteger &);
public:
	BigInteger();
	BigInteger(const BigInteger&);
	BigInteger(long);
	BigInteger(string);
	BigInteger &operator = (const BigInteger& );
	BigInteger operator + (const BigInteger&);
	BigInteger operator - (const BigInteger&);
	BigInteger operator * (const BigInteger&);
	BigInteger operator / (const BigInteger&);
	BigInteger operator % (const BigInteger&);
	BigInteger &operator += (const BigInteger&);
	BigInteger &operator -= (const BigInteger&);
	BigInteger &operator *= (const BigInteger&);
	BigInteger &operator /= (const BigInteger&);
	BigInteger &operator = (const long );
	BigInteger operator + (const long);
	BigInteger operator - (const long);
	BigInteger operator * (const long);
	BigInteger operator / (const long);
	BigInteger operator % (const long);
	BigInteger &operator += (const long);
	BigInteger &operator -= (const long);
	BigInteger &operator *= (const long);
	BigInteger &operator /= (const long);
	BigInteger &operator ++ (int);
	BigInteger operator ++ ();
	BigInteger &operator -- (int);
	BigInteger operator -- ();
	bool operator == (const BigInteger&);
	bool operator != (const BigInteger&);
	bool operator < (const BigInteger&);
	bool operator > (const BigInteger&);
	bool operator >= (const BigInteger&);
	bool operator <= (const BigInteger&);
	bool operator == (const long);
	bool operator != (const long);
	bool operator < (const long);
	bool operator > (const long);
	bool operator >= (const long);
	bool operator <= (const long);

	virtual ~BigInteger();
	unsigned int getSize() const;
	void setSize(unsigned int size);
	short * getPointer();
private:
	BigInteger(unsigned int, short*, char);
	static const int initialSize = 1;
	static const char positiveSign = '+';
	static const char negativeSign = '-';
	short* pointer;
	unsigned int size;
	char sign;

	unsigned int getSizeOfLong(long);
};

#endif /* BIGINTEGER_H_ */
