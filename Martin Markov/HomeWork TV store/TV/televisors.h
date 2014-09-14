/*
 * televisors.h
 *
 *  Created on: 14.09.2014 ã.
 *      Author: Marty
 */

#ifndef TELEVISORS_H_
#define TELEVISORS_H_
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class televisors {
public:
	televisors(string="",string ="",string="",int=0,double =0.0);
	virtual ~televisors();

	const string& getBrand() const;
	void setBrand(const string& brand);

	const string& getColor() const;
	void setColor(const string& color);

	int getHertz() const;
	void setHertz(int hertz);

	double getInch() const;
	void setInch(double inch);

	const string& getModel() const;
	void setModel(const string& model);

	void Print();
	string printTV();

private:
	string brand;
	string model;
	string color;
	int hertz;
	double inch;

};



#endif /* TELEVISORS_H_ */
