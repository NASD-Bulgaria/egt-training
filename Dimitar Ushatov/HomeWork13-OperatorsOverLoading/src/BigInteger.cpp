/*
 * BigInteger.cpp
 *
 *  Created on: Aug 17, 2014
 *      Author: NandM
 */

#include "BigInteger.h"

unsigned int BigInteger::getSize() const {
	return size;
}

BigInteger::BigInteger() :
		size(BigInteger::initialSize) {
	pointer = new short[size];
	sign = BigInteger::positiveSign;
}

BigInteger::BigInteger(const BigInteger& value) :
		size(value.size) {
	pointer = new short[size];
	for (unsigned int i = 0; i < size; ++i) {
		pointer[i] = value.pointer[i];
	}
	sign = value.sign;
}

BigInteger::BigInteger(long value) {
	unsigned int count = getSizeOfLong(value);
	size = count == 0 ? BigInteger::initialSize : count;
	sign = value < 0 ? BigInteger::negativeSign : BigInteger::positiveSign;
	pointer = new short[size];
	pointer[0] = 0;
	int i = size - 1;
	while (value != 0) {
		pointer[i] = value % 10;
		value /= 10;
		i--;
	}
}

BigInteger::BigInteger(unsigned int size, short* ptr, char sign){
	this->sign = sign;
	this->size = size;
	this->pointer = ptr;
}
BigInteger::BigInteger(string value){
	int marker = 0;
	sign = BigInteger::positiveSign;
	size = value.length();
	if (value[0] == BigInteger::positiveSign || value[0] == BigInteger::negativeSign) {
		size = value.length() - 1;
		marker++;
		sign = value[0];
	}
	pointer = new short[size];
	for (unsigned int i = 0; i < value.length(); ++i) {
		if (!isdigit(value.at(i + marker))) {
			cerr<<"The string contains non numeric charecters!";
			exit(1);
		} else{
			pointer[i] = value[i + marker] - 48;
		}
	}
}

BigInteger& BigInteger::operator =(const BigInteger& value) {
	if (this != &value) {
		if (size != value.size) {
			delete[] pointer;
			size = value.size;
			pointer = new short[size];
		}

		for (unsigned int i = 0; i < size; ++i) {
			pointer[i] = value.pointer[i];
		}
	}

	return *this;
}

BigInteger BigInteger::operator +(const BigInteger& value) {
	short inMind = 0;
	short result;
	unsigned int firstSize = size;
	unsigned int secondSize = value.size;
	unsigned int maxSize = max(firstSize, secondSize) + 1;
	short* resultPointer = new short[maxSize];
	BigInteger a (maxSize, resultPointer, BigInteger::positiveSign);
	while (maxSize > 0) {
		result = 0;
		if (firstSize > 0) {
			result += pointer[firstSize - 1];
			firstSize--;
		}
		if (secondSize > 0) {
			result += value.pointer[secondSize - 1];
			secondSize--;
		}
		result += inMind;
		inMind = result > 9? result / 10: 0;
		result %= 10;
		resultPointer[maxSize - 1] = result;
		maxSize--;
	}
	return a;
}

//BigInteger BigInteger::operator -(const BigInteger&) {
//}
//
//BigInteger BigInteger::operator *(const BigInteger&) {
//}
//
//BigInteger BigInteger::operator /(const BigInteger&) {
//}
//
//BigInteger BigInteger::operator %(const BigInteger&) {
//}
//
//BigInteger& BigInteger::operator +=(const BigInteger&) {
//}
//
//BigInteger& BigInteger::operator -=(const BigInteger&) {
//}
//
//BigInteger& BigInteger::operator *=(const BigInteger&) {
//}
//
//BigInteger& BigInteger::operator /=(const BigInteger&) {
//}
//
//BigInteger& BigInteger::operator =(const long) {
//}
//
//BigInteger BigInteger::operator +(const long) {
//}
//
//BigInteger BigInteger::operator -(const long) {
//}
//
//BigInteger BigInteger::operator *(const long) {
//}
//
//BigInteger BigInteger::operator /(const long) {
//}
//
//BigInteger BigInteger::operator %(const long) {
//}
//
//BigInteger& BigInteger::operator +=(const long) {
//}
//
//BigInteger& BigInteger::operator -=(const long) {
//}
//
//BigInteger& BigInteger::operator *=(const long) {
//}
//
//BigInteger& BigInteger::operator /=(const long) {
//}
//
//BigInteger& BigInteger::operator ++(int int1) {
//}
//
//BigInteger BigInteger::operator ++() {
//}
//
//BigInteger& BigInteger::operator --(int int1) {
//}
//
//BigInteger BigInteger::operator --() {
//}

bool BigInteger::operator ==(const BigInteger& value) {
	if (sign != value.sign) {
		return false;
	}
	return pointer == value.pointer;
}

bool BigInteger::operator !=(const BigInteger& value) {
	if (sign != value.sign) {
		return true;
	}
	return pointer != value.pointer;
}

bool BigInteger::operator <(const BigInteger& value) {
	if (sign == BigInteger::negativeSign
			&& value.sign == BigInteger::positiveSign) {
		return true;
	} else if (sign == BigInteger::positiveSign
			&& value.sign == BigInteger::negativeSign) {
		return false;
	} else {
		if (sign == BigInteger::positiveSign) {
			return pointer < value.pointer;
		} else {
			return pointer > value.pointer;
		}
	}
}

bool BigInteger::operator >(const BigInteger& value) {
	if (sign == BigInteger::negativeSign
			&& value.sign == BigInteger::positiveSign) {
		return false;
	} else if (sign == BigInteger::positiveSign
			&& value.sign == BigInteger::negativeSign) {
		return true;
	} else {
		if (sign == BigInteger::positiveSign) {
			return pointer > value.pointer;
		} else {
			return pointer < value.pointer;
		}
	}
}

bool BigInteger::operator >=(const BigInteger& value) {
	if (*this > value || *this == value) {
		return true;
	}
	return false;
}

bool BigInteger::operator <=(const BigInteger& value) {
	if (*this < value || *this == value) {
		return true;
	}
	return false;
}

BigInteger::~BigInteger() {
	delete[] pointer;
}

bool BigInteger::operator ==(const long value) {
	BigInteger temp(value);
	return *this == temp;
}

bool BigInteger::operator !=(const long value) {
	BigInteger temp(value);
	return *this != temp;
}

bool BigInteger::operator <(const long value) {
	BigInteger temp(value);
	return *this < temp;
}

bool BigInteger::operator >(const long value) {
	BigInteger temp(value);
	return *this > temp;
}

bool BigInteger::operator >=(const long value) {
	BigInteger temp(value);
	return *this >= temp;
}

bool BigInteger::operator <=(const long value) {
	BigInteger temp(value);
	return *this <= temp;
}

void BigInteger::setSize(unsigned int size) {
	this->size = size;
}
short * BigInteger::getPointer(){
	return this->pointer;
}

unsigned int BigInteger::getSizeOfLong(long value) {
	unsigned int count = 0;
	while (value != 0) {
		value /= 10;
		count++;
	}
	return count;
}
