/*
 * Garage.h
 *
 *  Created on: Aug 5, 2014
 *      Author: NandM
 */

#ifndef GARAGE_H_
#define GARAGE_H_
#include "ParkedCar.h"
#include <vector>
#include <cmath>
using namespace std;

class Garage {
public:
	Garage(double minFee, double maxFee, double chargePerHour) {
		this->minFee = minFee;
		this->maxFee = maxFee;
		this->chargePerHour = chargePerHour;
	}
	Garage(double minFee, double maxFee, double chargePerHour,
			vector<ParkedCar> parcedCars) {
		this->minFee = minFee;
		this->maxFee = maxFee;
		this->chargePerHour = chargePerHour;
		this->parkedCars = parcedCars;
	}

	const vector<ParkedCar> getParkedCars() const {
		return parkedCars;
	}

	double getMinFee() const {
		return minFee;
	}

	void setMinFee(double minFee) {
		this->minFee = minFee;
	}

	double getMaxFee() const {
		return maxFee;
	}

	void setMaxFee(double maxFee) {
		this->maxFee = maxFee;
	}

	double getChargePerHour() const {
		return chargePerHour;
	}

	void setChargePerHour(double chargePerHour) {
		this->chargePerHour = chargePerHour;
	}

	void addCar(ParkedCar car) {
		this->parkedCars.push_back(car);
	}

	void addCar(vector<ParkedCar> cars) {
		for (int car = 0; car < cars.size(); ++car) {
			this->addCar(cars[car]);
		}
	}

	vector<double> calculateFees() {
		vector<double> fees;
		double fee;
		double time;
		for (int car = 0; car < this->parkedCars.size(); ++car) {
			time = parkedCars[car].getParkingTime();
			fee = this->minFee;
			while (time > 3) {
				fee += 0.5;
				time--;
			}

			if (fee > this->maxFee) {
				fee = this->maxFee;
			}

			fees.push_back(fee);
		}
		return fees;
	}

private:
	vector<ParkedCar> parkedCars;
	double minFee;
	double maxFee;
	double chargePerHour;
};

#endif /* GARAGE_H_ */
