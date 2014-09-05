/*
 * ParkedCar.h
 *
 *  Created on: Aug 5, 2014
 *      Author: NandM
 */

#ifndef PARKEDCAR_H_
#define PARKEDCAR_H_
using namespace std;
class ParkedCar{
public:
	ParkedCar(double parkingTime){
		this->setParkingTime(parkingTime);
	}

	double getParkingTime() const {
		return parkingTime;
	}

	void setParkingTime(double parkingTime) {
		if (parkingTime <= 24) {
			this->parkingTime = parkingTime;
		} else {
			cout<<"The parking time is larger then the maximum allowed time"<<endl;
			this->parkingTime = 0;
		}
	}

private:
	double parkingTime;
};




#endif /* PARKEDCAR_H_ */
