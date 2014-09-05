#include <iostream>
#include <string>
using namespace std;

#include "Tool.h"


Tool::Tool(int rec, string name, int quantity, double priceProd)
{
	setRec(rec);
	setTool(name);
	setQuant(quantity);
	setPrice(priceProd);
}

void Tool::setRec(int rec)
{
	this -> record = rec;
}

int Tool::getRec() const
{
	return record;
}

void Tool::setTool(string name)
{
	//// copy at most 30 characters from string to toolName
	 int length = name.size();
	 length = ( length < length  ? length : length );
	 name.copy( toolName, length );

	 toolName[length] = '\0';
	 // append null-terminating
}

string Tool::getTool() const
{
	return toolName;
}

void Tool::setQuant(int quantity)
{
	this -> quant = quantity;
}

int Tool::getQuant() const
{
	return quant;
}

void Tool::setPrice(double priceProd)
{
	this -> priceTool = priceProd;
}

double Tool::getPrice() const
{
	return priceTool;
}
