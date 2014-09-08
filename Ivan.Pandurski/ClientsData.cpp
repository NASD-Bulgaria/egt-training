/*
 * ClientsData.cpp
 *
 *  Created on: 27.08.2014 ã.
 *      Author: PC
 */

#include "ClientsData.h"
#include<string>
using namespace std;

ClientsData::ClientsData(int accountNumberValue,
	 string lastNameValue, int toolNumberValue , double balanceValue)
{

	setNumber(accountNumberValue);
	setToolName(lastNameValue);
	setToolNumber(toolNumberValue);
	setToolPrice(balanceValue);



}


string ClientsData::getToolName()
{
 return toolName;
}

void ClientsData::setToolName( string lastNameString )
 {

 const char *lastNameValue = lastNameString.data();
 int length = lastNameString.size();
 length = ( length < 15 ? length : 14 );
 strncpy( toolName, lastNameValue, length );
 toolName[ length ] = '\0';
 }




