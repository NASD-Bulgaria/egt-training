/*
 * HardwareStore.cpp
 *
 *  Created on: 31.08.2014 г.
 *      Author: Ramzi
 */

#include <string.h>
#include "HardwareStore.h"

HardwareStore::HardwareStore(int number, string nameValue, int pieces,
		double priceValue)
{
	setIdNumber(number);
	setName(nameValue);
	setQuantity(pieces);
	setPrice(priceValue);
}

int HardwareStore::getIdNumber() const {
	return idNumber;
}

void HardwareStore::setIdNumber(int number) {
	idNumber = number;
}

string HardwareStore::getName() const {
	return name;
}

void HardwareStore::setName(string nameString) {
	const char *nameValue = nameString.data();
	int length = nameString.size();
	length = ( length < 30 ? length : 29 );
	strncpy( name, nameValue, length );
	name[ length ] = '\0';
}

double HardwareStore::getPrice() const {
	return price;
}

void HardwareStore::setPrice(double priceValue) {
	price = (priceValue > 0.0 ? priceValue : 0.0);
}

int HardwareStore::getQuantity() const {
	return quantity;
}

void HardwareStore::setQuantity(int pieces) {
	quantity = pieces;
}
