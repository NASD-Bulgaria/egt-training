/*
 * Invoice.h
 *
 *  Created on: Jul 22, 2014
 *      Author: NandM
 */

#ifndef INVOICE_H_
#define INVOICE_H_

using namespace std;

class Invoice{
public:
	Invoice(int partNumber, string partDescription, int itemsCount, double itemPrice){
		this->setPartNumber(partNumber);
		this->setPartDescrition(partDescription);
		this->setItemsCount(itemsCount);
		this->setItemPrice(itemPrice);
	}
	double getItemPrice() const {
		return itemPrice;
	}

	void setItemPrice(double itemPrice) {
		if (itemPrice < 0) {
			this->itemPrice = 0;
		} else {
			this->itemPrice = itemPrice;
		}
	}

	int getItemsCount() const {
		return itemsCount;
	}

	void setItemsCount(int itemsCount) {
		if (itemsCount < 0) {
			this->itemsCount = 0;
		} else {
			this->itemsCount = itemsCount;
		}
	}

	const string& getPartDescrition() const {
		return partDescrition;
	}

	void setPartDescrition(const string& partDescrition) {
		this->partDescrition = partDescrition;
	}

	int getPartNumber() const {
		return partNumber;
	}

	void setPartNumber(int partNumber) {
		this->partNumber = partNumber;
	}

	int getInvoiceAmount(){
		return (int)(this->getItemPrice() * this->getItemsCount());
	}

private:
	int partNumber;
	string partDescrition;
	int itemsCount;
	double itemPrice;
};



#endif /* INVOICE_H_ */
