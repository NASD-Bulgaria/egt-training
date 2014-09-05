/*
 * Tool.cpp
 *
 *  Created on: 29.08.2014 ã.
 *      Author: Koko
 */

#include "Tool.h"

Tool::Tool(int toolNumVal, string toolNameVal, int toolCountVal, double toolPriceVal) {

	setToolCount(toolNumVal);
	setToolName(toolNameVal);
	setToolCount(toolCountVal);
	setToolPrice(toolPriceVal);
}

Tool::~Tool() {
	// TODO Auto-generated destructor stub
}

int Tool::getToolCount() const {
	return toolCount;
}

void Tool::setToolCount(int toolCount) {
	this->toolCount = toolCount;
}

const char* Tool::getToolName() const {
	return toolName;
}

void Tool::setToolName(string tNameString)
{
	const char *tNameValue =tNameString.data();
	int length = tNameString.length();
	length = (length < 20 ? length : 19);
	strncpy(toolName, tNameValue, length);
	toolName[length] = '\0';
}

int Tool::getToolNumber() const {
	return toolNumber;
}

void Tool::setToolNumber(int toolNumber) {
	this->toolNumber = toolNumber;
}

double Tool::getToolPrice() const {
	return toolPrice;
}

void Tool::setToolPrice(double toolPrice) {
	this->toolPrice = toolPrice;
}
