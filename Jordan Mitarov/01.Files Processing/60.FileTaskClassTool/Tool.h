/*
 * Tool.h
 *
 *  Created on: Aug 29, 2014
 *      Author: User
 */

#ifndef TOOL_H_
#define TOOL_H_

class Tool {
public:
	static const int length = 30;
	Tool(int = 1,string = "",int = 0, double = 0.0);
	void setRec(int);
	int getRec() const;
	void setTool(string);
	string getTool() const;
	void setQuant(int);
	int getQuant()const;
	void setPrice(double);
	double getPrice() const;
	//virtual ~Tool();
private:
	int record;
	char toolName[length];
	int quant;
	double priceTool;
};

#endif /* TOOL_H_ */
