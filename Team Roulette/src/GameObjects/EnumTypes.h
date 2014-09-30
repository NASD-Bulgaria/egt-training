/*
 * EnumTypes.h
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#ifndef ENUMTYPES_H_
#define ENUMTYPES_H_

namespace GameObjects{
enum Color {
	RedColor,
	BlackColor,
	NoneColor
};

enum Type {
	OddType,
	EvenType,
	NoneType
};

enum Half {
	LowHalf = 19,
	HighHalf,
	NoneHalf
};

enum RouletteWheelState{
	ExtremlySlowSpin = 1,
	VerySlowSpin = 2,
	SlowSpin = 3,
	NormalSpin = 4,
	FastSpin = 5,
	VeryFastSpin = 6,
	Stoped = 7
};
}

#endif /* ENUMTYPES_H_ */
