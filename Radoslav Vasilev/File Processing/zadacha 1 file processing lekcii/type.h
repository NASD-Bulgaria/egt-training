/*
 * Type.h
 *
 *  Created on: 1.09.2014 г.
 *      Author: sandjiro
 */

#ifndef TYPE_H_
#define TYPE_H_
#include <cstring>
#include <string>
#include <iostream>
using namespace std;


class Type {
private:
    int typeNumber;
    char name[10];
    int counter;
public:
    Type(int = 0, string = "", int = 0);
    virtual ~Type();
    int getTypeNumber() const;
    int getCounter() const;
    string getName() const;

    void setCounter(int counter);
    void setName(string name);
    void setTypeNumber(int typeNumber);
};

#endif /* TYPE_H_ */
