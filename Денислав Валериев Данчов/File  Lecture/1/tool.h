#ifndef TOOL_H
#define TOOL_H
#include<iostream>
#include <string>
using namespace std;

class Tool
{
public:
	static const int LENGTH = 30;

	Tool(int = -1, string = "", int = 0, double = 0.0);

	void setPartNumber(int);
	int getPartNumber() const;

	void setToolName(string);
	string getToolName() const;

	void setInStock(int);
	int getInStock() const;
	void setUnitPrice(double);
	double getUnitPrice() const;
private:
	int partNumber;
	char toolName[LENGTH];
	int inStock;
	double unitPrice;
};

#endif
