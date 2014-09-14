/*
 * televisors.cpp
 *
 *  Created on: 14.09.2014 г.
 *      Author: Marty
 */

#include "televisors.h"



televisors::televisors(string tvBrand,string tvModel,string tvColor,int tvHertz,double tvInch)
{

	cout<<"Създаден е нов телевизор"<<endl<<endl;
   setBrand(tvBrand);
   setModel(tvModel);
   setColor(tvColor);
   setHertz(tvHertz);
   setInch(tvInch);

}

televisors::~televisors() {

}

const string& televisors::getBrand() const {
	return brand;
}

void televisors::setBrand(const string& brand) {
	this->brand = brand;
}

const string& televisors::getColor() const {
	return color;
}

void televisors::setColor(const string& color) {
	this->color = color;
}

int televisors::getHertz() const {
	return hertz;
}

void televisors::setHertz(int hertz) {
	this->hertz = hertz;
}

double televisors::getInch() const {
	return inch;
}

void televisors::setInch(double inch) {
	this->inch = inch;
}

const string& televisors::getModel() const {
	return model;
}

void televisors::setModel(const string& model) {
	this->model = model;
}
void televisors::Print()
{
	cout<<"brand : "<<getBrand();
	cout<<"model : "<<getModel();
	cout<<"color :"<<getColor();
	cout<<"hertz :"<<getHertz();
	cout<<"inch :"<<getInch();
	cout<<endl;
}
string televisors::printTV()
{
	string str;
	string hertz;
	string inch;
	stringstream ss;
	stringstream sa;

	ss<<getHertz();
	hertz=ss.str();

	sa<<getInch();
	inch=sa.str();

		str = getBrand() + "\t" + getModel() +"\t"+ getColor() +  "\t" + hertz + "\t"+ inch + "\n";

		return str;
}
