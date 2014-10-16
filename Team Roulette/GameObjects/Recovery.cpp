#include "Recovery.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

namespace GameObjects {

Recovery::Recovery() {
	init();
}

Recovery::~Recovery() {
}

int Recovery::getMoney() const {
	return money;
}

void Recovery::setMoney(int money) {
	this->money = money;
}

int Recovery::getTime() const {
	return t;
}

void Recovery::setTime(int time) {
	this->t = time;
}

void Recovery::save() {
	fstream save("save.dat", ios::out | ios::binary);
	save.write(reinterpret_cast<char *>(this), sizeof(Recovery));
	save.close();
}

bool Recovery::load() {
	fstream load("save.dat", ios::in | ios::out);
	if (load) {
		load.read(reinterpret_cast<char *>(this), sizeof(Recovery));
		load.close();
		return true;
	}
	return false;
}

void Recovery::init() {
	if (!this->load()) {
		this->setMoney(1000);
		this->setTime(time(0));
		this->save();
		this->load();
	}
}

}
