/*
 * Time.cpp
 *
 *  Created on: 16.08.2014 ã.
 *      Author: Admin
 */
//============================================================================
// Name        : Lekcion12Ex4.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using std::cout;

#include <iomanip>
using std::setfill;
using std::setw;

#include "Time.h" // Time class definition
// constructor function to initialize private data;
// calls member function setTime to set variables;
// default values are 0 (see class definition)
Time::Time(int hr, int min, int sec) {
	this->second = 0;
	setTime(hr, min, sec);
} // end Time constructor

// set values of hour, minute, and second
Time &Time::setTime(int h, int m, int s) // note Time & return
		{
	this->second = 0;
	setHour(h);
	setMinute(m);
	setSecond(s);
	return *this; // enables cascading
} // end function setTime
//set hour value
Time &Time::setHour(int h) // note Time & return
		{
	int hour = (h >= 0 && h < 24) ? h : 0; // validate hour
	int reminder = this->second % 3600;
	this->second = hour * 3600 + reminder;
	return *this; // enables cascading
} // end function setHour

// set minute value
Time &Time::setMinute(int m) // note Time & return
		{
	int minute = (m >= 0 && m < 60) ? m : 0; // validate minute
	int reminder = this->second % 60;
	this->second  =  minute * 60 + reminder;
	return *this; // enables cascading
} // end function setMinute

// set second value
Time &Time::setSecond(int s) // note Time & return
		{
	this->second -= this->second % 60;
	this->second += (s >= 0 && s < 60) ? s : 0; // validate second
	return *this; // enables cascading
} // end function setSecond

// get hour value
int Time::getHour() const {
	return this->second/3600;
} // end function getHour
// get minute value
int Time::getMinute() const {
	return (this->second % 3600) / 60;
} // end function getMinute

// get second value
int Time::getSecond() const {
	return (this->second % 3600) % 60;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const {
	int hour = this->second / 3600;
	int minute = (this->second % 3600) / 60;
	int second = (this->second % 3600) % 60;
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":"
			<< setw(2) << second;
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const {
	int hour = this->second / 3600;
	int minute = (this->second % 3600) / 60;
	int second = (this->second % 3600) % 60;
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setfill('0')
			<< setw(2) << minute << ":" << setw(2) << second
			<< (hour < 12 ? " AM" : " PM");
} // end function printStandard

