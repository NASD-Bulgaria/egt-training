#include "Tool.h"


Tool::Tool(int partNameValue, string toolNameValue, int inStockValue, double unitPriceValue)
{
	setPartNumber(partNameValue);
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
	return this->partNumber;
}

void Tool::setToolName(string toolNameString)
{
	int length = toolNameString.size();
	length = (length < LENGTH ? length : LENGTH - 1);
	toolNameString.copy(toolName, length);

	toolName[ length ] = '\0';
}

string Tool::getToolName() const
{
	return this->toolName;
}

void Tool::setInStock(int inStockValue)
{
	inStock = inStockValue;
}

int Tool::getInStock() const
{
	return this->inStock;
}

void Tool::setUnitPrice(double unitPriceValue)
{
	unitPrice = unitPriceValue;
}


double Tool::getUnitPrice() const
{
	return this->unitPrice;
}

Tool::~Tool() {
	// TODO Auto-generated destructor stub
}

