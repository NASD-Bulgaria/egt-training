/*
 * Time.h
 *
 *  Created on: 16.08.2014 ã.
 *      Author: Admin
 */

#ifndef TIME_H_
#define TIME_H_

class Time {
public:
	Time(int = 0, int = 0, int = 0); // default constructor

// set functions (the Time & return types enable cascading)
	Time &setTime(int, int, int); // set hour, minute, second
	Time &setHour(int); // set hour
	Time &setMinute(int); // set minute
	Time &setSecond(int); // set second
// get functions (normally declared const)
	int getHour() const; // return hour
	int getMinute() const; // return minute
	int getSecond() const; // return second

// print functions (normally declared const)
	void printUniversal() const; // print universal time
	void printStandard() const; // print standard time
private:
	int second; // 0 - 59
};
// end class Time

#endif /* TIME_H_ */
