//1. A parking garage charges a $2.00 minimum fee to park
//for up to three hours. The garage charges an additional
//$0.50 per hour for each hour or part thereof in excess of
//three hours. The maximum charge for any given 24-hour period
//is $10.00. Assume that no car parks for longer than 24 hours
//at a time. Write a program that calculates and prints the
//parking charges for each of three customers who parked their
//cars in this garage yesterday.

#include <iostream>
using namespace std;

double parkingFee(int hours)
{
	double price;

	if(hours == 24)
	{
		price = 10;
		return price;
	}
	if(hours <= 3)
	{
		price = 2;
		return price;
	}
	else
	{
		price  = 2 + (0.5 * (hours -3));
		return price;
	}
}

int main()
{
	int firstCostumer, secondCostumer, thirdCostumer;

	cout << "How many hours the first costumer was stay: ";
	cin >> firstCostumer;

	cout << "How many hours the second costumer was stay: ";
	cin >> secondCostumer;

	cout << "How many hours the the third costumer was stay: ";
	cin >> thirdCostumer;

	cout << endl;

	cout << "Costumer 1 must pay " << parkingFee(firstCostumer) << "$" << endl;
	cout << "Costumer 2 must pay " << parkingFee(secondCostumer) << "$" << endl;
	cout << "Costumer 3 must pay " << parkingFee(thirdCostumer) << "$" <<endl;

	return 0;
}
