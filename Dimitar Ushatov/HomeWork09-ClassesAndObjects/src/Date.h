/*
 * Date.h
 *
 *  Created on: Jul 23, 2014
 *      Author: NandM
 */

#ifndef DATE_H_
#define DATE_H_

#include "Month.h"
using namespace std;

class Date{
public:
	Date(int day, Month month, int year){
		this->setMonth(month);
		this->setDay(day);
		this->setYear(year);
	}
	int getDay() const {
		return day;
	}

	void setDay(int day) {
		this->day = day;
	}

	int getYear() const {
		return year;
	}

	void setYear(int year) {
		this->year = year;
	}

	Month getMonth() const {
		return month;
	}

	void setMonth(Month month) {
		this->month = month;
	}

	void displayDate(){
		cout<<this->getDay() << "/" << month <<"/" << this->getYear()<<endl;
	}
private:
	int year;
	int day;
	Month month;
};



#endif /* DATE_H_ */
