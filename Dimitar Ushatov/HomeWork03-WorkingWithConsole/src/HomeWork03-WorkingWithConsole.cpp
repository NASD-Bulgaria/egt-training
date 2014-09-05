//============================================================================
// Name        : HomeWork03-WorkingWithConsole.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

void ReadAndPrintSum() {
	int first = 0;
	int second = 0;
	int third = 0;
	cout << "Enter the first number:" << endl;
	cin >> first;
	cout << "Enter the second number:" << endl;
	cin >> second;
	cout << "Enter the third number:" << endl;
	cin >> third;
	int sum = first + second + third;

	cout << "The sum of the numbers " << first << ", " << second << " and "
			<< third << " is " << sum << endl;
}

void ReadRadiusPrintPAndArea() {
	double radius = 0;
	cout << "Enter radius: " << endl;
	cin >> radius;
	double perimeter = M_PI * radius * 2;
	double area = M_PI * radius * radius;

	cout << "The Perimeter of a circle with radius " << radius << " is "
			<< perimeter << " and his area is " << area << endl;
}

void GetAndPrintCompanyInfo(){
	string companyName = "";
	string companyAddress = "";
	string companyNumber = "";
	string companyFaxNumber = "";
	string companyWebSite = "";
	string managerFirstName = "";
	string managerLastName = "";

	cout << "Enter the company name: " << endl;
	cin >> companyName;
	cout << "Enter the company address: " << endl;
	cin >> companyAddress;
	cout << "Enter the company phone number: " << endl;
	cin >> companyNumber;
	cout << "Enter the company fax number: " << endl;
	cin >> companyFaxNumber;
	cout << "Enter the company web site: " << endl;
	cin >> companyWebSite;
	cout << "Enter the manager first name: " << endl;
	cin >> managerFirstName;
	cout << "Enter the manager last name: " << endl;
	cin >> managerLastName;

	cout << "COMPANY: " << companyName << endl;
	cout << "\t" << "Address: " << companyAddress << endl;
	cout << "\t" << "Phone Number: " << companyNumber << endl;
	cout << "\t" << "Fax Number: " << companyFaxNumber << endl;
	cout << "\t" << "Web Site: " << companyWebSite << endl;
	cout << "\t" << "Manager: " << managerFirstName << " " << managerLastName
			<< endl;
}

int main() {
	ReadAndPrintSum();
	ReadRadiusPrintPAndArea();
	GetAndPrintCompanyInfo();
	return 0;
}
