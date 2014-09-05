/*
 * Tool.h
 *
 *  Created on: 29.08.2014 ã.
 *      Author: Koko
 */
#include<string>
using namespace std;
#ifndef TOOL_H_
#define TOOL_H_

class Tool {
public:
	Tool(int = 0, string = "", int = 0, double = 0.0);
	virtual ~Tool();
	int getToolCount() const;
	void setToolCount(int toolCount);
	const char* getToolName() const;
	int getToolNumber() const;
	void setToolNumber(int toolNumber);
	double getToolPrice() const;
	void setToolPrice(double toolPrice);
	void setToolName(string tNameString);
private:
	int toolNumber;
	char toolName[20];
	int toolCount;
	double toolPrice;
};

#endif /* TOOL_H_ */
