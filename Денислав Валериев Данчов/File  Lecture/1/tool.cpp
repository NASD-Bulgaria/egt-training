#include <string>
#include <cstring>
#include "Tool.h"
using namespace std;

Tool::Tool(int partNumberValue, string toolNameValue, int inStockValue,
		double unitPriceValue)
{
	setPartNumber(partNumberValue);
	setToolName(toolNameValue);
	setInStock(inStockValue);
	setUnitPrice(unitPriceValue);
}

void Tool::setPartNumber(int partNumberValue)
{
	partNumber = partNumberValue;
}

int Tool::getPartNumber() const
{
	return partNumber;
}

void Tool::setToolName(string toolNameString)
{

	int length = toolNameString.size();
	length = (length < LENGTH ? length : LENGTH - 1);
	toolNameString.copy(toolName, length);

	toolName[length] = '\0';
}
string Tool::getToolName() const
{
	return toolName;
}

void Tool::setInStock(int inStockValue)
{
	inStock = inStockValue;
}

int Tool::getInStock() const
{
	return inStock;
}

void Tool::setUnitPrice(double unitPriceValue)
{
	unitPrice = unitPriceValue;
}

double Tool::getUnitPrice() const
{
	return unitPrice;
}
